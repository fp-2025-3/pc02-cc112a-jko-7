#include <iostream>
using namespace std;

struct Polinomio
{
    int* x;
};

void leerPolinomio (Polinomio* polinomio, int &n, int &m){

    cout<<"Ingrese el grado del primer polinomio: ";
    cin>>n;

    polinomio[0].x = new int[n+1]; // 1+ para incluir el termino independiente

    for (int i=n; i>=0; i--){
        cout<<"Ingrese el coeficiente de x^"<<i<<": ";
        cin>>polinomio[0].x[i];
    }
    
    cout<<"Ingrese el grado del segundo polinomio: ";
    cin>>m;

    polinomio[1].x = new int[m+1];

    for (int i=m; i>=0; i--){
        cout<<"Ingrese el coeficiente de x^"<<i<<": ";
        cin>>polinomio[1].x[i];
    }
}

void mostrarPolinomio (Polinomio* polinomio, int n, int m){
    cout<<"\nPrimer polinomio: ";
    for (int i=n; i>=0; i--){
        if (i==0){
            cout<<polinomio[0].x[i]<<endl;
        } else {
            cout<<polinomio[0].x[i]<<"x^"<<i<<" + ";
        }
    }

    cout<<"Segundo polinomio: ";
    for (int i=m; i>=0; i--){

        if (i==0){
            cout<<polinomio[1].x[i]<<endl;
        } else {
            cout<<polinomio[1].x[i]<<"x^"<<i<<" + ";
        }
    }    
}

void sumarPolinomio (Polinomio* polinomio, int n, int m){

    cout<<"La suma de polinomos es: ";

    if (n>m){
        for (int i=n; i>=0; i--){

            if (i==0){
                cout<<polinomio[0].x[n]+polinomio[1].x[m];
            } else {
               cout<<polinomio[0].x[n]+polinomio[1].x[m]<<"x^"<<i<<" + ";
            }
        }
    } else {
        for (int i=m; i>=0; i--){

            if (i==0){
                cout<<polinomio[0].x[n]+polinomio[1].x[m];
            } else {
               cout<<polinomio[0].x[n]+polinomio[1].x[m]<<"x^"<<i<<" + ";
            }
        }

    }
    


}

int main (){

    int n,m;

    Polinomio polinomio[2];

    leerPolinomio (polinomio,n,m);
    mostrarPolinomio(polinomio,n,m);
    



    // ¡Importante! Liberar la memoria dinámica
    delete[] polinomio[0].x;
    delete[] polinomio[1].x;

    return 0;
}