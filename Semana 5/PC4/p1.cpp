#include <iostream>
using namespace std;


struct Polinomio
{
    float *coef;
    int grado;
};

// Función auxiliar para crear polinomios
Polinomio crearPolinomio(int grado, float coeficientes[]){

    Polinomio p;
    p.grado = grado;
    p.coef = new float[grado+1];

    for (int i=0; i<=grado; i++){
        p.coef[i] = coeficientes[i];
    }

    return p;
}

void imprimirPolinomio(float* coefs, int grado){
    bool primero = true;
    for (int i=grado; i>=0; i--){
        if (coefs[i] != 0){
            if (!primero){
                cout<<(coefs[i]>0 ? " + ":" - ");
                cout<<(coefs[i]>0 ? coefs[i]:-coefs[i]);
            } else {
                cout<<coefs[i];
            }

            if (i>0){
                cout<<"x^"<<i;
            }
            primero=false;
        }
    }
}

void sumaPolinomios(Polinomio* polinomio, int n){

    // Encontrar grado máximo
    int gradoMax = 0;

    for (int i=0; i<n; i++){
        if (gradoMax < polinomio[i].grado){
            gradoMax = polinomio[i].grado;
        }
    }

    float* suma = new float[gradoMax+1]();  // inicializa suma en ceros

    // Sumar todos los polinomios
    for (int i=0; i<n; i++){
        for (int j=0; j<=polinomio[i].grado; j++){
            suma[j] += polinomio[i].coef[j];
        }
    }   

    imprimirPolinomio(suma, gradoMax);
    cout<<endl;
    delete[] suma;
}

void multiplicarPolinomio (Polinomio* polinomio, int n){

    int gradoProd = 0;

    for (int i=0; i<n; i++){
        gradoProd+=polinomio[i].grado;
    }

    float* producto = new float[gradoProd+1]();  // inicializa productos en ceros

    // Multiplicar
    for (int i=0; i<=polinomio[0].grado; i++){
        for (int j=0; j<=polinomio[1].grado; j++){
            for (int k=0; k<=polinomio[2].grado; k++){
                producto[i+j+k]+=polinomio[0].coef[i]*polinomio[1].coef[j]*polinomio[2].coef[k];
            }
        }
    }

    imprimirPolinomio(producto, gradoProd);
    cout<<endl;
    delete[] producto;
}


int main (){

    Polinomio polinomio[3];

    float coefs1[] = {3,0,1};   // 1x^2 + 3
    float coefs2[] = {5,-4};    // -4x^1 + 5
    float coefs3[] = {1,0,3};   // 3x^2 + 1

    polinomio[0] = crearPolinomio(2, coefs1);
    polinomio[1] = crearPolinomio(1, coefs2);
    polinomio[2] = crearPolinomio(2, coefs3);

    for (int i=0; i<3; i++){
        cout<<"Polinomio "<<i+1<<": ";
        imprimirPolinomio(polinomio[i].coef,polinomio[i].grado);
        cout<<endl;
    }

    cout<<"\nSuma de los tres polinomios: ";
    sumaPolinomios(polinomio,3);

    cout<<"\nProducto de los tres polinomios: ";   
    multiplicarPolinomio(polinomio,3);

    for (int i=0; i<3; i++){
        delete[] polinomio[i].coef;
    }

    return 0;
}

