#include"Search.h"
#include "Sort.h"
#include<chrono>

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i]<<" ";
}

const int SIZE = 1000000;
int* a = new int[SIZE];


int main()
{

	//Test 
	/*int* a = new int[1];
	a[0] = 1;
	cout << InterpolationSearch(a,1,1);
	*/

	//Test
	for (int i = 0; i < SIZE; i++)
		a[i] = rand() % SIZE;
	

	//Selection sort
	auto t1 = chrono::high_resolution_clock::now();
	SelectionSort(a, SIZE);
	auto t2 = chrono::high_resolution_clock::now();
	cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count()<<" ms\n";
	//PrintArray(a, 100);

	
	//Improve Selection sort
	auto t3 = chrono::high_resolution_clock::now();
	ProSelectionSort(a, SIZE);
	auto t4 = chrono::high_resolution_clock::now();
	cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(t4 - t3).count() << " ms\n";
	//PrintArray(a, 100);

	
	//Bubble sort
	auto t5 = chrono::high_resolution_clock::now();
	BubbleSort(a, SIZE);
	auto t6 = chrono::high_resolution_clock::now();
	cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(t6 - t5).count() << " ms\n";
	//PrintArray(a, 100);


	//Improve bubble sort
	auto t7 = chrono::high_resolution_clock::now();
	ProBubbleSort(a, SIZE);
	auto t8 = chrono::high_resolution_clock::now();
	cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(t8 - t7).count() << " ms\n";
	//PrintArray(a, 100);


	//Insertion sort
	auto t9 = chrono::high_resolution_clock::now();
	InsertionSort(a, SIZE);
	auto t10 = chrono::high_resolution_clock::now();
	cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(t10 - t9).count() << " ms\n";
	//PrintArray(a, 100);


	//Binary insertion sort
	auto t11 = chrono::high_resolution_clock::now();
	InsertionSort(a, SIZE);
	auto t12 = chrono::high_resolution_clock::now();
	cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(t12 - t11).count() << " ms\n";
	//PrintArray(a, 100);

	
	delete[] a;
	return 0;
}