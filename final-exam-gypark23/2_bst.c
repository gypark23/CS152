#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

/*
Kyu Park
12198215
2_bst.c*/


const int ABSOLUTEMIN = -2147483648;
const int ABSOLUTEMAX = 2147483647;

//inspired by https://riptutorial.com/ko/algorithm/example/29474/%EC%A3%BC%EC%96%B4%EC%A7%84-%EC%9D%B4%EC%A7%84-%ED%8A%B8%EB%A6%AC%EA%B0%80-bst%EC%9D%B8%EC%A7%80-%ED%99%95%EC%9D%B8%ED%95%98%EB%8A%94-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
//takes bst, min and max as parameters
//min and max is the range of the bst integer values
//min and max could be any integer values as long as min <= min of bst elements and max >= max of bst elements
//returns 1 if the given bst is a proper bst, 0 if not, -1 if the input is invalid
int is_valid_bst(BST* bst, int min, int max)
{
	//example of invalid input where min is greater than max
	if (min > max)
	{
		return -1;
	}
	//empty bst returns true
	//this is for the base case for the recursion runs
	if (bst == NULL)
	{
		return 1;
	}
	//if data is less than the given min or greater than the given max
	//this indicates that the bst rule of lesser values are placed in left and greater values in right
	//is violated, since min and max are from the predecessor value
	//check if the given bst->left is greater or equal than the predecessor
	//and if bst->right is less or equal than the predecessor
	//if so, it is not a valid bst, so returns false since it breaks the rule above
	if (bst->data < min || bst->data > max)
	{
		return 0;
	}
	//check if the two daughters are valid as well, and when reached at the end NULL
	//returns true if reached to the end since the base case returns true
	return (is_valid_bst(bst->left, min, bst->data - 1) && is_valid_bst(bst->right, bst->data + 1, max));
}

//prints the minimum and maximum value of the VALID bst
//if there is only one element, min and max are that very element
//O(log n) for a balanced tree since it does operations each level and does it log(n) times, which is the height of BST
//O(n) at the worst case for nonbalanced tree
void printMinMax(BST* bst)
{
	//edge case where bst is empty
	if (bst == NULL)
	{
		printf("BST is NULL");
		return;
	}

	//current max is set to the bst value in case the root's right is empty
	int	max = bst->data;
	BST* temp = bst;
	//searches the rightmost element, which is the greatest value
	while (temp->right != NULL)
	{
		temp = temp->right;
		max = temp->data;
	}

	//current min is set to the bst value in case the root's left is empty
	int min = bst->data;
	temp = bst;
	//searches the leftmost element, which is the smallest value
	while (temp->left != NULL)
	{
		temp = temp->left;
		min = temp->data;
	}

	//prints the result
	printf("Min: %d Max: %d\n", min, max);
	//free the temp pointer
	free(temp);
}

//creates a mirror BST that has greater values in left and lesser values in right
//O(n)
BST* reverseBST(BST* bst)
{
	//if bst is null, return null
	//for the base case of the recursion runs
	if (bst == NULL)
	{
		return NULL;
	}
	else
	{
		//creates a temporary node and copy the value
		BST* temp = add_node(NULL, bst->data);
		//flip the daughter nodes and place left in right, right in left
		//recursively flips all the nodes below
		temp->left = reverseBST(bst->right);
		temp->right = reverseBST(bst->left);

		//return the newly made flipped tree
		return temp;
	}
}

int main()
{
	//array from 0 to 9
	int arr[] = { 5, 3, 4, 6, 9, 7, 1, 2, 8, 0 };
	BST* bst = NULL;

	//create a bst with only one node of 1
	bst = add_node(NULL, 1);
	//should print min 1 max 1
	printMinMax(bst);

	//unit tests for is_valid_bst
	bst = create_bst(arr, 10);
	assert(is_valid_bst(bst, ABSOLUTEMIN, ABSOLUTEMAX) == 1);
	//should print min 0 and max 9
	printMinMax(bst);
	//ruin the bst by inserting -1 to the root
	//and see if is_valid_bst is false now
	bst->data = -1;
	assert(is_valid_bst(bst, ABSOLUTEMIN, ABSOLUTEMAX) == 0);
	assert(is_valid_bst(NULL, ABSOLUTEMIN, ABSOLUTEMAX) == 1);
	assert(is_valid_bst(bst, ABSOLUTEMAX, ABSOLUTEMIN) == -1);

	//unit tests for reverseBST
	//reset the bst
	//check if the daughters are also reversed
	bst = reverseBST(create_bst(arr, 10));
	assert(get_root(bst) == 5);
	assert(get_root(bst->right) == 3);
	assert(get_root(bst->left) == 6);
	assert(get_root(bst->right->right) == 1);
	assert(get_root(bst->right->left) == 4);


	return 0;
}