
// 7. Recorrido de matriz sin índices


#include <iostream>
using namespace std;

int main() {
    int m[2][3] = {{1,2,3},{4,5,6}};
    /*
    Qué es realmente una matriz en memoria
    int m[2][3];
    m ──▶   [1][2][3]   ← fila 0
            [4][5][6]   ← fila 1
    
    int (*p)[3] = m;
    p apunta a la primera fila

    p ──▶ fila 0


    
    */

    int (*p)[3] = m;

    for (int (*fila)[3] = p; fila < p + 2; ++fila) { // for (inicialización; condición; incremento)
    /*
    ¿Por qué fila es un puntero y no un int?

    Porque no estás contando números, estás recorriendo memoria.

    Entonces:
    int (*fila)[3];

    “fila apunta a una fila completa de 3 enteros”
    fila NO apunta a un int apunta a un arreglo de 3 int

    ¿Por qué puedo hacer fila = p?
    int (*p)[3] = m;
    int (*fila)[3] = p;

    Porque:
    p apunta a una fila
    fila apunta a una fila
    mismo tipo → asignación válida
        
    */
        for (int* col = *fila; col < *fila + 3; ++col) {
        /*
        Desarmemos:
        *fila
        fila → puntero a fila
        *fila → fila actual (int[3])
        el arreglo decae a int*

        Por eso:
        int* col = *fila;
        es legal.
        
        */

            cout << *col << " ";
        }
        cout << endl;
    }
}


int (*p)[10];  // un puntero a un arreglo de 10 int 
int* p[10];     // un arreglo de 10 punteros int
int (*(*p)[5])[3];  // p es un puntero a un arreglo de 5 punteros a arreglos de 3 enteros
// p apunta a un arreglo de 5 elementos;
// cada elemento es un puntero a un arreglo de 3 int.