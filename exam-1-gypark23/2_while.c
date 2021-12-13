#include <stdio.h>
/*
12198215
Kyu Park
Midterm 2_while.c
*/


void hollowBox(int n, int m);
void hollowBox2(int n, int m);


int main()
{
	int n, m;
	printf("n and m?\n");
	scanf("%d %d", &n, &m);

	printf("\n\nii) \n");
	hollowBox(1, 1);
	printf("\n");
	hollowBox(2, 2);
	printf("\n");
	hollowBox(6, 3);
	printf("\n");
	hollowBox(5, 4);
	printf("\n");
	hollowBox(n, m);

	printf("\n\niii) \n");
	hollowBox2(1, 1);
	printf("\n");
	hollowBox2(2, 2);
	printf("\n");
	hollowBox2(6, 3);
	printf("\n");
	hollowBox2(5, 4);
	printf("\n");
	hollowBox2(n, m);


	return 0;
}

//int n and m must be positive integer
//prints out nxm hollow box by while loop
void hollowBox(int n, int m)
{

	int row = 1;
	while (row <= n)
	{
		int col = 1;
		while (col <= m)
		{
			if (row == 1 || row == n)
			{
				printf("L");
				col++;
			}
			else
			{
				if (col == 1 || col == m)
				{
					printf("L");
					col++;
				}
				else
				{
					printf(" ");
					col++;
				}
			}
		}
		printf("\n");
		row++;
	}
}


//int n and m must be positive integer
//prints out nxm hollow box by do-while loop
void hollowBox2(int n, int m)
{
	int row = 1;
	do
	{
		int col = 1;
		do
		{
			if (row == 1 || row == n)
			{
				printf("L");
				col++;
			}
			else
			{
				if (col == 1 || col == m)
				{
					printf("L");
					col++;
				}
				else
				{
					printf(" ");
					col++;
				}
			}

		} while (col <= m);
		printf("\n");
		row++;
	} while (row <= n);
}