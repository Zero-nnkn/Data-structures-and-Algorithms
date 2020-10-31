#include "Search.h"

//Binary Search: log(n)
bool BinarySearch(int* a, int n, int value)
{
	int left = 0, right = n-1;
	int mid = left + (right-left)/2;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (value == a[mid])return true;
		else {
			if (value < a[mid]) 
				right = mid-1;
			else
				left = mid+1;
		}
	}
	return false;
}

//Interpolation Search: log (log n) + 1
bool InterpolationSearch(int* a, int n, int value)
{
	int left = 0, right = n - 1;
	int x;
	while (left <= right) {
		if (left == right)return a[left] == value;

		x = (value - a[left]) * (right - left) / (a[right] - a[left]) + left;
		if (a[x] == value)return true;
		else {
			if (a[x] < value)left = x + 1;
			else right = x - 1;
		}
	}
	return false;
}
