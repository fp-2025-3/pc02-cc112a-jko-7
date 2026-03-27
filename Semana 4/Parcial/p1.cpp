#include <iostream>
using namespace std;                

int costoMax (int arr[], int n, int pos){

    if (pos==n){
        return 0; 
    }

    int max = 0;
    long long producto = 1;

    for (int i=pos; i<n; i++){
        producto*=arr[i]; 

        int resultadoRestante = costoMax (arr, n, i+1);

        int costoTotal = producto+resultadoRestante;

        if (costoTotal > max){
            max = costoTotal;
        }
    }

    return max;
}

int main (){

    int A[]={1,2,3,4,5};
    int n=sizeof(A)/sizeof(A[0]);

    // Validacion de n
    if (n<1 || n>15){
        cout<<"Error: n debe estar entre 1 y 15.";
        return 1;
    } 

    // Validacion de números enteros positivos
    for (int i=0; i<n; i++){
        if (A[i]<=0){
            cout<<"Error: todos los elementos deben ser enteros positivos";
            return 1;
        }
    }

    for (int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }

    cout<<"\nCosto maximo: "<<costoMax(A,n,0)<<endl;

    return 0;
}

/*
b) A = [2 1 3]. En cada llamada recursiva se prueban todas las posibles 
segmentaciones del primer bloque y se retorna el maximo costo.

costoMax(A,3,pos=0) →  Retorna: 6
|
├── Opción 1: [2] + costoMax(A,3,1)
|             2 + 4 = 6
|                 └──costoMax(A,3,1) → Retorna: 4
|                      ├── Opción 1: [1] + costoMax(A,3,2)
|                      |              1 + 3 = 4
|                      |              └──costoMax(A,3,2) → Retorna: 3
|                      |                 └── Opción 1: [3] + costoMax(A,3,3)
|                      |                                3 + 0 = 3
|                      |                                └── costoMax(A,3,3) → Retorna: 0 (caso base: pos==n)
|                      └── Opción 2: [1 3] + costoMax(A,3,3)
|                                      3 + 0 = 3
|
|                     costoMax(pos=1) retorna max(4,3) = 4
|
|
|
├── Opción 2: [2 1] + costoMax(A,3,2)
|               2 + 3 = 5
|               └──costoMax(A,3,2) → Retorna: 3
|                  └── Opción 1: [3] + costoMax(A,3,3)
|                                 3 + 0 = 3
|                                 └── costoMax(A,3,3) → Retorna: 0 (caso base: pos==n)
|
|
|
|
|
└── Opción 3: [2 1 3] + costoMax(A,3,3)
                 6 + 0 = 6
                 └── costoMax(A,3,3) → Retorna: 0 (caso base: pos==n)

costoMax(pos=0) retorna max(6, 5, 6) = 6

El costo máximo para [2 1 3] es 6.

*/