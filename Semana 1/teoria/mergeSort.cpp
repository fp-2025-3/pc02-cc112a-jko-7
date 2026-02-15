#include <iostream>
using namespace std;

void merge (int arr[], int inicio, int medio, int fin){

    // Tamaños de los subarreglos
    int n1 = medio-inicio+1;
    int n2 = fin-medio;

    // Arreglos auxiliares
    int L[100], R[100];

    // Copiamos datos del subarreglo izquierdo
    for (int i=0; i<n1; i++){
        L[i]=arr[inicio+i];
    }

    // Copiamos datos del subarreglo derecho
    for (int j=0; j<n2; j++){
        R[j]=arr[medio+1+j];
    }

    int i=0, j=0, k=inicio;

    while (i<n1 && j<n2){
        if (L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Colocando los elementos restantes de L
    while (i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }

    // Colocando los elementos restantes de R
    while (j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort (int A[], int inicio, int fin){

    if (inicio<fin){

        int medio=(inicio+fin)/2;

        // ordeno la primera mitad
        mergeSort (A, inicio, medio);

        // ordeno la segunda mitad
        mergeSort (A, medio+1, fin);

        merge (A, inicio, medio, fin);

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

    mergeSort(arr,0, n-1);

    cout << "\nArreglo ordenado" << endl;
    imprimir(arr,n);

    return 0;
}



