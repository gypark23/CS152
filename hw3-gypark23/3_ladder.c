#include <stdio.h>

/*
Kyu Park
12198215
ladder.c
*/


int possible_ways(int n);


int main()
{
	int n;
	printf("Input: ");
	scanf("%d", &n);

	printf("\nNumber of possible ways: %d", possible_ways(n));
}


int possible_ways(int n)
{
	//base cases below
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	// if n > 3 f(n) = f(n-1) + f(n-2) + f(n-3)
	else
		return possible_ways(n - 1) + possible_ways(n - 2) + possible_ways(n - 3);
}