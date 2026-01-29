#include <iostream>
using namespace std;

const int MAX_FILAS = 3;
const int MAX_COLS = 4;

void imprimirMatriz(int (*inicio)[MAX_COLS], int (*fin)[MAX_COLS]){

    for (int(*fila)[MAX_COLS]=inicio; fila<fin; fila++){
        for (int *col=*fila; col<*fila+MAX_COLS; col++){
            cout<<*col<<" ";
        }
        cout<<endl;
    }
}

// c) Obtener puntero al inicio de una fila específica
int* obtenerFila(int (*inicio)[MAX_COLS], int (*fin)[MAX_COLS], int fila) {
    if (fila < 0 || (inicio + fila) >= fin) {
        return nullptr;
    }
    // Retornamos el puntero al primer entero de esa fila
    return *(inicio + fila);  
    /*
¿Por qué *(inicio + 1) es un puntero y no un valor?
Aquí está el truco: Depende de qué es lo que estás apuntando.
Caso A (Puntero simple): Si tienes int* p, entonces *p es un entero (un valor).
Caso B (Tu caso - Puntero a arreglo): Tu variable inicio no apunta a un entero, apunta 
a un bloque de 4 enteros.

Cuando haces *(inicio + 1), estás "entrando" a la fila 1. Pero en C++, una fila es un 
arreglo, y por regla general:

El nombre de un arreglo (o el resultado de desreferenciar un puntero a un arreglo) se 
convierte automáticamente en un puntero a su primer elemento.
*/
}

// d) Obtener puntero a un elemento (fila, col)
int* obtenerElementoColumna(int (*inicio)[MAX_COLS], int (*fin)[MAX_COLS], int col, int fila) {
    if (fila < 0 || (inicio + fila) >= fin || col < 0 || col >= MAX_COLS) {
        return nullptr;
    }
    // Aritmética: Ir a la fila (inicio + fila), 
    // acceder a ella (*) para obtener el int* del inicio, y sumar col.
    return *(inicio + fila) + col;
}

// e) Sumar los elementos de una fila
int sumaFila(int* filaInicio, int columnas) {
    int suma = 0;
    for (int i = 0; i < columnas; ++i) {
        suma += *(filaInicio + i);
    }
    return suma;
}

int main (){


    int M[3][4] = {
    {  2, -1,  4,  6 },
    { -3,  5, -2,  1 },
    {  7, -4,  0,  8 }
    };

    int (*inicio)[MAX_COLS]=M;
    int (*fin)[MAX_COLS]=M+3;

    cout << "--- Matriz completa ---" << endl;
    imprimirMatriz(inicio, fin);

    cout << "\n--- Suma de cada fila ---" << endl;
    for (int i = 0; i < 3; ++i) {
        int* pFila = obtenerFila(inicio, fin, i);
        if (pFila) {
            cout << "Fila " << i << ": " << sumaFila(pFila, 4) << endl;
        }
    }

    cout << "\n--- Elemento específico (1, 2) ---" << endl;
    int f = 1, c = 2;
    int* pElem = obtenerElementoColumna(inicio, fin, c, f);
    if (pElem) {
        cout << "Valor en M[" << f << "][" << c << "]: " << *pElem << endl;
        cout << "Direccion de memoria: " << pElem << endl;
    }

    // Análisis de direcciones (Parte f)
    cout << "\n--- Analisis de direcciones ---" << endl;
    cout << "M (inicio): " << inicio << endl;
    cout << "M + 1     : " << (inicio + 1) << " (Salto de " << sizeof(int)*4 << " bytes)" << endl;


    return 0;
}