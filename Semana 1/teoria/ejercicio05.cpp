#include <iostream>

using namespace std;

// --- FUNCIONES AUXILIARES PARA MERGESORT ---
void merge(int arr[], int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    // Arreglos temporales
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++) R[j] = arr[medio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;
        mergeSort(arr, inicio, medio);
        mergeSort(arr, medio + 1, fin);
        merge(arr, inicio, medio, fin);
    }
}

// --- FUNCIONES AUXILIARES PARA QUICKSORT ---
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivote al final
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*
¿Por qué MergeSort siempre es O(n log n)? Porque su estructura de división es fija: 
siempre divide el arreglo exactamente a la mitad (log $n$ niveles de recursión) y el 
proceso de mezcla (merge) siempre toma un tiempo lineal ($n$) para combinar los 
elementos.

¿En qué caso QuickSort degrada a O(n²)? Ocurre cuando la elección del pivote es pésima, 
por ejemplo, elegir siempre el elemento más grande o más pequeño en un arreglo que ya 
está ordenado o inversamente ordenado. Esto genera particiones totalmente desbalanceadas.

¿Qué estrategia de pivote es más segura? La técnica de pivote aleatorio o la de mediana 
de tres (primer, medio y último elemento). Esto minimiza drásticamente la probabilidad 
de caer en el caso de peor desempeño.

¿Cómo se puede mejorar el uso de memoria? QuickSort ya es eficiente al ser in-place. Para
MergeSort, la memoria se puede mejorar usando una implementación iterativa para ahorrar 
espacio en la pila o utilizando algoritmos de mezcla in-place, aunque estos últimos son 
mucho más complejos de implementar.

*/