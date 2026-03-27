#include <iostream>
using namespace std;

// --- VERSIÓN ITERATIVA ---
bool estaOrdenadoIterativo(const int arr[], int n) {
    if (n <= 1) return true;

    for (int i = 0; i < n - 1; i++) {
        // Si el elemento de la izquierda es mayor al de la derecha, no está ordenado
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// --- VERSIÓN RECURSIVA ---
bool estaOrdenadoRecursivo(const int arr[], int n) {
    // Caso base: un arreglo vacío o de un solo elemento está ordenado
    if (n <= 1) return true;

    // Comparamos los últimos dos elementos
    if (arr[n - 1] < arr[n - 2]) {
        return false;
    }

    // Llamada recursiva con un tamaño menor
    return estaOrdenadoRecursivo(arr, n - 1);
}

int main() {
    // Definición de casos de prueba usando arreglos constantes
    int p1[] = {0}; // Representa el caso vacío (n=0 se pasa manualmente)
    int p2[] = {5};
    int p3[] = {1, 2, 3, 4};
    int p4[] = {1, 3, 2, 4};

    cout << boolalpha; // Imprime true/false en lugar de 1/0

    cout << "Caso []: " << estaOrdenadoIterativo(p1, 0) << endl;
    cout << "Caso [5]: " << estaOrdenadoRecursivo(p2, 1) << endl;
    cout << "Caso [1,2,3,4]: " << estaOrdenadoIterativo(p3, 4) << endl;
    cout << "Caso [1,3,2,4]: " << estaOrdenadoRecursivo(p4, 4) << endl;

    return 0;
}

/*
¿Cuál es el caso base mínimo válido? Es n <= 1. Si el arreglo no tiene elementos 
o tiene solo uno, no hay forma de que esté "desordenado".

¿Qué ocurre si n == 0? La función retorna true. Es el comportamiento estándar en 
programación porque no hay ningún elemento que rompa la regla de orden.

¿Dónde ocurre el primer acceso peligroso? Si en el bucle iterativo usaras i < n en 
lugar de i < n - 1, al llegar al final intentarías acceder a arr[i + 1], que es una 
posición de memoria fuera del arreglo. Esto causaría un error de segmentación o basura.

*/
