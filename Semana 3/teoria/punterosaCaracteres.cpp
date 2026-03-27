#include <iostream>
using namespace std;

void imprimir (const char* p){

    while (*p != '\0'){  // Mientras no se llegue al caracter nulo
        cout<<*p;        // Imprimir el caracter apuntado por p
        p++;            // <> p=p+1;
        // Avanza al siguiente caracter
    }   

}




int main (){

    // CUIDADO el nombre de un arreglo de caracteres es una constante (const)
    // que almacena la direccion del primer caracter


    char texto[] = "Hola";
    char* p = texto;   // texto es la direccion del primer caracter 'H'
                        // p es un puntero que almacena esa direccion

    char palabra[] = "PERU";
    char* p = palabra;  // p apunta a 'P'
                        
    *(p + 1); // p + 1 apunta a 'E'
             // se avanza 1 byte (sizeof(char) = 1 byte)
             // sumar a un puntero es avanzar posiciones 


    imprimir (p);  // Imprime PERU
    imprimir (texto); // Imprime Hola

    return 0;
}