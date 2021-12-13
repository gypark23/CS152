#include <stdio.h>

/*
Kyu Park
12198215
spiral.c
*/

void print_nxn(int n);
void print_spiral(int mat[200][200], int row, int col, int m);

int main()
{
	int n;
	int matrix[200][200]; //maximum size of 200x200 matrix, will be used for spiral form
	int num = 1;

	printf("Number n?\n");
	scanf("%d", &n);
	printf("\n");
	print_nxn(n);


	//filling in the matrix
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = num;
			num++;
		}
	}


	printf("\n");
	print_spiral(matrix, 0, 0, n);

}


//prints nxn matrix, no n limitation
void print_nxn(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i * n + 1; j < (i + 1) * n + 1; j++)
		{
			printf("%d ", j);
		}
		printf("\n");
	}
}


//prints spiral form of nxn matrix, maximum size of 200x200
void print_spiral(int mat[200][200], int row, int col, int m)
{
	//only goes recursion if row & col is less than n
	if (row < m && col < m)
	{
		//prints first row
		for (int i = col; i < m; i++)
		{
			printf("%d ", mat[row][i]);
		}

		//prints last col 
		for (int i = row + 1; i < m; i++)
			printf("%d ", mat[i][m - 1]);

		//if first row and last row aren't same
		if (row != (m - 1))
		{
			//print last row
			for (int i = m - 2; i >= col; i--)
			{
				printf("%d ", mat[m - 1][i]);
			}
		}

		//if first col and last col aren't same
		if (col != (m - 1))
		{
			//print first col  
			for (int i = m - 2; i > row; i--)
			{
				printf("%d ", mat[i][col]);
			}
		}
		//recursion with the smaller "inner (n-1)x(n-1) square"
		print_spiral(mat, ++row, ++col, --m);
	}
	//base case
	else
		return;
}

