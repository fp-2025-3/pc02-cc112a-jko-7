#include <iostream>
#include <cstring>
using namespace std;

int my_strlen (const char* str){
    int count = 0;
    while (*str != '\0'){
        count++;
        str++;
    }

    return count;
}

char* my_strcpy (char* destination, const char* source){

    char* ptr = destination; // Guardar la direccion inicial de destination

    while (*source !='\0'){
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0'; // Agregar el caracter nulo al final
    return ptr; // Retornar la direccion inicial de destination
}


char* my_strcat (char* destination, const char* source){

    char* ptr=destination;

    while (*destination != '\0'){
        destination++;
    }

    while (*source != '\0'){
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0'; // Agregar el caracter nulo al final
    return ptr; // Retornar la direccion inicial de destination

}

int my_strcmp (const char* str1, const char* str2){

    while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0'){
        str1++;
        str2++;
    }

    return (*str1 - *str2); // Si ambas son iguales, retorna 0

}


int main (){

    const char* mensaje = "Hola Mundo";
    
    int resultado = my_strlen (mensaje);
    cout<<"La longitud del mensaje es: "<<resultado<<endl;
    cout<<"La longitud del mensaje es: "<<strlen(mensaje)<<endl;


    char destino[50];
    char origen[] = "Programacion";

    strcpy(destino, origen); // Copia "Programacion" a destino
    cout<<"Destino: "<<destino<<endl;

    char destino2[50];
    char origen2[] = "Hola mundo antiguo";
    my_strcpy (destino2, origen2); // Copiamos "Hola mundo antiguo" a destino2
    cout<<"Destino 2: "<<destino2<<endl;


    char a[] = "Hola";
    char b[] = "Hola";


    if (a == b){  // ERROR 
        cout<<"Iguales"<<endl;  // a y b compara direcciones de memoria
    }                           // strcmp compara contenidos
    
    if (strcmp (a, b) == 0){
        cout<<"Iguales"<<endl;
    }
    
    strcat (destino2, destino);
    cout<<"Destino 2 despues de strcat: "<<destino2<<endl;

    my_strcat (destino2, " Mundo");
    cout<<"Destino 2 despues de my_strcat: "<<destino2<<endl;


    int resul2 = strcmp ("abc", "abd"); // Retorna un valor negativo porque 'c' < 'd'
    cout<<"Comparacion abc y abd: "<<my_strcmp("abc", "abc")<<endl; // Retorna 0 porque son iguales
                                                                // Retorna un valor positivo si 'd' > 'c'
    cout<<"Comparacion abd y abc: "<<resul2<<endl;

    // Funciones
    /*
        strlen: calcula la longitud de una cadena de caracteres
        strcpy: copia una cadena de caracteres a otra
        strcat: concatena (une) dos cadenas de caracteres
        strcmp: compara dos cadenas de caracteres
        

    */


    return 0;
}