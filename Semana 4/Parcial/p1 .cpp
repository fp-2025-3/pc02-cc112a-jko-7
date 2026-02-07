#include <iostream>
using namespace std;                

int costoMax (int arr[], int n, int pos){

    if (pos==n){
        return 0; 
    }

    int max = -999;
    int producto = 1;

    for (int i=pos; i<n; i++){
        producto*=arr[i]; 

        int resultadoRestante = costoMax (arr, n, i+1);

        if (resultadoRestante != -999){
            int costoActual = producto+resultadoRestante;
            if (costoActual > max){
                max = costoActual;
            }
        }
    }

    return max;
}


int main (){

    int A[]={1,2,3,4,5};
    int n=sizeof(A)/sizeof(A[0]);

    for (int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    cout<<"Costo maximo: "<<costoMax(A,n,0)<<endl;

    return 0;
}



/*
b) A = [2 1 3], va calculando en cada recursividad el producto 
del bloque 

        [2] [1] [3]  ---> 6
        [2] [1 3]  ---> 5
        [2 1 3] ---> 6


*/