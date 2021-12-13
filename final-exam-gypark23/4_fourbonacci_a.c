#include <stdio.h> 
#include <assert.h>

/*
Kyu Park
12198215
4_fourbonacci_a.c*/

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

//scans and print out fourbonacci of user given n on terminal
int main()
{
	int num;
	printf("Please enter a value for n: ");
	scanf("%d", &num);
	printf("Four(%d) = %d", num, fourbonacci(num));

	return 0;
}