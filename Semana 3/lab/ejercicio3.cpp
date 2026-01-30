#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int construir_indice(char* texto, char* indice[]){

    int i=0;
    char* p = texto;

    while (*p!='\0'){

        if ((p==texto && *p!=' ') || (*(p-1)==' ' && *p!=' ')){
            indice[i]=p;
            i++;
        }
        p++;
    }
    return i;        
}

int comparar(const char* a, const char* b){

    int i=0;
    while (a[i]!=' ' && a[i]!='\0' && b[i]!=' ' && b[i]!='\0'){
        if (a[i]!=b[i]){
            return a[i]-b[i];
        }
        i++;
    }
    return a[i]-b[i];
}

void ordenar_indice(char* indice[], int n){

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (comparar(indice[j], indice[j+1])>0){
                swap (indice[j], indice[j+1]);
            }
        }
    }
}

void imprimir_indice(char* texto, char* indice[], int n){

    for (int i=0; i<n; i++){

        char* p=indice[i];

        while (*p!='\0'  && *p!=' '){
            cout<<*p;
            p++;
        }
        
        int posicion = indice [i]-texto;
        cout<<"\t\t(posicion "<<posicion<<")"<<endl;
    }
}

int main (){

    char texto[300] = "los punteros no se copian se referencian y se ordenan";   // arreglo base
    char* indice[60];    // arreglo de punteros a palabras

    int n = construir_indice (texto, indice);
    ordenar_indice (indice, n);
    imprimir_indice (texto, indice, n);

    return 0;
}