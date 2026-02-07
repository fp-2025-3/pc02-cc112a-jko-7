#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;

void leerCorredores (char nombres[100][100], int tiempoLlegada[], int &N){
    cout<<"Ingrese numero de corredores: ";
    cin>>N;     
    for (int i=0; i<N; i++){
        cout<<"Nombre del corredor "<<i+1<<": ";
        cin>>nombres[i];
        
        cout<<"Tiempo (en segundos): ";
        cin>>tiempoLlegada[i];
    }
}

void ordenarRanking (char nombres[100][100], int tiempoLlegada[], int N){
    for (int i=0; i<N-1; i++){
        for (int j=0; j<N-i-1; j++){
            if (tiempoLlegada[j]>tiempoLlegada[j+1]){
                
                swap(tiempoLlegada[j],tiempoLlegada[j+1]);  
                swap(nombres[j],nombres[j+1]);      
            }
        }
    }
}       

void mostrarRanking (char nombres[100][100], int tiempoLlegada[], int N){
    cout<<"\nRANKING FINAL:"<<endl;
    for (int i=0; i<5 && i<N; i++){
        cout<<i+1<<". "<<nombres[i]<<" - "<<tiempoLlegada[i]<<" segundos"<<endl;
    }
}       

void buscarNombre (char nombres[100][100], int tiempoLlegada[], int N){
    char nombreBuscado[100];
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

void tiempoRango (char nombres[100][100], int tiempoLlegada[], int N){
    int t1,t2;
    cout<<"\nIngrese tiempo minimo y maximo: ";
    cin>>t1>>t2;
    cout<<"Corredores en el rango ["<<t1<<", "<<t2<<"]:"<<endl;
    for (int i=0; i<N; i++){
        if (tiempoLlegada[i]>=t1 && tiempoLlegada[i]<=t2){
            cout<<nombres[i]<<" - "<<tiempoLlegada[i]<<" segundos"<<endl;
        }
    }
}       

int main (){

    int N;

    char nombres[100][100];
    int tiempoLlegada[100];

    leerCorredores(nombres,tiempoLlegada,N);    
    ordenarRanking(nombres,tiempoLlegada,N); 
    mostrarRanking(nombres,tiempoLlegada,N);
    buscarNombre(nombres,tiempoLlegada,N);
    tiempoRango(nombres,tiempoLlegada,N);              

    return 0;
}