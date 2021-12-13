#include <stdio.h>
#include <stdlib.h>
/*
12198215
Kyu Park
Midterm 3_swivel.c
*/


void swivel(int** mat, int n);
void createandtest(int n);


int main()
{
	createandtest(3);
	createandtest(4);
	createandtest(5);
}

//inspired by https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
void swivel(int** mat, int n)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			temp = mat[i][j];
			mat[i][j] = mat[i][n - 1 - j];
			mat[i][n - 1 - j] = temp;
		}
	}
}

//creates nxn matrix and swivels it and prints the swiveled matrix
void createandtest(int n)
{
	int** matrixnxn = malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++)
	{
		matrixnxn[i] = (int*)malloc(n * sizeof(int*));
	}

	int num = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrixnxn[i][j] = num;
			num++;
		}
	}

	swivel(matrixnxn, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", matrixnxn[i][j]);
		}
		printf("\n");
	}
}