#include <iostream>
#include <cmath>
using namespace std;

struct Polinomio
{
    int* coef;
    int grado;
};

void leerPolinomio (Polinomio* polinomio, int &n, int &m){

    cout<<"Ingrese el grado del primer polinomio: ";
    cin>>n;
    polinomio[0].grado = n; 
    polinomio[0].coef = new int[n+1]; //1+ para incluir el termino independiente

    for (int i=n; i>=0; i--){
        cout<<"Ingrese el coeficiente de x^"<<i<<": ";
        cin>>polinomio[0].coef[i];
    }
    
    cout<<"\nIngrese el grado del segundo polinomio: ";
    cin>>m;
    polinomio[1].grado = m;
    polinomio[1].coef = new int[m+1];

    for (int i=m; i>=0; i--){
        cout<<"Ingrese el coeficiente de x^"<<i<<": ";
        cin>>polinomio[1].coef[i];
    }
}

void mostrarPolinomio (Polinomio* polinomio, int n, int m){
    cout<<"\nPrimer polinomio: ";
    for (int i=n; i>=0; i--){
        if (i==0){
            cout<<polinomio[0].coef[i]<<endl;
        } else {
            cout<<polinomio[0].coef[i]<<"x^"<<i<<" + ";
        }
    }

    cout<<"Segundo polinomio: ";
    for (int i=m; i>=0; i--){
        if (i==0){
            cout<<polinomio[1].coef[i]<<endl;
        } else {
            cout<<polinomio[1].coef[i]<<"x^"<<i<<" + ";
        }
    }    
}

void sumarPolinomio (Polinomio* polinomio, int n, int m){

    int gradoMax = (n > m) ? n : m;

    cout<<"La suma de polinomos es: ";

    for (int i=gradoMax; i>=0; i--){
        int suma = 0;

        // Sumar coeficiente del primer polinomio si existe
        if (i<=n){
            suma+=polinomio[0].coef[i];
        }

        // Sumar coeficiente del segundo polinomio si existe
        if (i<=m){
            suma+=polinomio[1].coef[i];
        }

        if (i==0){
            cout<<suma<<endl;
        } else {
            cout<<suma<<"x^"<<i<<" + ";
        }
    }   
}

void multiplicarPolinomio (Polinomio* polinomio, int n, int m){
    int gradoProducto=m+n;
    int* producto = new int[gradoProducto+1];

    // Multiplicar
    for (int i=0; i<=n; i++){
        for (int j=0; j<=m; j++){
            producto[i+j]+=polinomio[0].coef[i]*polinomio[1].coef[j];
        }
        
    }

    cout<<"El producto de los polinomios es: ";
    for (int i = gradoProducto; i >= 0; i--){
        if (i == 0){
            cout << producto[i] << endl;
        } else {
            cout << producto[i] << "x^" << i << " + ";
        }
    }

    delete[] producto;
}

int evaluarPolinomio (Polinomio* polinomio, int indice, double x){
    int resultado = 0;
    int grado = polinomio[indice].grado;

    for (int i=0; i<=grado; i++){
        resultado+=polinomio[indice].coef[i]*pow(x,i);
    }
    return resultado;
}


int main (){

    int n,m;

    Polinomio polinomio[2];

    leerPolinomio (polinomio,n,m);
    mostrarPolinomio(polinomio,n,m);
    sumarPolinomio(polinomio,n,m);
    multiplicarPolinomio(polinomio,n,m);
    
    double valorX;
    cout<<"\nIngrese el valor de x para evaluar el primer polinomio: ";
    cin>>valorX;

    int resultado = evaluarPolinomio(polinomio, 0, valorX);
    cout<<"El primer polinomio evaluado en x="<<valorX<<" es: "<<resultado<<endl;

    // ¡Importante! Liberar la memoria dinámica
    delete[] polinomio[0].coef;
    delete[] polinomio[1].coef;

    return 0;
}