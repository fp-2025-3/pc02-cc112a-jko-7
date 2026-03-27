#include <iostream>
using namespace std;

// --- BÚSQUEDA LINEAL ---
// Recorre el arreglo uno por uno. Funciona en arreglos desordenados.
int busquedaLineal(const int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Retorna el índice donde lo encontró
        }
    }
    return -1; // No se encontró
}

// --- BÚSQUEDA BINARIA ---
// Divide el rango de búsqueda a la mitad en cada paso.
int busquedaBinaria(const int arr[], int n, int x) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2; // Evita desbordamiento de memoria

        if (arr[medio] == x) {
            return medio; // Encontrado
        }
        
        if (arr[medio] < x) {
            inicio = medio + 1; // Buscar en la mitad derecha
        } else {
            fin = medio - 1;    // Buscar en la mitad izquierda
        }
    }
    return -1; // No se encontró
}

int main() {
    int arr[] = {1, 3, 5, 7};
    int n = 4;

    cout << "--- Pruebas de Busqueda ---" << endl;
    cout << "Lineal (x=1): " << busquedaLineal(arr, n, 1) << endl;   // Esperado: 0
    cout << "Binaria (x=7): " << busquedaBinaria(arr, n, 7) << endl; // Esperado: 3
    cout << "Binaria (x=4): " << busquedaBinaria(arr, n, 4) << endl; // Esperado: -1

    return 0;
}

/*

1. ¿Qué precondición obligatoria tiene la búsqueda binaria?El arreglo debe estar 
ordenado (normalmente de forma ascendente). Si el arreglo no está ordenado, la lógica 
de descartar mitades no funciona y el algoritmo fallará en encontrar elementos que sí 
están presentes.

2. ¿Qué valor se retorna si no se encuentra el elemento? Se retorna -1. 
Se elige este valor porque los índices de un arreglo en C++ comienzan en 0; un número 
negativo indica claramente que la posición es inexistente.

3. ¿Cuál es el rango válido de índices? El rango válido es de 0 a n-1, donde n es el 
número total de elementos.


*/