#include <iostream>
#include <cstring>
using namespace std;

struct Producto
{
    int codigo;
    char* nombre;
    double precio;  
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

    inventario[0] = crearProducto(100, "Teclado", 10.5, 5);
    inventario[1] = crearProducto(101, "Mouse", 21, 10);
    inventario[2] = crearProducto(102, "Monitor", 31.5, 15);
    inventario[3] = crearProducto(103, "Laptop", 42, 20);
    inventario[4] = crearProducto(104, "Impresora", 52.5, 25);

    /*
    Otra forma de ingresar los datos

    int codigos[] = {100, 101, 102, 103, 104};
    const char* nombres[] = {"Teclado", "Mouse", "Monitor", "Laptop", "Impresora"};
    double precios[] = {10.5, 21, 31.5, 42, 52.5};
    int stocks[] = {5, 10, 15, 20, 25};
    
    for(int i = 0; i < n; i++){
        inventario[i] = crearProducto(codigos[i], nombres[i], precios[i], stocks[i]);
    }
    */

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

    for (int i=0; i<n; i++){
        delete[] inventario[i].nombre;
    }
    delete[] inventario;    
}

int main (){
    int n = 5;
    Producto* inventario = crearInventario(n);      

    cout<<"\tINVENTARIO"<<endl;

    for (int i=0; i<n; i++){
        cout<<"Codigo: "<<inventario[i].codigo 
            <<" | Nombre: "<<inventario[i].nombre 
            <<" | Precio: "<<inventario[i].precio 
            <<" | Stock: "<<inventario[i].stock << endl;
    }   

    int codigoBuscar = 102;
    Producto* encontrado = buscarProducto(inventario, n, codigoBuscar);

    cout<<"\nBuscando producto con codigo "<<codigoBuscar<<"..."<<endl;

    if (encontrado!=nullptr){
        cout<<"Producto encontrado: "<<encontrado->nombre
            <<" | Precio: "<<encontrado->precio<<endl;
    } else {
        cout<<"Producto no encontrado."<<endl;
    }
    
    // Liberar memoria
    liberarInventario(inventario, n);

    return 0;
}