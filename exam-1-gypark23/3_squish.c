#include <stdio.h>
#include <stdlib.h>
/*
12198215
Kyu Park
Midterm 3_squish.c
*/



//returns ‘squished’ string based on the relative counts of repetitive characters
//all letters in ascii accepted including punctuation marks
//lower case & upper case letters considered different letters
//maximum string length 100
//repetitive characters
int main()
{
	char string[100] = "";
	char* previousChar = string;	//pointer of previous character
	int index = 0;	//index of string
	int count = 0;	//count letters

	printf("Enter your string: ");
	scanf("%s", string);


	do
	{
		//if string is empty (last character reached), terminates program and print out results for previous character
		if (string[index] == '\0')
		{
			printf("%c%d", *previousChar, count);
			return 0;
		}
		//first letter is an exception since there is no previous character to compare
		if (index == 0)
		{
			count++;
			index++;
		}
		//if is not first letter,
		else
		{
			//if the character equals previous character, moves on with counter added
			if (string[index] == *previousChar)
			{
				count++;
				previousChar++;
				index++;
			}
			//if a new character appears, prints out the previous char and counter, and reset previous char and counter and moves on
			else
			{
				printf("%c%d", *previousChar, count);
				index++;
				previousChar++;
				count = 1;
			}
		}
	} while (1);	//theoretically an infinite loop but should terminate when char is null
}