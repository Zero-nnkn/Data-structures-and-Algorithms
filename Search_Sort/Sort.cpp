#include "Sort.h"
#include "Search.h"


//Selection sort
void SelectionSort(int* a, int n) {
	int i, j, i_min, temp;
	for (i = 0; i < n - 1; i++) {
		i_min = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[i_min]) i_min = j;
		}
		swap(a[i], a[i_min]);
	}
}

//Improve selection sort
void ProSelectionSort(int* a, int n) {
	int i, j, i_min, j_max;
	for (i = 0, j = n - 1; i < j; i++, j--) {
		i_min = i, j_max = j;
		for (int k = i + 1; k < j; k++) {
			if (a[k] < a[i_min]) i_min = k;
			if (a[k] > a[j_max])j_max = k;
		}
		swap(a[i], a[i_min]);
	}
}

//Bubble sort
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])swap(a[j], a[j - 1]);
}
//Improve bubble sort
void ProBubbleSort(int* a, int n)
{
	int save_1 = 0, save_2 = 0;
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		for (int k = j - 1; k > i; k--) {
			if (a[k] < a[k - 1]) {
				swap(a[k], a[k - 1]);
				save_1 = k - 1;
			}
		}
		i = save_1;
		for (int k = i + 1; k < j; k++)
		{
			if (a[k] > a[k + 1]) {
				swap(a[k], a[k + 1]);
				save_2 = k + 1;
			}
		}
		j = save_2;
	}
}


//Insertion sort
void InsertionSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int temp = a[i+1];
		int j = i;
		while (j >= 0 && a[j] > temp)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}

//Binary Search: log(n)
int Binary(int* a, int n, int value)
{
	int left = 0, right = n - 1;
	int mid = left + (right - left) / 2;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (value == a[mid])return mid+1;
		else {
			if (value < a[mid])
				right = mid-1;
			else
				left = mid + 1;
		}
	}
	return value > a[left] ? left+1 : left;
}
//Binary Insertion Sort
void BIS(int* a, int n)
{
	int last;
	for (int i = 0; i < n-1; i++)
	{
		last = a[i + 1];
		int insert = Binary(a, i+1, last);
		for (int j = i ; j >= insert; j--)
			a[j+1] = a[j];
		a[insert] = last;
	}
}