#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;

void agregarDuplicar (int* &codigo, float* &promedios, int &n, int &capacidad){
    if (n==capacidad){
        
        int* codNuevo = new int [capacidad*2];
        float* promNuevo = new float [capacidad*2];
        for (int i=0; i<capacidad; i++){
            codNuevo[i]=codigo[i];
            promNuevo[i]=promedios[i];          
        }

        delete[] codigo;
        delete[] promedios;

        codigo=codNuevo;
        promedios=promNuevo;
        capacidad*=2;
    }   

    cout<<"Ingrese codigo: ";
    cin>>codigo[n];
    cout<<"Ingrese promedio: ";
    cin>>promedios[n];
    n++;
}       


void eliminarDesaprobados (int* &codigo, float* &promedios, int &n){
    int* codNuevo = new int [n];
    float* promNuevo = new float [n];

    int j=0;

    for (int i=0; i<n; i++){
        if (promedios[i]>=10){
            codNuevo[j]=codigo[i];
            promNuevo[j]=promedios[i];
            j++;
        }
    }

    delete[] codigo;
    delete[] promedios;
    codigo=codNuevo;
    promedios=promNuevo;
    n=j; 
}       


int main (){

    int* codigo = new int [100];
    float* promedios = new float [100];
    int n=3;
    int capacidad=3;    

    agregarDuplicar(codigo,promedios,n,capacidad);
    
    cout<<"\nEstudiantes registrados:"<<endl;
    for (int i=0; i<n; i++){
        cout<<"Codigo: "<<codigo[i]<<" Promedio: "<<promedios[i]<<endl;
    }
    eliminarDesaprobados(codigo,promedios,n);
    cout<<"\nFiltrando estudiantes desaprobados..."<<endl;

    cout<<"\nEstudiantes aprobados:"<<endl;
    for (int i=0; i<100; i++){
        if (promedios[i]>=10){
            cout<<"Codigo: "<<codigo[i]<<" Promedio: "<<promedios[i]<<endl;
        }
    }       

    return 0;
}