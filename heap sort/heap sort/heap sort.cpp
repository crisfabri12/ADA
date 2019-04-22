// heap sort.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>

using namespace std;

/* A utility function to print array of size n */
template<class N>
void printArray(vector<N>& A)
{
	for (int i = 0; i < A.size(); ++i)
		cout << A[i] << " ";
	cout << "\n";
}



template<class N>
void heapify(vector<N>& A,int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 
	cout << n << " ";
	// If left child is larger than root 
	if (l < n && A[l] > A[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && A[r] > A[largest])
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		swap(A[i], A[largest]);
		//cout << A[i] << endl;
		//cout << A[largest] << endl;

		// Recursively heapify the affected sub-tree 
		heapify(A,n, largest);
	}
}

// main function to do heap sort
template<class N>
void heapSort(vector<N> &A)
{
	int n = A.size();
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(A,n, i);
		//cout << i << endl;
	}
	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end 
		swap(A[0], A[i]);

		// call max heapify on the reduced heap 
		heapify(A, i, 0);
	}
}


// Driver program 
int main()
{
	vector<int> arr = { 12, 11, 13, 5, 6, 7 };

	heapSort<int>(arr);

	cout << "Sorted array is \n";
	printArray<int>(arr);
}