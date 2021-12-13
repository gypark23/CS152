#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include <string.h>	//for strcmp for unit tests

/*
Kyu Park
12198215
6_string_sort.c*/

//sort the given string
//removes space and returns a sorted string (sorted in the capital, lower case, number order)
//prints out error and calls main if nonalphanumerical characters are detected
char* stringSort(char* string)
{
	int capitalChar[26] = { 0 };
	int lowerChar[26] = { 0 };
	int numbers[10] = { 0 };
	int index = 0;
	int length = 0;			//length of the sorted string to be used in string memory allocation
	//repeats until the null terminator is reached
	while (string[index] != '\0')
	{
		//case for capital letters
		if (string[index] >= 'A' && string[index] <= 'Z')
		{
			//capital letters are stored in the array
			//index represents the alphabets, elements represents the occurences
			capitalChar[string[index] - 'A']++;
			length++;
		}
		//case for lower case letters
		else if (string[index] >= 'a' && string[index] <= 'z')
		{
			//lower case letters are stored in the array
			//index represents the alphabets, elements represents the occurences
			lowerChar[string[index] - 'a']++;
			length++;
		}
		//case for numerical letters
		else if (string[index] >= '0' && string[index] <= '9')
		{
			//numbers are stored in the array
			//index represents the numbers, elements represents the occurences
			numbers[string[index] - '0']++;
			length++;
		}
		//nonalphanumerical characters
		//except spaces and line feed (enter)
		else if (string[index] != ' ' && string[index] != 10)
		{
			printf("**Invalid input - please only input alphanumeric characters and spaces **\n");
			main();
		}
		//increment index for next character
		index++;
	}

	//creates an empty string with calloc
	char* sortedString = calloc(length, sizeof(char));
	//reset the index
	index = 0;

	//fills in the string in order from capital letters, lower case letters and numbers array
	//which are also sorted alphabetically and numerically
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < capitalChar[i]; j++)
		{
			sortedString[index] = i + 'A';
			index++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < lowerChar[i]; j++)
		{
			sortedString[index] = i + 'a';
			index++;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < numbers[i]; j++)
		{
			sortedString[index] = i + '0';
			index++;
		}
	}

	//return the string
	return sortedString;
}

//takes up to 50 characters as input
int main()
{
	assert(strcmp(stringSort("My Phone Number is 555 333 1234"), "MNPbeehimnorsuy1233334555") == 0);
	assert(strcmp(stringSort("Hello World"), "HWdellloor") == 0);

	//infinite loop until user terminates with ctrl+c
	while (1)
	{
		char input[50] = "";
		printf("Please enter a string: \n");
		fgets(input, 50, stdin);
		printf("%s\n", stringSort(input));
	}
}