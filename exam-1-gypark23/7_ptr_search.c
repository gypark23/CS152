#include <stdio.h>


/*
12198215
Kyu Park
Midterm 7_ptr_search.c
*/

int increment(int* arr, int n);

int main()
{
	return 0;
}



//basically arr[n] but used pointer increment n times
int increment(int* arr, int n)
{
	int num;

	for (int i = 0; i < n; i++)
	{
		arr++;
	}
	num = *arr;

	return num;
}

//l is leftmost array index number, r is rightmost array index number, x is target integer
int binarySearch(int* arr, int l, int r, int x)
{
	if (r >= l)
	{
		//middle index num
		int mid = l + (r - l) / 2;

		//if num in middle index of the array equals target, returns that index number
		if (increment(arr, mid) == x)
			return mid;

		//if target is less than mid, run binary search below mid
		if (increment(arr, mid) > x)
			return binarySearch(arr, l, mid - 1, x);

		//target is greater than mid, run binary search over mid
		return binarySearch(arr, mid + 1, r, x);
	}
	//target not found
	return -1;
}