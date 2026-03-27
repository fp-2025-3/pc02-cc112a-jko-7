#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int NFILAS = 9;
const int NCOLS = 9;

void imprimirMatriz (int** A){

    for (int i=0; i<NFILAS; i++){
        for (int j=0; j<NCOLS; j++){
            cout<<*(*A+i*NCOLS+j)<<" ";
        }
        cout<<endl;
    }
}

void generarMAtriz (int** A){

    int valores[NCOLS]={1,2,3,4,5,6,7,8,9};
    
    for (int i=0; i<NFILAS; i++){
        for (int j=0; j<NCOLS; j++){
            int pos=rand()%NCOLS;
            swap(valores[j], valores[pos]);
        }

        for (int j=0; j<NCOLS; j++){
            *(*A + i*NCOLS + j) = valores[j];
        }
    }
}


void actualizar(int **A, int colObjetivo, int valor) {
    for(int i = 0; i < NFILAS; ++i) {
    
        // 1. Buscar donde está el valor
        int posActual = -1;
        for(int j = 0; j < NCOLS; ++j) {
            if(*(*A + i*NCOLS + j) == valor) {
                posActual = j;
                break;
            }
        }
        
        // 2. Mover elemento por elemento hasta llegar
        while(posActual != colObjetivo) {
            // Guardar el primer elemento
            int primero = *(*A + i * NCOLS + 0);
            
            // Desplazar todos una posición a la izquierda
            for(int j = 0; j < NCOLS - 1; ++j) {
                *(*A + i * NCOLS + j) = *(*A + i * NCOLS + (j + 1));
            }
            
            // El primero va al final (circular)
            *(*A + i * NCOLS + (NCOLS - 1)) = primero;
            
            // Actualizar posición del valor
            posActual--;
            if(posActual < 0) {
                posActual = NCOLS-1;
            }
        }
    }
}

int main (){

    srand(time(0));

    int M[NFILAS][NCOLS];   // (*p)[NCOLS];
    int*p = &M[0][0];
    int **A = &p;

    generarMAtriz (A);
    imprimirMatriz (A);

    int fila, cols, valor;

    cout<<"\nFila inicial (1-9): ";
    cin>>fila;
    cout<<"Columna inicial (1-9): ";
    cin>>cols;
    cout<<"Valor seleccionado: ";
    cin>>valor;

    actualizar (A,cols-1,valor);
    cout<<"\nTablero Final: "<<endl;
    imprimirMatriz (A);


    return 0;
}

