#include <stdio.h>
#include <math.h> //I've included math.h for the pow function. On Piazza it says that I am allowed to use math.h so I used it

/*
Kyu Park
12198215
dec2bin.c
*/

int dec_to_bin(int n);
int hexadecimal_to_dec(char n[]);

int main()
{
	int n;
	char hexn[20]="";

	printf("Decimal Input :");
	scanf("%d", &n);
	printf("%d", dec_to_bin(n));

	printf("\nHexadecimal Input :");
	scanf("%s", &hexn);
	printf("%d", hexadecimal_to_dec(hexn));
}


int dec_to_bin(int n)
{
	int counter = 0;
	int binary = 0;


	do
	{
		//I first find whether the number in the digit is 0 or 1 by doing the modulus operation
		//And then put either 0 or 1 into the right place by multiplying by 10 counter powered
		binary += (n % 2) * pow((double)10, (double)counter);
		//n is then divided by 2 to move on to the next binary digit
		n = n / 2;
		//this is a counter that I use to place the number into the right digit, used for power of 10
		counter++;
	} while (n != 0); //the steps above repeats until there is no division, or n = 0, which indicates that the calculation is over

	return binary;
}

int hexadecimal_to_dec(char n[])
{
	
	int length = 0;

	//computes the actual length of the string
	do
	{
		length++;
	} while (n[length] != '\0');
	;

	int counter = length - 1; //counter I would use for pow function 
	int decimal = 0;

	//repeats for all digits of the hexadecimal input
	//starts from the very first element in array
	for (int i = 0; i < length; i++)
	{
		//if the digit is number from 0 to 9
		if (n[i] >= '0' && n[i] <= '9')
		{
			//the number is multiplied with 16 power counter and then added to the decimal
			decimal += (n[i] - 48) * pow(16, counter);
		}
		//if the digit is not number and alphabetical
		else
		{
			//I could use the if statement like above, but I found switch case more handy
			switch (n[i])
			{
			case 'A':
			case 'a':
				decimal += 10 * pow(16, counter);
				break;

			case 'B':
			case 'b':
				decimal += 11 * pow(16, counter);
				break;

			case 'C':
			case 'c':
				decimal += 12 * pow(16, counter);
				break;

			case 'D':
			case 'd':
				decimal += 13 * pow(16, counter);
				break;

			case 'E':
			case 'e':
				decimal += 14 * pow(16, counter);
				break;

			case 'F':
			case 'f':
				decimal += 15 * pow(16, counter);
				break;
			
			//I wanted to throw an error if the input is weird, but I don't know how to yet, so I just commented out
			//Also I can't return 0 to end the function because that will return 0 for the function, not the proggram
			/*default:
				printf("Error in input");
				break;
				*/
			}
		}
		//subtracts counter for the next following digit
		counter--;
	}
	return decimal;
}