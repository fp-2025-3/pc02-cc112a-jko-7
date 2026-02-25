#include "Libro.h"

int main (){

    Libro libro1("El principito", "Antoine", 100);

    Libro libro2("Don Quijote", "Cervantes", 800);

    libro1.mostrarInfo();

    libro1.setPaginas(400);

    libro1.mostrarInfo();


    return 0;
}