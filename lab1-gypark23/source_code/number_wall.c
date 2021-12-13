#include <stdio.h>

int main()
{
	int width;
	int max_val;

	printf("width?\n");
	scanf("%d", &width);
	printf("max val?\n");
	scanf("%d", &max_val);


	for (int i = 1; i < max_val+1; i++)
	{
		if ((i % width) == 0)
			printf("%d \n", i);
		else
			printf("%d ", i);

	}

	for (int i = max_val; i < (width * (max_val/width + 1)); i++)
	{
		printf("x ");
	}

	return 0;
}