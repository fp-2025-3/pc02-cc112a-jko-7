#include <iostream>
using namespace std;

// Complete la funcion de busqueda
int* buscar(
    int* inicio,                 // Estos dos primeros parametros
    int* fin,                    // delimitan el rango de busqueda a [inicio, fin)
    bool (*equivale)(int, int),  // equivale es una funcion que determina cuando dos enteros se condideran equivalentes
    int clave                    // clave es el valor a buscar segun el criterio indicado
) {
    // Complete aqui 

    for (int *ptr=inicio; ptr<fin; ++ptr){

        if (equivale(*ptr, clave)){
            return ptr;
        }
    }    
    return fin;
}

// Implemente aqui los Criterios de equivalencia
// y si es necesario algunas funciones adicionales para reproducir el ejemplo de salida

bool igual (int a, int b){
    return a == b;
}

bool mismaParidad (int a, int b){
    return abs(a)%2 == abs(b)%2;
}

bool divideA (int a, int b){
    return b%a == 0;
}

bool mismaCantidadDigitos (int a, int b){
    // Definimos una "mini-función" interna llamada countDigits usando auto
    auto countDigits = [] (int num){  

        if (num == 0) return 1; // Si es 0, tiene 1 dígito

        int count = 0;

        // Si el número es negativo, lo convertimos a positivo
        if (num < 0) num = -num;

        // Mientras el número sea mayor a 0, seguimos quitando dígitos
        while (num > 0){
            num /= 10;
            count++;
        }
        return count;

    };

    return countDigits(a) == countDigits(b); 
}


bool mimoResiduoMod5 (int a, int b){
    return a%5==b%5;
}


int main() {
    int A[] = { -1, 21, 2, -2, 8, 13, 25 };
    int* inicio = A;
    int* fin = A + 7;

    int clave = 13;

    // Imprima el arreglo
    cout << "Arreglo: ";
    for (int *ptr = inicio; ptr < fin; ++ptr){
        cout << *ptr <<" ";
    }
    cout << endl;

    cout << "\nClave: " <<clave;
    cout << endl;

    // Llame a la funcion buscar para cada criterio implementado
    cout << "\nIgualdad exacta: encontrado valor: " ;
    int *resultado = buscar(inicio, fin, igual, clave);
    cout << *resultado << " Pos: " << resultado << endl;

    cout << "Misma paridad: encontrado valor: " ;
    int *resultado2 = buscar(inicio, fin, mismaParidad, clave);
    cout << *resultado2 << " Pos: " << resultado2 << endl;
 
    cout << "Divide a: encontrado valor: " ;
    int *resultado3 = buscar(inicio, fin, divideA, clave);
    cout << *resultado3 << " Pos: " << resultado3 << endl;

    cout << "Misma cantidad de digitos: encontrado valor: " ;
    int *resultado4 = buscar(inicio, fin, mismaCantidadDigitos, clave);
    cout << *resultado4 << " Pos: " << resultado4 << endl;

    cout << "Mismo residuo modulo 5: encontrado valor: " ;
    int *resultado5 = buscar(inicio, fin, mimoResiduoMod5, clave);
    cout << *resultado5 << " Pos: " << resultado5 << endl;

    return 0;
}
