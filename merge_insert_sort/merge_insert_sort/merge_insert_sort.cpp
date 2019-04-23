#include<stdlib.h> 
#include<stdio.h> 
#include <iostream>
#include <vector> 
using namespace std;
static int k = 5;

template <class N>
void insertionSort(vector<N> &arr, int n)
{
	int i, j;
	N key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		  greater than key, to one position ahead
		  of their current position */
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

template <class N>
void merge(vector<N>& arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	vector<N>L;

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L.push_back(arr[l + i]);

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		cout << m + j << endl;

		if (L[i] <= arr[m + 1 + j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = arr[m + 1 + j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */

template<class N>
void mergeSort(vector<N>& arr, int l, int r)
{
	if (r-l > k)
	{
		int m = l + (r - l) / 2;

		mergeSort<N>(arr, l, m);
		mergeSort<N>(arr, m + 1, r);
		merge<N>(arr, l, m, r);
	}
	else {
		insertionSort(arr, arr.size());
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */

template<class N>
void printArray(vector<N> & A, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* Driver program to test above functions */
int main()
{
	vector<int>arr = { 12, 11, 13, 5, 6, 7 };
	int arr_size = arr.size();

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}