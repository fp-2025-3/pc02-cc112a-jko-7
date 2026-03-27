#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CORREDORES = 30; // Máximo 30 corredores
const int MAX_NOMBRE = 21; // 20 caracteres + '\0'

void leerCorredores (char nombres[][MAX_NOMBRE], int tiempoLlegada[], int &N){
    do {
        cout<<"Ingrese numero de corredores: ";
        cin>>N; 

        if (N<1 || N>MAX_CORREDORES){
            cout<<"Error: debe ingresar entre 1 y "<<MAX_CORREDORES<<" corredores."<<endl;
        }
    } while (N<1 || N>MAX_CORREDORES);
        
    for (int i=0; i<N; i++){
        cout<<"Nombre del corredor "<<i+1<<": ";
        cin>>nombres[i];
        
        do {
            cout<<"Tiempo (en segundos): ";
            cin>>tiempoLlegada[i];

            if (tiempoLlegada[i]<=0){
                cout<<"Error: el tiempo debe ser positivo."<<endl;
            }
        } while (tiempoLlegada[i]<=0);        
    }
}

void ordenarRanking (char nombres[][MAX_NOMBRE], int tiempoLlegada[], int N){
    for (int i=0; i<N-1; i++){
        for (int j=0; j<N-i-1; j++){
            if (tiempoLlegada[j]>tiempoLlegada[j+1]){
                swap(tiempoLlegada[j],tiempoLlegada[j+1]);  
                swap(nombres[j], nombres[j+1]);
            }
        }
    }
}       

void mostrarRanking (char nombres[][MAX_NOMBRE], int tiempoLlegada[], int N){
    cout<<"\nRANKING FINAL:"<<endl;
    for (int i=0; i<N; i++){
        cout<<i+1<<". "<<nombres[i]<<" - "<<tiempoLlegada[i]<<" segundos"<<endl;
    }
}       

void buscarNombre (char nombres[][MAX_NOMBRE], int tiempoLlegada[], int N){
    char nombreBuscado[MAX_NOMBRE];
    cout<<"\nIngrese nombre a buscar: ";
    cin>>nombreBuscado;

    bool encontrado=false;
    for (int i=0; i<N; i++){
        if (strcmp(nombres[i],nombreBuscado)==0){
            cout<<"Corredor encontrado"<<endl;
            cout<<"Posicion: "<<i+1<<endl;
            cout<<"Tiempo: "<<tiempoLlegada[i]<<" segundos"<<endl;
            encontrado=true;
            break;
        }
    }

    if (!encontrado){
        cout<<"Error: corredor no encontrado."<<endl;
    }       
}       

void tiempoRango (char nombres[][MAX_NOMBRE], int tiempoLlegada[], int N){
    int tmin,tmax;
    cout<<"\nIngrese tiempo minimo y maximo: ";
    cin>>tmin>>tmax;

    cout<<"Corredores en el rango ["<<tmin<<", "<<tmax<<"]:"<<endl;
    bool hayresultados = false;

    for (int i=0; i<N; i++){
        if (tiempoLlegada[i]>=tmin && tiempoLlegada[i]<=tmax){
            cout<<nombres[i]<<" - "<<tiempoLlegada[i]<<" segundos"<<endl;
            hayresultados = true;
        }
    }

    if (!hayresultados){
        cout<<"No hay corredores en ese rango."<<endl;
    }
}       

int main (){

    int N;

    char nombres[MAX_CORREDORES][MAX_NOMBRE];
    int tiempoLlegada[MAX_CORREDORES];

    leerCorredores(nombres,tiempoLlegada,N);    
    ordenarRanking(nombres,tiempoLlegada,N); 
    mostrarRanking(nombres,tiempoLlegada,N);
    buscarNombre(nombres,tiempoLlegada,N);
    tiempoRango(nombres,tiempoLlegada,N);              

    return 0;
}