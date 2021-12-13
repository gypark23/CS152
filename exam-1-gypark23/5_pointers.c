#include <stdio.h>
#include <assert.h>

/*
12198215
Kyu Park
Midterm 5_pointers.c
*/

double min(double* arr, int n);
double max(double* arr, int n);
double sum(double* arr, int n);


int main()
{
	double arr[] = { 0, -0.1, 0.1, 0.2, 0.3, 0.4, 0.5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(min(arr, n) == -0.1);
	assert(max(arr, n) == 0.5);
	assert(sum(arr, n) == 1.4);

	double arr2[] = { 0 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(min(arr2, n2) == 0);
	assert(max(arr2, n2) == 0);
	assert(sum(arr2, n2) == 0);

	double arr3[] = { 1, 1, 1, 1, 1 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(min(arr3, n3) == 1);
	assert(max(arr3, n3) == 1);
	assert(sum(arr3, n3) == 5);
}


//takes in double array and its number of elements n
//returns minimum element of the array
double min(double* arr, int n)
{
	double minimum = *arr;

	for (int i = 0; i < n; i++)
	{
		if (minimum > * arr)
			minimum = *arr;
		arr++;
	}

	return minimum;
}
//takes in double array and its number of elements n
//returns maximum element of the array
double max(double* arr, int n)
{
	double maximum = *arr;

	for (int i = 0; i < n; i++)
	{
		if (maximum < *arr)
			maximum = *arr;
		arr++;
	}

	return maximum;
}
//takes in double array and its number of elements n
//returns sum of all elements of the array
double sum(double* arr, int n)
{
	double summation = 0;

	for (int i = 0; i < n; i++)
	{
		summation += *arr;
		arr++;
	}

	return summation;
}