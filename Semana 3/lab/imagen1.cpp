#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void completarMatriz (int **matriz[], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            *(*(matriz+i)+j)= rand()%10;
        }
    }
}

void imprimirMatriz (int **matriz[], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<*(*(matriz+i)+j)<<" ";
        }
        cout<<endl;
    }
}

int main (){

    int (*matriz)[9];

    int n=9;

    cout<<"Matriz: "<<endl;

    srand(time(0));

    completarMatriz((int**)matriz, n);
    imprimirMatriz((int**)matriz, n);


    return 0;
}