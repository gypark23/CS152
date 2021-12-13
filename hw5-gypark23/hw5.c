#include <stdio.h>
#include <assert.h>
#include "q.h"
#include "bst.h"

/*
Kyu Park
12198215
hw5.c*/


void queueTest();
void BSTTest();
int main()
{
	queueTest();
	BSTTest();
}


void queueTest()
{
	//unit tests for create_queue, size, front last must be 0 and null
	struct Queue* q = create_queue();
	assert(q->size == 0);
	assert(q->front == NULL);
	assert(q->last == NULL);

	//enqueue 1, so front and last must be 1, sized 1
	//make sure 1 is the only element by checking if next is null
	enqueue(q, 1);
	assert(q->front->data == 1);
	assert(q->last->data == 1);
	assert(q->front->next == NULL);
	assert(q->size == 1);
	//another enqueue with 2, front must be 1, last must be 2 and they must be connected
	//size is 2
	enqueue(q, 2);
	assert(q->front->data == 1);
	assert(q->front->next->data == 2);
	assert(q->front->next->next == NULL);
	assert(q->size == 2);


	//testing dequeue. It must remove 1, shifting 2 to front
	//size is back to 1 after 1 is removed
	//make sure 2 is the only element by checking next
	dequeue(q);
	assert(q->front->data == 2);
	assert(q->last->data == 2);
	assert(q->front->next == NULL);
	assert(q->size == 1);


	//dequeue 2, so the queue must be empty
	//an edge case
	dequeue(q);
	assert(q->front == NULL);
	assert(q->last == NULL);
	assert(q->size == 0);


	//unit test for is_empty, is_empty must return true for q
	//since it is confirmed empty above
	assert(is_empty(q) == 1);
	//add an element to check if is_empty returns false
	//if is not empty
	enqueue(q, 0);
	assert(is_empty(q) == 0);


	//check peek and most_recent by adding two elements
	//peek must be 0 and most_recent must be 2
	//make sure they are all connected
	enqueue(q, 1);
	enqueue(q, 2);
	assert(peek(q)->data == 0);
	assert(most_recent(q)->data == 2);
	assert(peek(q)->next->data == 1);
	assert(most_recent(q)->next == NULL);


	//unit tests for drain()
	//make sure q is now empty by checking if is_empty
	//check if front and last are null
	drain(q);
	assert(is_empty(q) == 1);
	assert(peek(q) == NULL);
	assert(most_recent(q) == NULL);


	//unit tests for inc_nums()
	//checks if a que with 0 1 2 3 4 5 is properly formed
	//size must be 6, peek is 0 most_recent 5
	//they must be connected
	inc_nums(q, 5);
	assert(q->size == 6);
	assert(peek(q)->data == 0);
	assert(most_recent(q)->data == 5);
	assert(peek(q)->next->data == 1);
	assert(peek(q)->next->next->data == 2);


	//unit tests for reverse()
	//0 1 2 3 4 5 is now 5 4 3 2 1 0
	//size is still 6 and still connected
	reverse(q);
	assert(q->size == 6);
	assert(peek(q)->data == 5);
	assert(most_recent(q)->data == 0);
	assert(peek(q)->next->data == 4);
	assert(peek(q)->next->next->data == 3);


	//unit tests for remove_all_n()
	//create a queue with 0 1 2 2 3 and remove all 2
	//should have a queue with 0 1 3
	//check if q is a queue of 0 1 3
	inc_nums(q, 2);
	enqueue(q, 2);
	enqueue(q, 3);
	remove_all_n(q, 2);
	assert(q->size == 3);
	assert(peek(q)->data == 0);
	assert(peek(q)->next->data == 1);
	assert(peek(q)->next->next->data == 3);
	assert(most_recent(q)->data == 3);
}
void BSTTest()
{
	const int arr[5] = { 2, 1, 3, 4, 5 };
	BST* bst = NULL;

	//unit tests for add_node
	//check left and right and see if added nodes are connected correctly
	bst = add_node(bst, 1);
	assert(bst->data == 1);
	assert(bst->left == NULL);
	assert(bst->right == NULL);
	bst = add_node(bst, 2);
	bst = add_node(bst, 0);
	bst = add_node(bst, 3);
	assert(bst->data == 1);
	assert(bst->left->data == 0);
	assert(bst->right->data == 2);
	assert(bst->right->right->data == 3);


	//unit tests for create_bst
	//check if the values are in the right place and are connected
	bst = create_bst(arr, 5);
	assert(bst->data == 2);
	assert(bst->left->data == 1);
	assert(bst->right->data == 3);
	assert(bst->right->right->data == 4);
	assert(bst->right->right->right->data == 5);
	assert(bst->right->right->right->right == NULL);


	//unit tests for delete_node
	//case of deleting a node with one child
	bst = delete_node(bst, 3);
	assert(bst->data == 2);
	assert(bst->left->data == 1);
	assert(bst->right->data == 4);
	assert(bst->right->right->data == 5);
	assert(bst->right->right->right == NULL);
	//case of deleting a node with no child
	delete_node(bst, 5);
	assert(bst->data == 2);
	assert(bst->left->data == 1);
	assert(bst->right->data == 4);
	assert(bst->right->right == NULL);
	bst = create_bst(arr, 5);
	//case of deleting a node with two children
	delete_node(bst, 2);
	assert(bst->data == 3);
	assert(bst->left->data == 1);
	assert(bst->right->data == 4);


	//unit test for get_root()
	bst = create_bst(arr, 5);
	assert(get_root(bst) == 2);
	assert(bst->data == get_root(bst));


	//unit test for height()
	//check height() of null as well as edge case
	bst = NULL;
	assert(height(bst) == 0);
	bst = add_node(bst, 1);
	assert(height(bst) == 1);
	bst = add_node(bst, 2);
	assert(height(bst) == 2);
	bst = add_node(bst, 0);
	assert(height(bst) == 2);
	bst = add_node(bst, 3);
	assert(height(bst) == 3);


	//unit test for num_leaves
	bst = create_bst(arr, 5);
	assert(num_leaves(bst) == 2);
	delete_node(bst, 5);
	assert(num_leaves(bst) == 2);
	bst = NULL;
	assert(num_leaves(bst) == 0);
	bst = add_node(bst, 1);
	assert(num_leaves(bst) == 1);


	//unit tests for search
	//search any integers and still works
	bst = NULL;
	assert(search(bst, 1) == 0);
	bst = create_bst(arr, 5);
	assert(search(bst, 1) == 1);
	assert(search(bst, 0) == 0);
	assert(search(bst, -1) == 0);
	assert(search(bst, 5) == 1);
}