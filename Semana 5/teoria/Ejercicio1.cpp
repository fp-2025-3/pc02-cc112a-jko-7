/*
Estructuras en C++
Ejercicios 

Ejercicio 1

Se desea gestionar estudiantes, donde no se conoce de antemano cuántos habrá.
Cada estudiante tiene código y promedio

Escribir un programa que:
a) Solicitar al usuario la cantidad N de estudiantes
b) Reservar memoria dinámicamente para los N estudiantes
c) Leer los datos
d) Mostrar únicamente los aprobados (>= 10)
e) Liberar memoria correctamente

*/

#include <iostream>
using namespace std;

struct Estudiante
{
    int codigo;
    float promedio;
};

void leerEstudiante (Estudiante* estudiante, int N){
    for (int i=0; i<N; i++){
        cout<<"Alumno "<<i+1<<endl;
        cout<<"Codigo: ";
        cin>>estudiante[i].codigo;
        cout<<"Promedio: ";
        cin>>estudiante[i].promedio;
    }
}


void mostrarAprobados(Estudiante* estudiante, int N){
    
    cout<<"\nAlumnos aprobados: "<<endl;

    for (int i=0; i<N; i++){
        if (estudiante[i].promedio>=10){
            cout<<"Alumno "<<i+1<<endl;
            cout<<"Codigo: "<<estudiante[i].codigo<<endl;
            cout<<"Promedio: "<<estudiante[i].promedio<<endl;
        }
    }
}

int main (){

    int N; 
    cout<<"Ingrese la cantidad de estudiantes: ";
    cin>>N;

    Estudiante* estudiante = new Estudiante[N];

    leerEstudiante (estudiante, N);
    mostrarAprobados (estudiante, N);

    delete[] estudiante;

    return 0;
}