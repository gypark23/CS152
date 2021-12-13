#include <stdio.h>

int main()
{
	for (int i = 1; i < 101; i++)
	{
		if ((i % 3) == 0)
			if ((i % 5) == 0)
				printf("FizzBuzz \n");
			else
				printf("Fizz \n");
		else printf("%d\n", i);
	}

	return 0;
}