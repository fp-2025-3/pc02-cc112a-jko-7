#include <iostream>
using namespace std;

const int MAX_COLS = 5;
const int MAX_FILA = 4;

void mostrarMatriz (int (*ptr)[MAX_COLS]){

    for (int i = 0; i < MAX_FILA; i++){

        for (int j = 0; j < MAX_COLS; j++){

            cout << *(*(ptr + i) + j) << "\t";
        }
        cout << endl;
    }
}

int sumaRango (int (*ptr)[MAX_COLS], int i1, int j1, int i2, int j2){

    int suma = 0;

    for (int i = i1; i <= i2; i++){

        for (int j = j1; j <= j2; j++){

            suma+=*(*(ptr + i) + j);
        }
    }
    return suma;
}

void maxSubmatriz (int (*ptr)[MAX_COLS]){

    int maxSuma = -999;
    int mejorI1 = 0, mejorJ1 = 0, mejorI2 = 0, mejorJ2 = 0;

    // Probar cada posible esquina superior izquierda (i,j)
    for (int i = 0; i < MAX_FILA; i++){
        
        for (int j = 0; j < MAX_COLS; j++){

            // Probar cada posible esquina inferior derecha (k, l)
            for (int k = i; k < MAX_FILA; k++){

                for (int l=j; l < MAX_COLS; l++){

                    int sumaActual = sumaRango(ptr, i, j, k, l);

                    if (sumaActual > maxSuma){
                        maxSuma = sumaActual;
                        mejorI1 = i;
                        mejorJ1 = j;
                        mejorI2 = k;
                        mejorJ2 = l;
                    }
                }
            }
        }
    }

    cout << "Esquina superior izquierda: (" << mejorI1 << ", " << mejorJ1 << ")" << endl;
    cout << "Esquina inferior derecha: (" << mejorI2 << ", " << mejorJ2 << ")" << endl;
    cout << "Suma maxima: " << maxSuma << endl;

}


int main (){

    int M [MAX_FILA][MAX_COLS] = {{-2,1,-3,4,-1},
                                  {2,3,-2,1,-5},
                                  {-1,4,2,-3,2},
                                  {1,-2,3,4,-1}};

    cout << "Matriz: " << endl;
    mostrarMatriz (M);
    
    cout << "Submatriz de suma maxima: " << endl;
    maxSubmatriz (M);

    return 0;
}