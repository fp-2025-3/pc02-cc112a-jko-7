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
        Producto* nuevo = new Producto[i];
        cout<<"Ingrese codigo del producto: ";
        cin>>nuevo->codigo;
        cout<<"Ingrese precio del producto: ";
        cin>>nuevo->precio;
        nuevo->sig=cabeza;
        cabeza=nuevo;
    }

    // Mostrar los productos
    Producto* aux = cabeza;

    while (aux != nullptr){
        cout<<aux->codigo<<" "<<aux->precio<<endl;
        aux = aux->sig;
    }

    while (cabeza != nullptr){
        Producto temp = cabeza;
        cabeza->
        delete temp;
    }


        cout<<"\nCodigo del producto: ";
        cout<<cabeza->codigo<<endl;
        cout<<"Precio del producto: ";
        cout<<cabeza->precio<<endl;
        cout<<"Codigo del producto: ";
        cout<<cabeza->sig->codigo<<endl;
        cout<<"Precio del producto: ";
        cout<<cabeza->sig->precio<<endl;
    
    

    // Liberar memoria


    

    return 0;
}
