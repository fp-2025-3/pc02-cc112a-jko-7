#include <iostream>
using namespace std;

// Función auxiliar para intercambiar valores
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// --- BUBBLE SORT OPTIMIZADO ---
void bubbleSort(int arr[], int n) {
    int comparaciones = 0, intercambios = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambios++;
                swapped = true;
            }
        }
        if (!swapped) break; // Si no hubo intercambios, ya está ordenado
    }
    cout << "Bubble Sort -> Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
}

// --- SELECTION SORT ---
void selectionSort(int arr[], int n) {
    int comparaciones = 0, intercambios = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparaciones++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            intercambios++;
        }
    }
    cout << "Selection Sort -> Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
}

// --- INSERTION SORT ---
void insertionSort(int arr[], int n) {
    int comparaciones = 0, intercambios = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // El primer chequeo de (j >= 0) no suele contarse como comparación de datos, 
        // pero (arr[j] > key) sí.
        while (j >= 0) {
            comparaciones++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                intercambios++; // Se cuenta el desplazamiento como un "swap" parcial
                j--;
            } else {
                break; 
            }
        }
        arr[j + 1] = key;
    }
    cout << "Insertion Sort -> Comparaciones: " << comparaciones << ", Desplazamientos: " << intercambios << endl;
}

int main() {
    int original[] = {3, 1, 2, 1};
    int n = 4;

    // Nota: Para probar cada uno con los mismos datos, 
    // deberías resetear el arreglo antes de cada llamada.
    
    return 0;
}

/*
1. ¿Cuál se comporta mejor con arreglos casi ordenados? El Insertion Sort. Si el arreglo 
está casi ordenado, el bucle interno de Insertion Sort termina casi de inmediato en cada 
paso, logrando un rendimiento cercano a $O(n)$. Bubble Sort optimizado también detecta esto, 
pero Insertion suele realizar menos trabajo administrativo.

2. ¿Cuál realiza más swaps? Generalmente, Bubble Sort. Este algoritmo intercambia elementos 
adyacentes constantemente. En cambio, Selection Sort solo realiza como máximo $n-1$ 
intercambios en total, ya que solo hace un swap después de encontrar el mínimo de toda la 
lista restante.

3. ¿Cuál realiza más comparaciones? Selection Sort. A diferencia de los otros 
dos, Selection Sort no tiene un mecanismo de "salida temprana". Siempre buscará el elemento 
más pequeño en el resto del arreglo, sin importar si el arreglo ya estaba ordenado, 
realizando siempre aproximadamente n^2/2 comparaciones.
*/