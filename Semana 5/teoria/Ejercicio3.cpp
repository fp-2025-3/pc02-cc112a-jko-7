#include <iostream>
using namespace std;

// ESTRUCTURA AUTOREFERENCIADA
struct Producto
{
    int codigo;
    float precio;
    Producto* sig;
};

int main (){

    Producto* cabeza = nullptr; 

    // Insertar producto al inicio
    for (int i=0; i<2; i++){
        Producto* nuevo = new Producto;

        cout<<"Ingrese codigo del producto: ";
        cin>>nuevo->codigo;
        cout<<"Ingrese precio del producto: ";
        cin>>nuevo->precio;

        nuevo->sig = cabeza;
        cabeza = nuevo;
    }

    // Mostrar los productos
    Producto* aux = cabeza;

    while (aux != nullptr){
        cout<<aux->codigo<<" "<<aux->precio<<endl;
        aux = aux->sig;
    }

    // Liberar memoria
    while (cabeza != nullptr){
        Producto* temp = cabeza;
        cabeza = cabeza->sig;
        delete temp;
    }
    
    return 0;
}
