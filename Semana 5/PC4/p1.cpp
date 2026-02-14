#include <iostream>
using namespace std;


struct Polinomio
{
    float *coef;
    int grado;
};

void sumaPolinomios(Polinomio* polinomio, int n){

    int gradoMax = n;

    for (int i=gradoMax; i>=0; i--){

        float suma = 0;

        if (i<=n){
            suma+=polinomio[0].coef[i];
        }

        
        if (i<=n){
            suma+=polinomio[1].coef[i];
        }

        if (i<=n){
            suma+=polinomio[2].coef[i];
        }

        if (i==0){
            cout<<suma<<endl;
        } else {
            cout<<suma<<"x^"<<i<<" + ";
        }
    }   

}
    


void multiplicarPolinomio (Polinomio* polinomio, int n){

    int gradoProducto=2*n;
    float* producto = new float[gradoProducto+1];

    for (int i=0; i<=gradoProducto; i++){
        producto[i]=0;
    }

    // Multiplicar
    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++){
            for (int k=0; k<=n; k++){
                producto[i+j+k]+=polinomio[0].coef[i]*polinomio[1].coef[j]*polinomio[2].coef[k];
            }
        }
        
    }

    for (int i = gradoProducto; i >= 0; i--){
        if (i == 0){
            cout << producto[i] << endl;
        } else {
            cout << producto[i] << "x^" << i << " + ";
        }
    }

    delete[] producto;

}


int main (){

    Polinomio polinomio[3];

    polinomio[0].coef = new float[2];
    polinomio[0].coef[0] = 1;
    polinomio[0].coef[1] = 0;
    polinomio[0].coef[2] = 3;
    
    polinomio[1].coef = new float[2];
    polinomio[1].coef[0] = 5;
    polinomio[1].coef[1] = -4;
    polinomio[1].coef[2] = 0;

    polinomio[2].coef = new float[2];
    polinomio[2].coef[0] = 3;
    polinomio[2].coef[1] = 0;
    polinomio[2].coef[2] = 1;

    int k=1;
    for (int i=2; i>=0; i--){
        cout<<"Polinomio "<<k++<<": ";
        for (int j=2; j>=0; j--){
            if (polinomio[i].coef[j]==0){
                continue;
            } else {
                if (j==0){
                cout<<polinomio[i].coef[j];
                } else{
                    cout<<polinomio[i].coef[j]<<"x^"<<j<<" + ";
                }
            }
        }
        cout<<endl;
    }

    cout<<"Suma de los tres polinomios: ";
    sumaPolinomios(polinomio,2);

    cout<<"Producto de los tres polinomios: ";   
    multiplicarPolinomio(polinomio,2);


    return 0;
}

