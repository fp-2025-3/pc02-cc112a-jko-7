#include <iostream>
using namespace std;

int** crearMatriz (int n, int m){
    int** M = new int*[n];
    for(int i = 0; i < n; i++){
        M[i] = new int[m];
    }
    return M;
}
 
void llenarMatriz (int** M, int n, int m){ 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            M[i][j] = (i+1)*(j+1);
        }
    }
}                

int* sumaFilas (int** M, int n, int m){
    int* suma = new int[n];
    for(int i = 0; i < n; i++){
        suma[i] = 0;
        for(int j = 0; j < m; j++){
            suma[i] += M[i][j];
        }
    }
    return suma;                    
}

void liberarMatriz (int** M, int n){

    for(int i = 0; i < n; i++){
        delete[] M[i];
    }
    delete[] M;         
}

int main (){

    int n, m;
    cout << "Ingrese el numero de filas: ";
    cin >> n;
    cout << "Ingrese el numero de columnas: ";
    cin >> m;

    int** M = crearMatriz(n, m);
    llenarMatriz(M, n, m);      

    int* suma = sumaFilas(M, n, m); 
    cout<< "Suma de cada fila: "<<endl;
    for(int i = 0; i < n; i++){
        cout<<suma[i]<<" ";
    }                      
    cout<<endl;     
    

    return 0;
}