#include <iostream>
using namespace std;

int dominates (int A[], int i, int maxDerecha){
    
    // Caso base: ya no hay mas elementos
    if (i<0){
        return 0;
    }

    //Si A[i] es mayor que todo lo que esta a la derecha 
    if (A[i]>maxDerecha){
        return 1+dominates(A, i-1, A[i]);
    } else {
        return dominates (A, i-1, maxDerecha);
    }

}


int main (){

    int A[]={5,3,8,6,2,1};

    int n=sizeof(A)/sizeof(A[0]);

    int resultado=1+dominates(A, n-2, A[n-1]);

    cout<<resultado<<endl;

    return 0;

}