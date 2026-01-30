#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int separar_palabras(char* frase, char* palabras[]){

    int i=0;
    char*p=frase;

    while (*p!='\0'){

        if ((p==frase && *p!=' ') ||(*(p-1)==' ' && *p!=' ')){
            palabras[i]=p;
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


void ordenar(char* palabras[], int n){

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){
            if (comparar(palabras[j],palabras[j+1])>0){
                swap (palabras[j],palabras[j+1]);
            }
        }
    }
}

void imprimir(char* palabras[], int n){

    for (int i=0; i<n; i++){

        char* p=palabras[i];

        while (*p!='\0' && *p!=' '){
            cout<<*p;
            p++;
        }
        cout<<endl;
    }
}

int main (){

    char frase[200] = "aprender punteros exige mucha logica y practica";

    char* palabras[50];  // arreglo de punteros a palabras

    int n=separar_palabras(frase, palabras);
    ordenar (palabras, n);
    imprimir (palabras, n);   

    return 0;
}