#include <iostream>
using namespace std;

const int MAX_COLS = 5;
const int MAX_FILAS = 4;

void imprimirMatriz (int (*ptr)[MAX_COLS]){

    for (int i = 0; i < MAX_FILAS; i++){

        for (int j = 0; j < MAX_COLS; j++){

            cout << (*(*(ptr + i) + j)) << " ";
        }
        cout << endl;
    }
}

void mostrarPicos (int (*ptr)[MAX_COLS]){

    for (int i = 0; i < MAX_FILAS; i++){
        
        for (int j = 0; j < MAX_COLS; j++){

            int valorActual = *(*(ptr + i) + j);
            bool esPico = true;
            bool tieneVecinoMenor = false;

            // Arriba
            if (i > 0) {
                int arriba = *(*(ptr + i - 1) + j);
                if (valorActual < arriba) esPico = false;
                if (valorActual > arriba) tieneVecinoMenor = true;
            }

            // Izquierda
            if (j > 0) {
                int izquierda = *(*(ptr + i) + j - 1);
                if (valorActual < izquierda) esPico = false;
                if (valorActual > izquierda) tieneVecinoMenor = true;
            }

            // Debajo
            if (i < MAX_FILAS - 1) {
                int abajo = *(*(ptr + i + 1) + j);
                if (valorActual < abajo) esPico = false;
                if (valorActual > abajo) tieneVecinoMenor = true;
            }

            // Derecha
            if (j < MAX_COLS - 1) {
                int derecha = *(*(ptr + i) + j + 1);
                if (valorActual < derecha) esPico = false;
                if (valorActual > derecha) tieneVecinoMenor = true;
            }

            if (esPico && tieneVecinoMenor){
                cout << "Pico en (" << i << "," << j << "): " << valorActual << endl;
            }
        }
    }
}

int main (){

    int M [MAX_FILAS][MAX_COLS] = {{3,3,3,3,3},
                                   {3,4,4,2,3},
                                   {3,4,5,4,3},
                                   {3,3,3,3,3}};

    cout << "Matriz: " << endl;
    imprimirMatriz (M);

    cout << "\nElementos pico: " <<endl;
    mostrarPicos (M);


    return 0;
}
