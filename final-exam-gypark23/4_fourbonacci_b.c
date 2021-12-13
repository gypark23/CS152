#include <stdio.h> 
#include <assert.h>

/*
Kyu Park
12198215
4_fourbonacci_b.c*/

//returns a fourbonacci of a nonnegative integer
int fourbonacci(int n)
{
	if (n < 0)
		return 0;
	else if (n < 4)
		return 1;
	else
		return fourbonacci(n - 1) + fourbonacci(n - 2) + fourbonacci(n - 3) + fourbonacci(n - 4);
}

//scans and print out fourbonacci of numbers up to n in 4_fourbonacci.txt
int main()
{
	int num;
	printf("Please enter a value for n: ");
	scanf("%d", &num);

	FILE* ofp = fopen("4_fourbonacci.txt", "w");
	for (int i = num; i > -1; i--)
	{
		fprintf(ofp, "Four(%d) = %d\n", i, fourbonacci(i));
	}

	fclose(ofp);

	printf("Your Four-bonacci numbers have been saved to 4_fourbonacci.c");

	return 0;
}