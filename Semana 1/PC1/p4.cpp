#include <iostream>
using namespace std;

void unir (int L[], int A[], int B[], int n){

    int k=0;
    for (int i=0; i<n; i++){
        L[k]=B[i];
        k=k+2;
    }

    k=1;
    for (int i=0; i<n; i++){
        L[k]=A[i];
        k=k+2;
    }

}

void imprimir (int A[], int n){

    for (int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }

    cout<<endl;
}

void bubbleSort (int A[], int indices[], int n){

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){

            if (A[j]>A[j+1]){
                swap (A[j], A[j+1]);

                swap (indices[j], indices[j+1]);

            }
        }
    }

}


int busquedaBinaria (int A[], int indices[], int n, int x){

    int inicio=0, fin=n-1, medio;
    int resultado=-1;

        while (inicio<=fin){

            medio = inicio+(fin-inicio)/2;

            if (A[medio]==x){
                resultado=indices[medio];
                fin=medio-1;

            } else if (A[medio]<x){
                inicio = medio+1;

            } else {
                fin = medio -1;

            }
        }
        return resultado;
}

int main (){

    int A[]={10,8,6,4};
    int n=sizeof(A)/sizeof(A[0]);

    int B[]={9,7,6,5};

    int L[40];
    int indices[40];

    unir (L, A, B, n);

    cout<<"Lista intercalada L: "<<endl;
    cout<<"Indices: ";

    for (int i=0; i<2*n; i++){
        cout<<i<<" ";
        indices[i]=i;
    }

    cout<<"\nValores: ";
    imprimir (L, 2*n);

    int x;
    cout<<"\nIngrese numero a buscar: ";
    cin>>x;
    
    bubbleSort (L, indices, 2*n);

    int resultado=busquedaBinaria(L, indices ,2*n, x);

    if (resultado!=-1){
        cout<<"El numero se encuentra en el indice: "<<resultado<<endl;
    } else {
        cout<<"El numero no se encuentra."<<endl;
    } 


    return 0;
}