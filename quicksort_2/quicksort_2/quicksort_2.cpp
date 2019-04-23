// An iterative implementation of quick sort 
#include <stdio.h> 
#include <iostream>
#include<vector>

using namespace std;

// A utility function to swap two elements 
template<class N>
void swap(N* a, N* b)
{
	N t = *a;
	*a = *b;
	*b = t;
}

/* This function is same in both iterative and recursive*/
template<class N>
int partition(vector<N> &arr, int l, int h)
{
	N x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

/* A[] --> Array to be sorted,
   l  --> Starting index,
   h  --> Ending index */

template<class N>
void quickSortIterative(vector<N>&arr, int l, int h)
{
	// Create an auxiliary stack 
	vector<N> stack(h - l + 1,0);

	// initialize top of stack 
	int top = -1;

	// push initial values of l and h to stack 
	stack[++top] = l;
	stack[++top] = h;

	// Keep popping from stack while is not empty 
	while (top >= 0)
	{
		// Pop h and l 
		h = stack[top--];
		l = stack[top--];

		// Set pivot element at its correct position 
		// in sorted array 
		int p = partition<N>(arr, l, h);

		// If there are elements on left side of pivot, 
		// then push left side to stack 
		if (p - 1 > l)
		{
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot, 
		// then push right side to stack 
		if (p + 1 < h)
		{
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}

// A utility function to print contents of arr
template<class N>
void printArr(vector<N>&arr, int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d ", arr[i]);
}

// Driver program to test above functions 
int main()
{
	vector<int> arr = { 4, 3, 5, 2, 1, 3, 2, 3 };
	int n = arr.size();
	quickSortIterative(arr, 0, n - 1);
	printArr(arr, n);
	return 0;
}
