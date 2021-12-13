#include <stdio.h>
#include <stdlib.h>

/*
12198215
Kyu Park
Midterm 10_linked_lists.c
*/


//inspired by https://www.geeksforgeeks.org/void-pointer-c-cpp/
//void pointer could point to any types of variables, so I used a void pointer for data
//as long as each variables are defined beforehand and the address is passed to data
//void pointer could store any types of variables
typedef struct node
{
	void* data;
	struct node* next;
}Node;


int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	Node* fourth = NULL;

	//memory allocated to each nodes
	head = (Node*)malloc(sizeof(Node));
	second = (Node*)malloc(sizeof(Node));
	third = (Node*)malloc(sizeof(Node));
	fourth = (Node*)malloc(sizeof(Node));

	//demonstration of each types
	int integer = 1;
	char character = 'a';
	float flooat = 1.0;
	double doouble = 1.0;

	//assigning each types of variables to each nodes
	//since data is stored in void pointer, the address of each variables are passed
	head->data = &integer;
	head->next = second;
	second->data = &character;
	second->next = third;
	third->data = &flooat;
	third->next = fourth;
	fourth->data = &doouble;
	fourth->data = NULL;
}