#include <stdio.h>

/*
Kyu Park
12198215
iterate_recurse.c
*/


int recursive_palindrome(char s[], int i, int f);
int iteration_palindrome(char s[]);

int main()
{
	//initial string contains all null with total size of 200
	char string[200] = "";
	//the real length of the string
	int length = 0;
	printf("Enter string: ");
	scanf("%s", &string);

	
	//computes the actual length of the string
	do
	{
		length++;
	} while (string[length] != '\0');

	//error if the length is over 100
	if (length > 100)
	{
		printf("\ninvalid size of input");
		return 0;
	}

	//error if the input is not alphabet
	for (int i = 0; i < length; i++)
	{
		if (!((string[i] >= 65 && string[i] <= 90)
			||(string[i] >= 97 && string[i] <= 122)))
		{
			printf("\ninvalid input");
			return 0;
		}
	}



	if (iteration_palindrome(string) == 0)
		printf("\nAccording to the palindrome iteration method,this is a palindrome");
	else
		printf("\nAccording to the palindrome iteration method, this is not a palindrome");

	if (recursive_palindrome(string, 0, 99) == 0)
		printf("\nAccording to the palindrome recursion method, this is a palindrome");
	else
		printf("\nAccording to the palinedrome recursion method, this is not a palindrome");

}

//recursively checks if the given string is palindrome
//with the i and f each representing the letters at the end
int recursive_palindrome(char s[], int i, int f)
{
	//if the string array has empty element,
	//then the function is called again with f reduced
	if (s[f] == '\0')
		return recursive_palindrome(s, i, f - 1);
	else
	{
		//if i exceeds f, the string is found palindrome
		if (i >= f)
			return 0;
		//if the letters at i and f are identical (not case-sensitive)
		//then the function proceeds with
		//i added and f reduced until i exceeds f
		else if ((s[i] == s[f]) || ((s[i] - s[f] == 32) || (s[i] - s[f] == -32)))
			return recursive_palindrome(s, ++i, --f);
		//if the letters at i and f are not identical
		//then returns 1 and found not palindrome
		else
			return 1;
	}
}


int iteration_palindrome(char s[])
{
	int length = 0;

	//figures out the length
	do
	{
		length++;
	} while (s[length] != '\0');

	//final index number
	int final = length - 1;;

	//for loop to check the palindrome
	for (int i = 0; i <= final; i++)
	{
		//if the letters are not identical
		if (s[i] != s[final])
			//first check if the letters are identical
			//but just written in different cases
			if (((s[i] - s[final] != 32) && (s[i] - s[final] != -32)))
				//if not identical, then found not palindrome
				return 1;
		//final index reduced
		final--;
	}
	//if every letters are paired, then found palindrome
	return 0;
}
