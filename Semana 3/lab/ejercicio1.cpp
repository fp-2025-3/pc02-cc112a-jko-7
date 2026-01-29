#include <iostream>
using namespace std;

int separar_palabras(char* texto, char* palabras[]){
    int i=0;

    char* p=texto; //almacena la direccion del primer caracter

    while (*p!='\0'){
        if ((p==texto && *p!=' ') || (*(p-1)=='\0' && *p!=' ')){
            palabras[i]=p;
            i++;
        }
        if (*p==' '){
            *p='\0';
        }
        p++;
    }

    return i;
}
 
int longitud_palabra(const char* p){

    int longitud=0;
    while (*p!='\0' && *p!=' '){
        longitud++;
        p++;
    }

    return longitud;
}

void clasificar(char* palabras[], int n,
                char* cortas[], int& nc,
                char* largas[], int& nl){

    // recorrer el arreglo de punteros palabras
    // clasificar segun su longitud
    
    nc=0;
    nl=0;
    for (int i=0; i<n; i++){
        if (longitud_palabra(palabras[i])<=3){
            cortas[nc]=palabras[i];
            nc++;
        }
        else{
            largas[nl]=palabras[i];
            nl++;
        }
    }
}

int comparar_palabras(const char* a, const char* b){

    // se usa la funcion comparar_palabras porque strcmp 
    // al compara hay hay problemas con los espacios en blanco

    int i=0;


    while (a[i]!='\0' && b[i]!='\0'){
    
        if (a[i]!=b[i]){
            return a[i]-b[i];
        }
        i++;
    }
    return a[i]-b[i];
}

void ordenar(char* v[], int n){

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (comparar_palabras(v[j], v[j+1])>0){
                swap (v[j], v[j+1]);
            }
        }
    }
}

void imprimir_grupo(const char* titulo, char* v[], int n){

    cout<<"Palabras "<<titulo<<endl;

    for (int i=0; i<n; i++){
        cout<<v[i]<<endl;
    }
    cout<<endl;
}

int main (){

    char texto[300]="Programar en C++ requiere logica C++ exige disciplina";
    char* palabras[60];
    char* cortas[60];
    char* largas[60];

    cout<<"Texto: ";
    cout<<texto<<endl;

    int n=separar_palabras(texto, palabras);
    int nc, nl; 
    clasificar(palabras, n, cortas, nc, largas, nl);
    ordenar(cortas, nc);
    imprimir_grupo("cortas:", cortas, nc);

    ordenar(largas, nl);
    imprimir_grupo("largas:", largas, nl);
    

    return 0;
}