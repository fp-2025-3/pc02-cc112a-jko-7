#include <iostream>
using namespace std;

int particion(int A[], int inicio, int fin) {

    int pivot = A[fin];  // El pivote es el último elemento
    int i = inicio - 1;  // Índice del elemento más pequeño
    
    // Recorrer el arreglo y reorganizar
    for (int j = inicio; j < fin; j++) {
        if (A[j] <= pivot) {
            i++;
            // Intercambiar A[i] y A[j]
            swap (A[i], A[j]);
        }
    }
    
    // Colocar el pivote en su posición correcta
    swap (A[i+1], A[fin]);
    
    return i + 1;  // Retornar la posición del pivote
}

void quickSort (int A[], int inicio, int fin){

    if (inicio<fin){

        int indPiv = particion (A, inicio, fin);

        quickSort (A, inicio, indPiv-1);
        quickSort (A, indPiv+1, fin);
        
    }
}

void imprimir(int arr[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main (){

    int arr[] = {2,3,5,4,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "\nArreglo original: " << endl;
    imprimir(arr,n);

    quickSort(arr,0, n-1);

    cout << "\nArreglo ordenado" << endl;
    imprimir(arr,n);

    return 0;

}
