#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
using namespace std;

int guardaDirecciones (char* texto, char** indice){

    int i=0;
    char* p=texto;
    
    while (*p!='\0'){
        
        if ((p==texto && *p!=' ') || (*(p-1)==' ' && *p!=' ')){
            *(indice+i)=p;
            i++;
        }
        p++;    
    }       
    return i;
}

int comparar (const char* a, const char* b){
    
    while (*a!=' '&& *a!='\0' && *b!=' '&& *b!='\0'){
        if (*a != *b){
            return *a-*b;
        }
        a++;
        b++;
    }
    return *a-*b;
}

void ordenarIndice (char** indice, int n){

    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (comparar(*(indice+i), *(indice+j))>0){
                swap (*(indice+i), *(indice+j));
            }
        }
    }
}

void imprimir (char* texto, char** indice, int n){
    
    for (int i=0; i<n; i++){
        char* p=*(indice+i);

        int pos=0;
        while (*p!=' ' && *p!='\0'){
            cout<<*p;
            p++;
            pos++;
        }

        cout<<setw(16-pos)<<" "<<"(posicion "<<*(indice+i)-texto<<") ";

        cout<<endl;
    }   
}

int main (){

    char texto[] = "los punteros no se copian se referencian y se ordenan";
    char* indice[20];

    int n=guardaDirecciones (texto, indice);

    ordenarIndice (indice, n);
    imprimir (texto, indice, n);

    return 0;
}