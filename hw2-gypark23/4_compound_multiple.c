#include <stdio.h>

/*
Kyu Park
12198215
compound_multiple.c
*/




// prints out from 1 to 100
// adds fire if is multiple of 3, man if is multiple of 5, firemand if is multiple of 3 and 5
int main()
{
	for (int i = 1; i < 101; i++)
	{
		if (i % 3 == 0)
		{
			if (i % 5 == 0)
				printf("%d fireman\n", i);
			else
				printf("%d fire\n", i);
		}
		else if (i % 5 == 0)
			printf("%d man\n", i);
		else
			printf("%d\n", i);
	}

	return 0;
}