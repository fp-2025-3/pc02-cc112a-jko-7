#include <iostream>
using namespace std;


int main (){

    double A[]={8.8,10.1,14.4,16.6,18.8,20.5};

    int n=sizeof(A)/sizeof(A[0]);

    double p, pv;
    
    cout<<"Peso de una galleta (en gramos): ";
    cin>>p;


    if (p <= A[0]){

        pv = A[0];

    }  else if  (p >= A[n-1]){

        pv = A[n-1];

    } else {

        // Búsqueda binaria para encontrar el intervalo

        int inicio = 1, fin = n - 1, medio;
        
        while (inicio < fin) {           
            medio = inicio + (fin - inicio) / 2;
            
            if (A[medio] < p) {
                inicio = medio + 1;
            } else {
                fin = medio;
            }
        }

        int pos = inicio; // pos es el índice superior del intervalo
        
        if (p == A[pos]) {
            pv = A[pos];
        } else {
            pv = (A[pos-1] + A[pos]) / 2;
        }
    }

    cout<<"Precio sugerido: s/ "<<pv/20<<endl;


    return 0;
}

