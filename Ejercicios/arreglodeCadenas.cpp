#include <iostream>
using namespace std;

int main (){

    // Arreglo bidimensional de caracteres (forma rigida)
    char paises[3][10] = {
        "Peru",
        "Chile",    
        "Brasil"
    };

    /*
    ¿Qué hay en memoria? 3 filas. cada fila tiene 10 caracteres
    Todas las cadenas tienen longitud máxima fija
    Se desperdicia memoria. No todas las palabras usan las 10 posiciones
    */

    // Arreglo de punteros a char (forma eficiente)
    const char* paises[] = {
        "Peru",
        "Chile",
        "Brasil"
    };

    for (int i = 0; i < 3; i++) {
        const char* p = *(paises + i);
        while (*p != '\0') {
            cout << *p;
            p++;
        }
        cout << endl;
    }
    


    return 0;
}