#include <stdio.h>
/*
Kyu Park
12198215
cipher.c
*/


// prints out modified strings after shifts each letter to user's given number in the alphabet
// the number given should be "reasonable"--that is, the number should be at most inbetween -24 or 24
int main()
{

	int index = 0;
	int shift;
	char string[50];


	printf("String?\n");
	scanf("%s", &string);

	printf("Shift?\n");
	scanf("%d", &shift);

	// first do-while loop firstchecks whether any of the character is a symbol
	// and immediately terminates the program with an error if it contains a symbol
	do
	{
		if (((int)string[index] >= 48 && (int)string[index] <= 57) || ((int)string[index] >= 65 && (int)string[index] <= 90) || ((int)string[index] >= 97 && (int)string[index] <= 122))
			index++;
		else
		{
			printf("\nerror: the symbol cannot contain symbols");
			return 0;
		}
	} while (string[index] != '\0');

	// resets the index number back to 0
	index = 0;

	// second do-while loop prints out each characters after the shifts
	do
	{
		if ((int)string[index] >= 65 && (int)string[index] <= 122)
		{
			printf("%c", string[index] + shift);
			index++;
		}
		if ((int)string[index] >= 48 && (int)string[index] <= 57)
		{
			printf("%c", string[index]);
			index++;
		}
	} while (string[index] != '\0');

	return 0;

}