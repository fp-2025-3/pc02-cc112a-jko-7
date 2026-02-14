#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

struct Producto
{
    int codigo;
    char* nombre;
    double precio;  // cadena dinámica
    int stock;
};

Producto crearProducto(int codigo, const char* nombre, double precio, int stock){
    
    int len = strlen(nombre);
    char* nombreCopia = new char[len + 1];
    strcpy(nombreCopia, nombre);

    Producto p;
    p.codigo = codigo;
    p.nombre = nombreCopia;
    p.precio = precio;
    p.stock = stock;

    return p;           

}

Producto* crearInventario(int n){
    
    Producto* inventario = new Producto[n];

    for (int i=0; i<n; i++){
        inventario[i] = crearProducto(i+1, "Producto", 10.0, 5);
    }

    return inventario;

}

Producto* buscarProducto(Producto* inventario, int n, int codigoBuscado){

    for (int i=0; i<n; i++){
        if (inventario[i].codigo == codigoBuscado){
            return &inventario[i];
        }
    }   
    return nullptr;
}

void liberarInventario(Producto* inventario, int n){
    // liberar memoria

    for (int i=0; i<n; i++){
        delete[] inventario[i].nombre;
    }
    delete[] inventario;    


}


int main (){
    int n = 3;
    Producto* inventario = crearInventario(n);      

    for (int i=0; i<n; i++){
        cout << "Codigo: " << inventario[i].codigo << ", Nombre: " << inventario[i].nombre << ", Precio: " << inventario[i].precio << ", Stock: " << inventario[i].stock << endl;
    }   



    return 0;
}