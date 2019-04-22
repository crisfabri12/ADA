// radix_sort.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>

using namespace std;

template<class N >
N get_max(vector<N> &A)
{
	N max = A[0];
	for (int i = 1; i < A.size();i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}
	return max;
}

template <class N>
void countSort(vector<N> &A, int exp)
{ 

    vector<N> output; // output array 
	output = A;
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < A.size(); i++) 
        count[ (A[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = A.size() - 1; i >= 0; i--) 
    { 
        output[count[ (A[i]/exp)%10 ] - 1] = A[i]; 
        count[ (A[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < A.size(); i++) 
        A[i] = output[i]; 
} 
template<class N>
void radixsort(vector<N> &A)
{
	N m = get_max(A);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(A, exp);
}
template<class N>
void print(vector<N> A)
{
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
}
int main()
{
	vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
	radixsort<int>(arr);
	print<int>(arr);
	return 0;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
