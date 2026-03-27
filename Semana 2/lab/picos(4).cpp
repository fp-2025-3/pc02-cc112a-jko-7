#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int FILA= 3;
const int COLUMNA= 3;

// A[i]==*(A+i)
// M[i][j] == M[i]+j == *((*M+i)+j)

void leerMatriz (int (*p)[COLUMNA]){

    for (int i=0; i<FILA; i++){
        for (int j=0; j<COLUMNA; j++){
            *(*(p+i)+j)=rand()%41+10;
        }
    }
}

void mostrarMatriz (int (*p)[COLUMNA]){

    for (int i=0; i<FILA; i++){
        for (int j=0; j<COLUMNA; j++){
            cout<<*(*(p+i)+j)<<" ";
        }
        cout<<endl;
    }
}

int contarPicos (const int (*p)[COLUMNA]){

    int cont=0;

    for (int i = 0; i < FILA; i++) {
        for (int j = 0; j < COLUMNA; j++) {

            int actual = *(*(p + i) + j);
            bool esPico = true;

            // Arriba
            if (i > 0 && actual <= *(*(p + i - 1) + j))
                esPico = false;

            // Abajo
            if (i < FILA - 1 && actual <= *(*(p + i + 1) + j))
                esPico = false;

            // Izquierda
            if (j > 0 && actual <= *(*(p + i) + j - 1))
                esPico = false;

            // Derecha
            if (j < COLUMNA - 1 && actual <= *(*(p + i) + j + 1))
                esPico = false;

            if (esPico)
                cont++;
        }
    }

    return cont;

}

void mostrarPicos (int (*p)[COLUMNA]){

    for (int i = 0; i < FILA; i++) {
        for (int j = 0; j < COLUMNA; j++) {

            int actual = *(*(p + i) + j);
            bool esPico = true;

            if (i > 0 && actual <= *(*(p + i - 1) + j))
                esPico = false;
            if (i < FILA - 1 && actual <= *(*(p + i + 1) + j))
                esPico = false;
            if (j > 0 && actual <= *(*(p + i) + j - 1))
                esPico = false;
            if (j < COLUMNA - 1 && actual <= *(*(p + i) + j + 1))
                esPico = false;

            if (esPico)
                cout << "Pico en (" << i << "," << j << ") = " << actual << endl;
        }
    }
}


int main (){

    int M[FILA][COLUMNA];

    srand(time(0));

    cout << "Ingrese los elementos de la matriz:\n";
    leerMatriz(M);

    cout << "\nMatriz ingresada:\n";
    mostrarMatriz(M);

    cout << "\nCantidad de picos: " << contarPicos(M) << endl;

    cout << "\nPicos encontrados:\n";
    mostrarPicos(M);


    return 0;
}