#include <iostream>
using namespace std;

int main (){

    int filas=3, columnas=4;

    int** M = new int*[filas];

    for (int i=0; i<filas; i++){
        M[i] = new int [columnas];  // <> *(M+1)
    }


    // FORMA CORRECTA DE LIBERAR
    for (int i=0; i<filas; i++){
        delete[] M[i];
    }

    delete[] M;

    return 0;
}