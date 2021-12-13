#include <stdio.h>
/*
Kyu Park
12198215
number_tower.c
*/

void for_loop();
void do_while_loop();

int main()
{
	for_loop();
	printf("\n");
	do_while_loop();
}



// returns a number tower
void for_loop()
{
	for (int i = 1; i < 7; i++)
	{
		for (int j = i; j > 0; j--)
		{
			printf("%d", j);
		}
		printf("\n");
	}
}

// returns a number tower
void do_while_loop()
{
	int i = 1;
	do
	{
		int j = i;
		do
		{
			printf("%d", j);
			j--;
		} while (j >= 1);
		printf("\n");
		i++;
	} while (i <= 6);
}
