#include<stdio.h>

int main()
{
	int input;

	printf("Enter your integer\n");
	scanf("%d", &input);
	printf("Output: %d", input % 2);

	return 0;
}