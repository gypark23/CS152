#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

/*
12198215
Kyu Park
Midterm 9_tests.c
*/

int is_foxish(char* string, int f, int o, int x);
int is_anyish(char* string1, char* string2);
char* stringtoLower(char* string);

int main()
{
	assert(is_foxish("Fox", 0, 0, 0) == 1);
	assert(is_foxish("deToXiFication", 0, 0, 0) == 1);
	assert(is_foxish("this isn't F0xish at all", 0, 0, 0) == 0);
	assert(is_anyish("aBc", "Apple banana Cat") == 1);
	assert(is_anyish("FoX", "deToxification") == 1);
	assert(is_anyish("Xylophone", "zebra") == 0);
	assert(is_anyish("ABC", "apple banana") == 0);
}


//int f, o, x each represents the counts of each letters. When executed first, they must all be assigned 0, 0, 0
int is_foxish(char* string, int f, int o, int x)
{
	//if each letters are found, then returns true
	if (f > 0 && o > 0 && x > 0)
		return 1;
	//if all characters of the string were inspected and the condition above was not met, found not foxish and returned false
	if (strlen(string) == 0)
		return 0;
	//switch case for the first character of the string
	switch (*string)
	{
	case 'f':
	case 'F':
		f++;
		break;
	case 'o':
	case 'O':
		o++;
		break;
	case 'x':
	case 'X':
		x++;
		break;
	}
	//new string with the first character removed
	char* nextLetter = string;
	nextLetter++;
	return is_foxish(nextLetter, f, o, x);
}



int is_anyish(char* string1, char* string2)
{
	//if the first string is empty and have never been returned 0, is found true and returned true.
	if (strlen(string1) == 0)
		return 1;
	//if the first letter of string1 is not found in string2, returned false
	//all characters are converted to lowercase by stringtoLower, and a lowercase letter is searched
	if (strchr(stringtoLower(string2), tolower(*string1)) == NULL)
		return 0;
	//if found
	else
	{
		//recursive run with the first character removed until string1 is empty and returned true
		char* nextLetter = string1;
		nextLetter++;
		return is_anyish(nextLetter, string2);
	}
}

//converts a string to all lowercase
char* stringtoLower(char* string)	//code from https://stackoverflow.com/questions/2661766/how-do-i-lowercase-a-string-in-c
{
	for (char* p = string; *p; p++)
		*p = tolower(*p);
	return string;
}