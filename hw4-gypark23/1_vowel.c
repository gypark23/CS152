#include <stdio.h>
#include <string.h>


/*
1_vowel.c
12198215
Kyu Park
*/

typedef struct _Letter
{
	char letter;
	int count;
}Letter;


//count and update letters from a given string
static void countLetter(char* string, Letter* letter)
{
	for (int i = 0; i < strlen(string); i++)
	{
		//considers an uppercase as well
		if (string[i] == letter->letter || string[i] == letter->letter - 32)
			letter->count++;
	}
}


