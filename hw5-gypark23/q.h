#include <stdio.h> 
#include <stdlib.h> 

/*
Kyu Park
12198215
q.h*/


/* Queue implementation: borrowed from Igor Carpanese on Quora:
 * https://www.quora.com/How-do-you-make-a-simple-queue-program-in-C/answer/Igor-Carpanese
 * */

struct Node
{
	int data;
	struct Node* next;
};

struct Queue
{
	struct Node* front;
	struct Node* last;
	unsigned int size;
};

//add a node with the given data to the given queue
//puts it on the end of the queue
void enqueue(struct Queue* q, int data)
{
	q->size++;

	if (q->front == NULL)
	{
		q->front = (struct Node*)malloc(sizeof(struct Node));
		q->front->data = data;
		q->front->next = NULL;
		q->last = q->front;
	}
	else
	{
		q->last->next = (struct Node*)malloc(sizeof(struct Node));
		q->last->next->data = data;
		q->last->next->next = NULL;
		q->last = q->last->next;
	}
}

//removes the first element of the queue and pulls the other elements
void dequeue(struct Queue* q)
{
	q->size--;

	struct Node* tmp = q->front;
	q->front = q->front->next;
	free(tmp);

	if (q->size == 0)
	{
		q->last = NULL;
		free(q->last);
	}
}

//checks if the given queue is empty
//returns 1 if true, 0 if false
int is_empty(struct Queue* q)
{
	return (q->size == 0);
}

//creates a queue with nothing stored and returns it
//size 0, front and last are null
struct Queue* create_queue()
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = NULL;
	q->last = NULL;
	q->size = 0;

	return q;
}

//returns the peek (first) element of the queue
struct Node* peek(struct Queue* q)
{
	return (q->front);
}

//returns the most recently added (last) element of the queue
struct Node* most_recent(struct Queue* q)
{
	return (q->last);
}

//resets the given queue
//removes all the elements and becomes an empty queue
void drain(struct Queue* q)
{
	free(q);
	q = create_queue();
}

//drains the existing queue 
//constructs a queue from 0 to n
//0 is the first and n is the last
void inc_nums(struct Queue* q, unsigned int n)
{
	drain(q);
	for (int i = 0; i <= n; i++)
	{
		enqueue(q, i);
	}
}

//remove all occurences of the integer n
//from the given queue
void remove_all_n(struct Queue* q, unsigned int n)
{
	const int SIZE = q->size;

	for (int i = 0; i < SIZE; i++)
	{
		if (peek(q)->data != n)
		{
			enqueue(q, peek(q)->data);
		}
		dequeue(q);
	}
}

//inspired by https://stackoverflow.com/questions/47039477/c-reverse-queue
//revert the queue
void reverse(struct Queue* q)
{
	if (!is_empty(q))
	{
		int num = peek(q)->data;
		dequeue(q);
		reverse(q);
		enqueue(q, num);
	}
}