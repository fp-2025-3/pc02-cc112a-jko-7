
// 
#include <iostream>
using namespace std;

int main (){

    char nombre[10];
    cout<<"Ingresa tu nombre: ";
    cin>>nombre;  // Lee una palabra (hasta el primer espacio) 
                  // pero no puede leer nombres compuestos
                 // El código puede detener el programa sin avisar
    

    cout<<"Hola "<<nombre<<endl; // Imprime la Hola y el primer espacio 
    cin.ignore();  // Limpia el buffer de entrada

    char nombre2[50];  //Lee hasta 49 caracteres
    cout<<"Ingresa tu nombre completo: ";
    cin.getline (nombre2, 49); // Lee una linea completa hasta el salto
    cout<<"Hola "<<nombre2<<endl;

    int edad;
    cout<<"Ingrese su edad: ";
    cin>>edad;  // Lee un número entero

    cin.ignore(); 

    char nombre3[50];
    cout<<"Ingrese su nombre completo: "<<endl;
    cin.getline (nombre3, 50); // Lee una linea completa hasta el salto
    cout<<"Hola "<<nombre3<<", tienes "<<edad<<" años."<<endl;

    return 0;
}