/*
Ejercicio 1
Implemente un programa para gestionar notas de un curso utilizando asignación dinámica.
El programa debe:
*/

#include <iostream>
using namespace std;

// 1.1. Solicitar al usuario el número n de estudiantes.
void leerEstudiantes (int& n){
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>n;
}

// 1.2. Reservar memoria dinámica para almacenar las notas float notas[n]
float* reservarMemoria (int n){

    return new float[n];
}

// 1.3. Leer las notas desde el teclado
void leerNotas (float* notas, int n){

    for (int i=0; i<n; i++){
        cout<<"Ingrese la nota "<<i+1<<": ";
        cin>>notas[i];
    }

}

// 1.4. Calcular: Promedio del curso. Nota máxima y mínima
float calculoPromedio (float *notas, int n){

    float sum=0;

    for (int i=0; i<n; i++){
        sum+=notas[i];
    }

    return sum/n;
}

void calculoMinMax (float* notas, int n, float &max, float & min){

    min = notas[0];
    max = notas[0];

    for (int i=0; i<n; i++){
        if (notas[i]<min){
            min=notas[i];
        }

        if (notas[i]>max){
            max=notas[i];
        }
    }
}

// 1.5. Redimensionar dinámicamente el arreglo para agregar k estudiantes.
void redimensionar (float*& notas, int &n, int k){

    // Asignar memoria dinamica de tamaño n+k
    float* nuevo = new float [n+k];

    // Copiar los valores antiguos
    for (int i=0; i<n; i++){
        nuevo[i]=notas[i];
    }

    // Actualizar notas (puntero)
    delete[] notas;
    notas = nuevo;

    n=n+k;
}

void liberarMemoria (float*& notas){
    delete [] notas;
    notas = nullptr;
}

int main (){

    int n;
    float* notas=nullptr;

    leerEstudiantes(n);
    notas = reservarMemoria (n);
    leerNotas (notas, n);

    cout<<"Promedio inicial: "<<calculoPromedio(notas, n)<<endl;

    float max,min;
    calculoMinMax (notas, n, max, min);

    /*
    1.6. Leer las nuevas notas
    1.7. Recalcular los valores (1.4)
    1.8. Liberar correctamente la memoria
    */

    int k;
    cout<<"Ingrese la cantidad de estudiantes a agregar: ";
    cin>>k;

    redimensionar (notas, n, k);

    // Usamos aritmética de punteros (notas + n - k) para empezar a llenar 
    // el arreglo justo donde terminaban los datos anteriores.
    leerNotas (notas+n-k, k);  

    cout<<"Promedio final: "<<calculoPromedio(notas, n)<<endl;

    calculoMinMax (notas, n, max, min);

    cout<<"Nota minima: "<<min<<" | Nota maxima: "<<max<<endl;

    liberarMemoria (notas);

    return 0;
}