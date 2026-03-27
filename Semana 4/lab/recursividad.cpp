#include <iostream>
#include <climits>
using namespace std;

int costoMinimo (int arr[], int n, int pos){

    // Caso base
    // Si se llega al final del arreglo no hay mas costo que sumar
    if (pos==n){
        return 0; // 
    }

    // Caso recursivo
    int min = INT_MAX;
    int producto = 1;

    // Todas las posibles divisiones del 'pos' hasta el final
    for (int i=pos; i<n; i++){
        producto*=arr[i]; // [pos ... i]

        // Llamada recursiva
        int resultadoRestante = costoMinimo (arr, n, i+1);

        if (resultadoRestante != INT_MAX){
            int costoActual = producto+resultadoRestante;
            if (costoActual < min){
                min = costoActual;
            }
        }
    }

    return min;
}

// Graficando el arbol de llamadas recursivas
// para [1,2,3]
// [1] [2] [3] --->  6
// [1] [2 3] ---> 7
// [1 2] [3] ---> 5
// [1 2 3] ---> 6

int main (){

    int A[] = {1,2,3};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"El costo minimo es : "<<costoMinimo(A, n, 0)<<endl;

    return 0;
}