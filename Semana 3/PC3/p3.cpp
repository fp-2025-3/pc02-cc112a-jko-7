#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int FILAS = 9;
const int COLS = 9;

void imprimirMatriz (int** A){

    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cout<<*(*A+i*COLS+j)<<" ";
        }
        cout<<endl;
    }
}

void crearMatriz (int** A){

    int numeros[9]={1,2,3,4,5,6,7,8,9};
    
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            int pos=rand()%9;
            swap(numeros[j], numeros[pos]);
        }

        for (int j=0; j<9; j++){
            *(*A+i*COLS+j)=numeros[j];
        }
    }
}

void cambiarPos(int **A, int col, int valor) {
    for(int i=0; i<9; i++) {
    
        int posActual=0;

        for(int j=0; j<9; j++) {
            if(*(*A+i*COLS+j)==valor) {
                posActual=j;
            }
        }
        
        while(posActual != col-1) {

            int primero=*(*A+i*COLS+0);
            
            for(int j=0; j<8; j++) {  // desplazamos
                *(*A+i*COLS+j)=*(*A+i*COLS+j+1);
            }
            
            *(*A+i*COLS+8)=primero; 
            
            posActual--;

            if(posActual<0) {
                posActual=8;
            }
        }
    }
}

int main (){

    srand(time(0));

    int M[FILAS][COLS];   
    int*p = &M[0][0];
    int **A = &p;

    crearMatriz(A);
    cout<<"Matriz inicial: "<<endl;
    imprimirMatriz(A);

    int fila, cols, valor;

    cout<<"\nFila inicial (1-9): ";
    cin>>fila;
    cout<<"Columna inicial (1-9): ";
    cin>>cols;
    cout<<"Valor seleccionado: ";
    cin>>valor;

    cambiarPos (A,cols,valor);
    cout<<"\nTablero final: "<<endl;
    imprimirMatriz (A);

    return 0;
}

