#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
Kyu Park
12198215
5_pq.c*/

int size = 0;
typedef struct _Node
{
	int data;
	int priority;
}Node;

//now swaps a node
void swap(Node* a, Node* b)
{
	Node temp = *a;
	*a = *b;
	*b = temp;
}

//heapify and rearrange the priority queue by comparing priority of the nodes
//adopted from max_heap.c and modified to accomodate Node type
void heapify(Node* node, int size, int i)
{
	if (size == 1)
	{
		printf("Single element in the heap");
	}
	else
	{
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l < size && node[l].priority > node[largest].priority)
			largest = l;
		if (r < size && node[r].priority > node[largest].priority)
			largest = r;
		if (largest != i)
		{
			swap(&node[i], &node[largest]);
			heapify(node, size, largest);
		}
	}
}

//adopted from insert function of max_heap.c
//type changed to Node* from void, returns a pointer of modified priority queue
//At the worst case, the swap is performed on every level.
//Therefore it will repeat for the height of the heap tree, which is log(n)
//O(log n)
Node* insert(Node* node, int newNum, int prio)
{
	//creating a node with the given value
	Node* temp = malloc(sizeof(Node));
	temp->data = newNum;
	temp->priority = prio;
	//case for creating a new heap
	if (size == 0 || node == NULL)
	{
		size++;
		return temp;
	}
	//adding an element to an existing priority queue
	else
	{
		//resizing the existing heap for an additional room for the new node
		Node* new = realloc(node, sizeof(Node) * (size + 1));
		//assign the new temp node to the end of the heap
		new[size] = *temp;
		size++;
		//heapify and rearrange the heap
		for (int i = size / 2 - 1; i >= 0; i--)
		{
			heapify(new, size, i);
		}
		//return the modified heap
		return new;
	}
}

// return (without popping) the front element of the priority queue
// O(1) since it takes a constant time complexity to access the first element of the array/pointer.
// It always will be O(1) since all it does is just reach to the first element.
int peek(Node* node)
{
	return node[0].data;
}

// return the value (and removes the node) at the front of the priority queue
// returns -1 if an empty node is turned in
// Also O(log n), since it deletes the node for each level of the heap tree,
// and it will repeat for the height of the heap tree, which is (log n)
// therefore O(log n)
int pop(Node* node)
{
	if (size == 0 || node == NULL)
		return -1;


	const int value = peek(node);

	swap(&node[0], &node[size - 1]);
	//this frees the deleted node by shrinking the pointer size by one
	node = realloc(node, sizeof(Node) * size);
	size--;
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(node, size, i);
	}

	return value;
}


int main()
{
	Node* temp = NULL;
	//unit tests for insert
	//check if first insert creates a priority queue with only one elemenet
	temp = insert(temp, 12, 1);
	assert(size == 1);
	assert(temp[0].data == 12);
	assert(temp[0].priority == 1);
	//insert three other elements and check if priority queue is heapified
	temp = insert(temp, 11, 2);
	temp = insert(temp, 10, 3);
	temp = insert(temp, 9, 4);
	assert(size == 4);
	assert(temp[0].data == 9);
	assert(temp[3].data == 12);
	//insert more elements
	temp = insert(temp, 8, 5);
	temp = insert(temp, 7, 6);
	temp = insert(temp, 6, 7);
	temp = insert(temp, 5, 8);
	temp = insert(temp, 4, 9);
	temp = insert(temp, 3, 10);
	temp = insert(temp, 2, 11);
	temp = insert(temp, 100000000, 12);
	assert(temp[0].data == 100000000);
	assert(temp[1].data == 3);
	assert(temp[2].data == 2);
	//unit tests for peek
	assert(peek(temp) == temp[0].data);
	//unit tests for pop
	//check if pop returns the right integer value
	//and if the max priority element is deleted
	assert(pop(temp) == 100000000);
	assert(size == 11);
	assert(peek(temp) == 2);
	assert(pop(temp) == 2);
	assert(size == 10);

	return 0;
}


