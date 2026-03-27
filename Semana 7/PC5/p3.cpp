#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){

    const int COLS = 80;
    const int FILAS = 21;    

    ofstream archivo ("output/grafico.txt");

    if (!archivo){
        cout<<"Error al abrir el archivo grafico.txt"<<endl;
        return 1;
    }

    // Crear una cuadricula vacia (rellenar con espacios)
    char cuadricula [FILAS][COLS];
    for (int i=0; i<FILAS; i++){
        for (int j=0; j<COLS; j++){
            cuadricula[i][j]=' ';
        }
    }

    // Dibujar eje X (fila del medio = fila 10, donde valor = 0)
    int ejeX = FILAS/2;   // fila 10
    for (int j=0; j<COLS; j++){
        cuadricula[ejeX][j] = '-';
    }

    // Dibujar eje Y (columna 0)
    for (int i=0; i<FILAS; i++){
        cuadricula[i][0]='|';
    }
    
    // Evaluar f(x)=sin(5x) en 80 puntos igualmente espaciados en [0, 2*PI]
    for (int j=0; j<COLS; j++){
        double x = j*(2.0*M_PI)/(COLS-1); // x va de 0 a 2*PI
        double fx = sin(5.0*x);             

        // Convertimos valor f(x) a fila:
        // fx =  1  --> fila 0  (arriba)
        // fx =  0  --> fila 10 (medio)
        // fx = -1  --> fila 20 (abajo)
        int fila = (int)round((1.0-fx)/2.0*(FILAS-1));

        cuadricula[fila][j] = '*';
    }

    for (int i=0; i<FILAS; i++){
        for (int j=0; j<COLS; j++){
            archivo<<cuadricula[i][j];
        }
        archivo<<endl;
    }

    archivo.close();  

    return 0;
}