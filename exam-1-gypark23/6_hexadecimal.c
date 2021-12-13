#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*
12198215
Kyu Park
Midterm 6_hexadecimal.c
*/


char* dec2hexadecimal(int n);


int main()
{
	char* _2020;
	char* _13;
	char* _4199999;

	_2020 = dec2hexadecimal(2020);
	_13 = dec2hexadecimal(13);
	_4199999 = dec2hexadecimal(4199999);

	assert((strcmp(_2020, "7E4")) == 0);
	assert((strcmp(_13, "D")) == 0);
	assert((strcmp(_4199999, "40163F")) == 0);
}


char* dec2hexadecimal(int n)
{
	char* arr = malloc(8 * sizeof(char));	//2^32 to hex is FFFFFFFF, so the maximum size is 8
	int index = 0;
	int size = 0;	//the number of digits
	do
	{
		//if the remainder of n is less than 10, that remainder is stored in the array 
		if (n % 16 < 10)
		{
			arr[index] = n % 16 + '0';	//char to int converted, and stored into the array
			n /= 16;	//n is divided by 16
			index++;	//the index of the array incremented
			size++;		//size is also incremented for later use
		}
		//if the remainder of n is greater than 10, alphabet A to E must be used
		else
		{
			arr[index] = n % 16 + 55;	//10 becomes A, 11 becomes B and so on, and it is stored into the array
			n /= 16;	//n is divided by 16
			index++;	//the index of the array incremented
			size++;		//size is also incremented for later use
		}
	} while (n != 0);	//repeats until n = 0

	//array inverting process below
	//real char pointer (not flipped) appropriately sized (based on the number of digits) is created
	char* hex = calloc(size, sizeof(char));

	//elements are copied, but are inverted
	for (int i = 0; i < size; i++)
	{
		hex[i] = arr[size - i - 1];
	}

	//real hexadecimal representation of n is then returned
	return hex;
}

