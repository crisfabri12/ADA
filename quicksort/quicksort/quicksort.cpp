/* C implementation QuickSort */
#include<stdio.h>
#include <iostream>
#include <vector>

using namespace std;


// A utility function to swap two elements 
template<class N>
void swap(N* a, N* b)
{
	N t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
template<class N>
int partition(vector<N> &arr, int low, int high)
{
	N pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
template<class N>
void quickSort(vector<N>& arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition<N>(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort<N>(arr, low, pi - 1);
		quickSort<N>(arr, pi + 1, high);
	}
}

/* Function to print an array */
template<class N>
void printArray(vector<N> arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

// Driver program to test above functions 
int main()
{
	vector<int> arr = { 10, 7, 8, 9, 1, 5 };
	int n = arr.size();
	quickSort<int>(arr, 0, n - 1);
	printf("Sorted array: ");
	printArray<int>(arr, n);
	return 0;
}