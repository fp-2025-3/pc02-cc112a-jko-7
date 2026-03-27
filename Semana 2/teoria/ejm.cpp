#include <iostream>
using namespace std;

void inicializar (int* ptr2, int n){

    for (int i=0; i<n; i++){
        cout<<"Elemento "<<i<<": ";
        cin>>ptr2[i];
    }

    cout<<endl;

}

void imprimir (int *ptr3, int n){

    for (int i=0; i<n; i++){
        cout<<"Elemento "<<i<<": "<<endl;
        cout<<"Valor: "<<ptr3[i]<<endl;
        cout<<"Direccion: "<<&ptr3[i]<<endl;
    }

}


int main (){

    int n;
    cout<<"Ingrese cuantos elementos desea ingresar: ";
    cin>>n;

    int arr[n];
    int* ptr1 = arr;

    inicializar(ptr1, n);
    imprimir (ptr1, n);


    return 0;
}