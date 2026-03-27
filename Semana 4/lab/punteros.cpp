#include <iostream>
using namespace std;

const int N = 5;

/*
Una fila se considera dominante si cada uno de sus 
elementos es estrictamente mayor que el elemento 
correspondiente de todas las demás filas en la misma columna.
*/
bool esFilaDominante (int (*M)[N], int fila){
    
    // Recorremos todas las demás filas de la matriz
    for (int i=0; i<N; i++ ){
        // Saltamos si es la misma fila
        if (i==fila) continue;

        for (int j=0; j<N; j++){
            if (*(*(M+fila)+j) <= *(*(M+i)+j)){
                // Si encontramos un elemento que no es mayor 
                return false;
            }
        }
    }
    // Si recorrió todo y nunca fallo, es dominante
    return true;
}

/*
Una columna se considera crítica si la suma de sus elementos es mayor 
que la suma de cualquier fila de la matriz.
La función debe retornar la cantidad total de columnas críticas.
*/
int contarColumnasCriticas(int (*M)[N]){

    int cont=0;
    int maxSumfila=0;

    // Encontramos la mayor suma de las filas
    for (int i=0; i<N; i++){

        int sumFila=0;
        for (int j=0; j<N; j++){
            sumFila+=*(*(M+i)+j);
        }
        if (maxSumfila<sumFila){
            maxSumfila=sumFila;
        }
    }

    // Suma de cada columna y comparamos
    for (int j=0; j<N; j++){
        int sumaCols=0;
        for (int i=0; i<N; i++){
            sumaCols+=*(*(M+i)+j);
        }

        if (sumaCols>maxSumfila){
            cont++;
        }
    }

    return cont;
}

/*
Una matriz es escalonada si, para cada fila, la posición del primer 
elemento no nulo aparece en una columna estrictamente mayor que la del 
primer elemento no nulo de la fila anterior.
*/
bool esMatrizEscalonada(int (*M)[N]){

    int posAnterior = -1;

    for (int i=0; i<N; i++){
        int* fila = *(M+i);
        int posActual = -1;

        for (int j=0; j<N; j++){
            if (*(fila+j) != 0){
                posActual = j;
                break;
            }
        }

        if (posActual != -1){
            if (posActual <= posAnterior){
                return false;
            }
            posAnterior = posActual;
        }
    }

    return true;
}

/*
El núcleo de la matriz es un elemento que cumple simultáneamente:
Es el máximo de su fila
Es el mínimo de su columna
La función debe retornar el valor del núcleo. Si no existe ningún elemento 
que cumpla ambas condiciones, retornar -1.
*/
int valorNucleo(int (*M)[N]){
    
    for (int i=0; i<N; i++){

        int maxFila=*(*(M+i)+0);
        int col=0;

        for (int j=1; j<N; j++){
            if (*(*(M+i)+j)>maxFila){
                maxFila=*(*(M+i)+j);
                col=j;
            }
        }

        // Verificamos si maxFila es el minimo de su columna
        bool esMinimoCol = true;
        for (int k=0; k<N; k++){
            if (*(*(M+k)+col)<maxFila){
                esMinimoCol=false;
            }
        }

        if (esMinimoCol){
            return maxFila;
        }
    }

    return -1;
}


int main (){

    const int N=5;
    int M[N][N] = {
        {0, 0, 7, 8, 9},
        {0, 0, 0, 5, 6},
        {0, 0, 0, 0, 4},
        {1, 2, 3, 4 ,5},
        {9, 8, 7, 6, 5}
    };

    if (esFilaDominante (M, 2)){
        cout<<"La fila 2 es dominante."<<endl;
    } else {
        cout<<"La fila no es dominante."<<endl;
    }

    cout<<"Columnas criticas: "<<contarColumnasCriticas(M)<<endl;
    
    if (esMatrizEscalonada(M)){
        cout<<"SI es matriz escalonada."<<endl;
    } else {
        cout<<"NO es una matriz escalonada."<<endl;
    }

    cout<<"Nucleo de la matriz: "<<valorNucleo(M);

    return 0;
}