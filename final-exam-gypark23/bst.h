#include <stdio.h> 
#include <stdlib.h>

/*
Kyu Park
12198215
bst.h*/


typedef struct BTree
{
	int data;
	struct BTree* left;
	struct BTree* right;
} BST;

//returns the integer data of root of the given bst
int get_root(BST* bst)
{
	return bst->data;
}

//returns the number of nodes on the longest path from root to leaf
int height(BST* bst)
{

	//base case
	if (bst == NULL)
		return 0;
	else
	{
		//count left and right heights and return whatever is the highest
		int left = height(bst->left);
		int right = height(bst->right);

		if (left > right)
			return ++left;
		else return ++right;
	}
}

//given a bst, return the number of leaves
int num_leaves(BST* bst)
{
	int count = 0;
	//no leaf if bst is empty
	if (bst == NULL)
	{
		return 0;
	}
	//if both left and right is empty, count that as one leaf
	if (bst->left == NULL && bst->right == NULL)
	{
		count = 1;
	}
	//if not, check their children if they are leaves by recursion
	else
	{
		if (bst->left != NULL)
		{
			count += num_leaves(bst->left);
		}
		if (bst->right != NULL)
		{
			count += num_leaves(bst->right);
		}
	}
	return count;
}

//given a bst and an integer n, return whether a node is in the the tree. 
//returns 0 if not found
//returns 1 if found
int search(BST* bst, int key)
{
	if (bst == NULL)
	{
		return 0;
	}
	else if (bst->data == key)
	{
		return 1;
	}
	else if (bst->data > key)
	{
		return search(bst->left, key);
	}
	else
	{
		return search(bst->right, key);
	}
}

//given a bst, add an additional node.
//returns a new bst that has the node added to the appropriate place
BST* add_node(BST* bst, int n)
{
	//if bst is null, create a brand new bst with the integer n
	if (bst == NULL)
	{
		bst = malloc(sizeof(BST));
		bst->data = n;
		bst->left = NULL;
		bst->right = NULL;
	}
	//if it isn't empty
	//check where n will belong by comparing the root value
	//calls recursion to traverse through and put n into the right place
	else if (n < bst->data)
	{
		bst->left = add_node(bst->left, n);
	}
	else
	{
		bst->right = add_node(bst->right, n);
	}

	//returns the bst that has n added
	return bst;
}



//inspired by https://www.techiedelight.com/deletion-from-bst/ (but didn't copy)
//given a bst, delete the node containing the integer n. 
//returns the bst with the node deleted
BST* delete_node(BST* bst, int n)
{
	//recursive calls
	//if n doesn't exist, terminate the function immediately
	if (search(bst, n) == 0)
		return bst;
	//base case for recursion
	if (bst == NULL)
		return bst;
	//traverse through to find where the node is at
	if (n < bst->data)
	{
		bst->left = delete_node(bst->left, n);
	}
	if (n > bst->data)
	{
		bst->right = delete_node(bst->right, n);
	}


	//the actual process of deletion below
	if (n == bst->data)
	{
		// case for node with no child
		if (bst->left == NULL && bst->right == NULL)
		{
			//remove that bst and return null for the recursion
			free(bst);
			return NULL;
		}
		//case for node with one child
		else if (bst->left == NULL || bst->right == NULL)
		{
			//check whether left or right has the child
			//and whatever child is there yields the value to the node
			//and the child node is freed or deleted
			BST* temp;
			if (bst->left == NULL)
				temp = bst->right;
			else
				temp = bst->left;
			free(bst);
			return temp;
		}
		else
		{
			//case for node with two children
			//finds the minimum at the right node to replace the node
			BST* minimum = bst->right;
			//go to the leftmost from the right side of the first node
			while (minimum->left != NULL)
			{
				minimum = minimum->left;
			}
			//the node becomes the right side's minimum value
			bst->data = minimum->data;
			//and deletes that very node
			bst->right = delete_node(bst->right, minimum->data);
		}
	}
	return bst;
}

//given a list of nonnegative integers, generate a BST. They should be added from lower index to higher
//includes length which must be less or equal to the length of arr[]
//if length is less than the actual length of arr[], only takes integers up to that length
//returns a bst generated in preorder traversal
BST* create_bst(int arr[], int length)
{
	//first create an empty bst and fills it with values of the array
	BST* bst = NULL;
	for (int i = 0; i < length; i++)
	{
		bst = add_node(bst, arr[i]);
	}
	//then returns it
	return bst;
}
