#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int main (){

    int n;

    do
    {
        cout<<"Ingrese la dimension de la matriz cuadrada (entre 2 y 8): ";
        cin>>n;

    } while (n<2 || n>8);

    cout<<"\nMatriz original: "<<endl;

    srand(time(0));

    int A[10][10];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            A[i][j]=rand()%101;
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"\nMatriz ordenada: "<<endl;

    int total=n*n;

    int T[100];
    int k=0;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            T[k]=A[i][j];
            k++;
        }
    }

    for (int i=0; i<total-1; i++){
        int indMin=i;

        for (int j=i+1; j<total; j++){
            if (T[j]<T[indMin]){
                indMin=j;
            }
            
        }
        swap (T[i], T[indMin]);
    }

    k=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            A[i][j]=T[k];
            k++;
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }


    return 0;
}