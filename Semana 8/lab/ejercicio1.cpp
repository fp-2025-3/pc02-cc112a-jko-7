#include <iostream>
#include <cmath>
using namespace std;

struct Termino
{
    double coeficiente;
    int exponente;
};

struct Polinomio
{
    int cantidad;
    Termino *terminos;
};

void crearPolinomio(Polinomio &p, int n){
    p.cantidad = n;
    p.terminos = new Termino[n];
}

void leerPolinomio(Polinomio &p){
    cout<<"Ingrese los grados y exponentes: "<<endl;

    for (int i=0; i<p.cantidad; i++){
        cout<<"Coeficiente "<<i+1<<": ";
        cin>>p.terminos[i].coeficiente;
        cout<<"Exponente "<<i+1<<": ";
        cin>>p.terminos[i].exponente;
    }
}

// Ordena los términos por exponente de mayor a menor (burbuja)
void ordenarPolinomio(Polinomio &p){
    for (int i=0; i<p.cantidad-1; i++){
        for (int j=i+1; j<p.cantidad; j++){
            if (p.terminos[i].exponente < p.terminos[j].exponente){
                swap(p.terminos[i], p.terminos[j]);
            }
        }
    }
}

void mostrarPolinomio(const Polinomio &p){
    for (int i=0; i<p.cantidad; i++){
        cout<<p.terminos[i].coeficiente<<"x^"<<p.terminos[i].exponente;

        if(i<p.cantidad-1){
            cout<<" + ";
        }
    }
    cout<<endl;
}


double evaluarPolinomio(const Polinomio &p, double x){
    double resultadoEvaluar = 0;
    for (int i=0; i<p.cantidad; i++){
        resultadoEvaluar+=p.terminos[i].coeficiente*pow(x,p.terminos[i].exponente);
    }
    
    return resultadoEvaluar;
}

// Completar la derivada del polinomio
void derivarPolinomio(const Polinomio &p, Polinomio &derivada){
    int numExpNoNulos = 0;

    for (int i=0; i<p.cantidad; i++){
        if (p.terminos[i].exponente != 0){
            numExpNoNulos++;
        }
    }

    crearPolinomio(derivada, numExpNoNulos);

    int j=0;
    for (int i=0; i<p.cantidad; i++){
        if(p.terminos[i].exponente != 0){
            derivada.terminos[j].coeficiente = p.terminos[i].coeficiente*p.terminos[i].exponente;
            derivada.terminos[j].exponente = p.terminos[i].exponente-1;
            j++;
        }
    }
    ordenarPolinomio (derivada);
}

// Suma de 2 polinomios
void sumarPolinomios(Polinomio &p1, Polinomio &p2, Polinomio &resultado){
    int max = p1.cantidad+p2.cantidad;
    resultado.terminos = new Termino[max];
    resultado.cantidad = 0;

    // Copiar todos los terminos de p1
    for (int i=0; i<p1.cantidad; i++){
        resultado.terminos[resultado.cantidad]=p1.terminos[i];
        resultado.cantidad++;
    }

    // Agregar términos de p2, sumando si el exponente ya existe
    for (int i=0; i<p2.cantidad; i++){
        bool encontrado = false;

        for (int j=0; j<resultado.cantidad; j++){
            if (resultado.terminos[j].exponente == p2.terminos[i].exponente){
                resultado.terminos[j].coeficiente += p2.terminos[i].coeficiente;
                encontrado = true;
                break;
            }
        }

        // Si no existe ese exponente, agregarlo
        if (!encontrado){
            resultado.terminos[resultado.cantidad] = p2.terminos[i];
            resultado.cantidad++;
        }
    }

    ordenarPolinomio(resultado);
}

void liberarPolinomio(Polinomio &p){
    delete[] p.terminos;
    p.terminos = nullptr;
}

int main (){

    // ----- Polinomio -----
    Polinomio p1;
    int n1;

    cout<<"Ingrese la cantidad de terminos del polinomio 1: ";
    cin>>n1;

    crearPolinomio(p1,n1);
    leerPolinomio(p1);
    ordenarPolinomio(p1);

    cout<<"\nPolinomio p1: "<<endl;
    mostrarPolinomio(p1);

    double x=1;

    cout<<"p1("<<x<<") = "<<evaluarPolinomio(p1,x)<<endl;

    // --- Derivada ---

    Polinomio derivada;
    derivarPolinomio(p1,derivada);
    cout<<"\nDerivada de p1: "<<endl;
    mostrarPolinomio(derivada);

    x=3;
    cout<<"p1("<<x<<") = "<<evaluarPolinomio(derivada,x)<<endl;

    // ----- Polinomio 2 -----
    Polinomio p2;
    int n2;
    cout<<"\nIngrese la cantidad de terminos del polinomio 2: ";
    cin>>n2;
    crearPolinomio(p2, n2);
    leerPolinomio(p2);
    ordenarPolinomio(p2);

    cout << "\nPolinomio p2: ";
    mostrarPolinomio(p2);

    // ----- Suma -----
    Polinomio suma;
    sumarPolinomios(p1, p2, suma);
    cout << "\np1 + p2 = ";
    mostrarPolinomio(suma);

    x=2;
    cout << "(p1+p2)(" << x << ") = " << evaluarPolinomio(suma, x) << endl;

    liberarPolinomio(p1);
    liberarPolinomio(p2);
    liberarPolinomio(derivada);
    liberarPolinomio(suma);

    return 0;
}