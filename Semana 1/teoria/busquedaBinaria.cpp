/*

===============IMPORTANTE==============
LA BUSQUEDA BINARIA SE HACE EN ARREGLOS ORDENADOS


*/

#include <iostream>
using namespace std;

int busquedaBinaria (int A[], int n, int x){

    int inicio=0, fin=n-1, medio;

    while (inicio<=fin){

        medio=inicio+(fin-inicio)/2;

        if (A[medio]==x){
            return medio;
        } else if (A[medio]<x){
            inicio=medio+1;
        } else {
            fin=medio-1;
        }
    }
    return -1;
}


int main (){

    int arr[] = {2,3,4,6,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<busquedaBinaria(arr,n,4)<<endl;

    return 0;
}