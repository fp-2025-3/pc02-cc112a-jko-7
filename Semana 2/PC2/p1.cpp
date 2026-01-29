#include <iostream>
using namespace std;

// Complete la funcion que calcula la derivada de orden k de un polinomio
// Usar EXCLUSIVAMENTE punteros (NO indices)

void derivadaK(
    const double* coef, //
    int grado, int k,   //
    double* res,        //
    int& gradoRes       //
) {
    // Escriba su codigo aqui
    gradoRes = grado - k;

    for (int j = 0; j <= grado; ++j){   // damos 0s a res 
        *(res + j) = 0;
    }
    
    for (int i = k; i <= grado; ++i){  // empezamos desde k porque los terminos con exponentes 
                                        // menor que k desaparecen
        double coefDerivada = *(coef + i);  // ponemos a coefDerivada los valores de coef
    
        for (int j = 0; j < k; ++j){   // derivar k veces es multiplicar n(n-1)(n-2)...(n-k+1) x^n-k

            coefDerivada *= (i - j);    
        }
        
        *(res + i - k) = coefDerivada; // Restamos k para que el término que estaba en x^k este en 
                                      // posición 0
    }
}

// Complete la función auxiliar para imprimir un polinomio
void imprimirPolinomio(const double* p, int grado) {

    for (int i = grado; i >= 0; --i){
        double coef = *(p + i);

        if (coef != 0){

            if (i != grado && coef > 0){

                cout << "+";
            }
            cout << coef;

            if (i > 0){ 
                cout << "x^" << i;
            }
            cout << " ";

        }
    }
    cout << endl;
}

int main() {
    // Polinomio:
    // P(x) = 2 + 3x - x^2 + 4x^3
    double coef[] = {2, 3, -1, 4};
    const int grado = 3;

    double resultado[10]; // espacio suficiente
    int gradoResultado;

    int k = 2; // derivada de orden 2

    // Llamar a su funcion derivadaK
    derivadaK (coef, grado, k, resultado, gradoResultado);

    // Llamar la funcion imprimir para mostrar el polinomio original y  la derivada
    cout << "Polinomio original: ";
    imprimirPolinomio (coef, grado);
    
    cout << "Derivada de orden " << k << ": ";
    imprimirPolinomio (resultado, gradoResultado);

    return 0;
}
