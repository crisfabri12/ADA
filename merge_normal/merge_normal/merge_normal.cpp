#include<stdlib.h> 
#include<stdio.h>
#include<iostream>
#include<vector>;

using namespace std;

template <class N>
void merge(vector<N> &arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<N> L; 
	vector<N> R;

	for (i = 0; i < n1; i++)
		L.push_back(arr[l + i]);
	for (j = 0; j < n2; j++)
		R.push_back(arr[m + 1 + j]);

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
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
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

template<class N>
void mergeSort(vector<N> &arr, int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort<N>(arr, l, m);
		mergeSort<N>(arr, m + 1, r);

		merge<N>(arr, l, m, r);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
template<class N>
void printArray(vector<N>&A, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* Driver program to test above functions */
int main()
{
	vector<int> arr = { 12, 11, 13, 5, 6, 7 };
	int arr_size = arr.size();

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}