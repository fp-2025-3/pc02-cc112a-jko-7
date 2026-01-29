#include <iostream>
using namespace std;

int main (){

    char c1 = 'A';
    char c2 = 'a';
    char c3 = '0';

    cout<<(int)c1<<endl;
    cout<<(int)c2<<endl;
    cout<<(int)c3<<endl;

    char x='9';
    if (x>'5'){
        cout<<"Mayor";   // Se comparan codigos ASCII entre caracteres
    }                    // en este caso '9' (57) es mayor que '5' (53)


    return 0;
}

/* 
    ¿Qué valores numéricos se imprimirán?
    65
    97  
    48

    ¿Por qué 'A' y 'a' no tienen el mismo valor?
    Porque las letras mayúsculas y minúsculas tienen diferentes códigos en la tabla ASCII

    ¿Un char es realmente un carácter o un número?
    un char es un número que representa un carácter

    El compilador no ve letras, solo números

    ¿Cuántos bytes ocupa un char en memoria? 
    1 byte 

*/