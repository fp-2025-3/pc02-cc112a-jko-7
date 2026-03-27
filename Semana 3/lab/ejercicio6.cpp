#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Función para ordenar letras de una palabra
void ordenarLetras(char* palabra, char* ordenada) {
    strcpy(ordenada, palabra);
    int n = strlen(ordenada);
    
    // Ordenamiento burbuja
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(ordenada[j] > ordenada[j+1]) {
                swap (ordenada[j], ordenada[j+1]);
            }
        }
    }
}

// Función para verificar si son anagramas
int esAnagrama(char* palabra1, char* palabra2) {
    char ord1[100], ord2[100];
    
    // Convertir TODA la palabra a minúsculas
    for(int i = 0; palabra1[i] != '\0'; i++) {
        palabra1[i] = tolower(palabra1[i]);
    }
    for(int i = 0; palabra2[i] != '\0'; i++) {
        palabra2[i] = tolower(palabra2[i]);
    }
    
    // Ordenar ambas palabras
    ordenarLetras(palabra1, ord1);
    ordenarLetras(palabra2, ord2);
    
    // Comparar si son iguales
    if(strcmp(ord1, ord2) == 0) {
        return 1;  // Son anagramas
    }
    return 0;  // No son anagramas
}

int main() {
    char palabra1[100], palabra2[100];
    
    cout << "Ingrese la primera palabra: ";
    cin >> palabra1;
    
    cout << "Ingrese la segunda palabra: ";
    cin >> palabra2;
    
    if(esAnagrama(palabra1, palabra2)) {
        cout << "1" << endl;  // Son anagramas
    } else {
        cout << "0" << endl;  // No son anagramas
    }
    
    return 0;
}