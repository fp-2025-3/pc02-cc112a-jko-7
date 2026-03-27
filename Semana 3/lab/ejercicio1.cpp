#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// NOTA: Esta función modifica el texto (reemplaza espacios con '\0')
// Solo usar si está permitido modificar el texto original
// O hacer copias para no modificar el original
int separar_palabras_strtok(char* texto, char* palabras[]) {

    int i = 0;
    char* token = strtok(texto, " ");

    while (token != nullptr) {
        palabras[i] = token;
        token = strtok(nullptr, " "); // continua analizando la cadena 
        i++;
    }
    return i;
}

// CANTIDAD TOTAL DE PALABRAS ENCONTRADAS
int separar_palabras(char* texto, char* palabras[]){
    int i=0;

    char* p=texto; //almacena la direccion del primer caracter

    while (*p!='\0'){
        if ((p==texto && *p!=' ') || (*(p-1)==' ' && *p!=' ')){
            palabras[i]=p;
            i++;
        }
        p++;
    }
    return i;
}
/*
EJM:
    char texto[] = "Hola mundo en C";
    char* palabras[60];

    int n = separar_palabras(texto, palabras);
    n = 4 (porque hay 4 palabras)

    Ahora palabras[] contiene:
    palabras[0] -> apunta a 'H' de "Hola"
    palabras[1] -> apunta a 'm' de "mundo"
    palabras[2] -> apunta a 'e' de "en"
    palabras[3] -> apunta a 'C'
    palabras[4..59] -> sin usar
*/

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

    // strcmp requiere cadenas terminadas en '\0'
    // Aquí las palabras están separadas por espacios
    // Además, necesitamos ignorar mayúsculas/minúsculas

    int i=0;

    while (a[i]!=' ' && a[i]!='\0' && b[i]!=' ' && b[i]!='\0'){
                                            
        char minus_a = tolower(a[i]);   
        char minus_b = tolower(b[i]);   

        if (minus_a != minus_b){
            return minus_a-minus_b;
        }
        i++;
    }
    return tolower(a[i])-tolower(b[i]);  
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

    cout<<"\nPalabras "<<titulo<<endl;
    for (int i=0; i<n; i++){
        char* p=v[i];

        while (*p!='\0' && *p!=' '){
            cout<<*p;
            p++;
        }
        cout<<endl;
    }
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