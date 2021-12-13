#include <stdio.h>
/*
Kyu Park
12198215
add_for_all.c
*/

int subtraction(int a, int b);
int multiplication(int a, int b);
float division(int a, int b);

int main()
{
	int a;
	int b;

	printf("Please enter the first number a\n");
	scanf("%d", &a);

	printf("Please enter the second number b\n");
	scanf("%d", &b);

	// error statement if b = 0 to prevent division by zero
	if (b == 0)
	{
		printf("error, b cannot be 0");
		return 0;
	}


	printf("Results for a=%d and b=%d", a, b);
	printf("\nSum: %d, Difference: %d, Multiplication: %d, Division %.2f", a + b, subtraction(a, b), multiplication(a, b), division(a, b));

	return 0;
}


// returns a - b
int subtraction(int a, int b)
{
	return a + -b;
}

// returns a * b
int multiplication(int a, int b)
{
	int sum = 0;

	if (b < 0)
	{
		if (a < 0)
		{
			return multiplication(-a, -b);
		}
		else
		{
			return multiplication(b, a);
		}
	}
	else
	{
		for (int i = 0; i < b; i++)
		{
			sum += a;
		}
	}
	return sum;
}

// returns a / b while b != 0
// this division function finds the quotient by adding 0.001 until the quotient times b equals a
float division(int a, int b)
{
	
	
	if (a < 0)
	{
		if (b < 0)
		{
			return division(-a, -b);
		}
		else
		{
			return -division(-a, b);
		}
	}
	else
	{
		if (b < 0)
		{
			return -division(a, -b);
		}
		else
		{
			// initial quotient starts from zero 
			float quotient = 0.00;
			do
			{
				// sum of floats computes the expected quotient times b
				float sum_of_floats = 0.00;
				
				// this for loop adds expected quotient b times, which is quotient times b
				for (int i = 0; i < b; i++)
				{
					sum_of_floats += quotient;
				}

				// if quotient times b is equal to or greater than a, the loop stops imediately and returns the quotient
				if (sum_of_floats >= a)
					break;
				
				// quotient increments by 0.001 for accuracy to the hundredths decimal places
				quotient += 0.001;
			} while (1); // this is an infinite loop until the correct quotient is found
			
			return quotient;
		}
	}
}