#include <iostream>
using namespace std;

// Función para agregar y duplicar si es necesario
void agregarDuplicar (int* &codigo, float* &promedios, int &n, int &capacidad){
    if (n==capacidad){
        capacidad*=2;
        int* codNuevo = new int [capacidad];
        float* promNuevo = new float [capacidad];

        for (int i=0; i<n; i++){
            codNuevo[i]=codigo[i];
            promNuevo[i]=promedios[i];          
        }

        delete[] codigo;
        delete[] promedios;

        codigo = codNuevo;
        promedios = promNuevo;
        
    }   

    cout<<"Ingrese codigo: ";
    cin>>codigo[n];
    cout<<"Ingrese promedio: ";
    cin>>promedios[n];
    n++;
}       

// Función para eliminar y ajustar al tamaño exacto
void eliminarDesaprobados (int* &codigo, float* &promedios, int &n){
    // Contamos cúantos aprobados hay para saber el tamaño exacto
    int aprobados=0;

    for (int i=0; i<n; i++){
        if (promedios[i]>=10){
            aprobados++;
        }
    }
    
    if (aprobados==0){
        delete[] codigo;
        delete[] promedios;
        codigo = nullptr;
        promedios = nullptr;
        n = 0;
        return;
    }


    // Creamos los nuevos arreglos con el tamaño exacto
    int* codNuevo = new int [aprobados];
    float* promNuevo = new float [aprobados];

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
    n=aprobados;  // El nuevo tamaño lógico es igual al número de aprobados
}       


int main (){

    int capacidad = 2;  // Capacidad inicial pequeña para probar el duplicado 
    int n = 0;          // Empezamos con 0 estudiantes

    int* codigo = new int [capacidad];
    float* promedios = new float [capacidad];   

    // Llenar datos 
    for (int i=0; i<5; i++){
        cout<<"Estudiante "<<i+1<<":"<<endl;
        agregarDuplicar(codigo,promedios,n,capacidad);
    }
    
    cout<<"\nEstudiantes registrados:"<<endl;
    for (int i=0; i<n; i++){
        cout<<"Codigo: "<<codigo[i]<<" Promedio: "<<promedios[i]<<endl;
    }

    eliminarDesaprobados(codigo,promedios,n);

    cout<<"\nFiltrando estudiantes desaprobados..."<<endl;
    cout<<"\nEstudiantes aprobados:"<<endl;
    for (int i=0; i<n; i++){
        cout<<"Codigo: "<<codigo[i]<<" Promedio: "<<promedios[i]<<endl;
    }       

    // Limpieza final de memoria
    delete[] codigo;
    delete[] promedios;

    return 0;
}