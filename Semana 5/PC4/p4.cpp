#include <iostream>
#include <cstring>
using namespace std;

struct Item
{
    char* descripcion;
    int cantidad;
    double precioUnitario;
};

struct Pedido
{
    int numeroPedido;
    char* nombreCliente;
    Item* items;
    int cantidadItems;
};

Item crearItem(const char* descripcion, int cantidad, double precio){
    Item item;

    // Reservar memoria dinamica para la descripción
    item.descripcion  = new char[strlen(descripcion)+1];
    strcpy (item.descripcion, descripcion);

    item.cantidad = cantidad;
    item.precioUnitario = precio;

    return item;
}

Pedido* crearPedido(int numero, const char* cliente, int cantidadItems){
    // Reservar memoria dinamica para el pedido
    Pedido* p = new Pedido;

    p->numeroPedido = numero;
    p->cantidadItems = cantidadItems;

    // Reservar memoria para nombreCliente
    p->nombreCliente = new char[strlen(cliente)+1];
    strcpy(p->nombreCliente, cliente);

    // Reservar un arreglo dinamico Item
    p->items = new Item[cantidadItems];

    return p;
}

double calcularTotal(const Pedido* p){

    double total=0;

    for (int i=0; i<p->cantidadItems; i++){
        total+=p->items[i].cantidad * p->items[i].precioUnitario;
    }

    return total;
}

Item* itemMasCaro(Pedido* p){

    if (p->cantidadItems==0){
        return nullptr;
    }

    int indice=0;

    for (int i=0; i<p->cantidadItems; i++){
        if (p->items[i].precioUnitario > p->items[indice].precioUnitario){
            indice=i;
        }
    }

    return &(p->items[indice]);
}

void liberarPedido(Pedido* p){
    
    for (int i=0; i<p->cantidadItems; i++){
        delete[] p->items[i].descripcion;
    }

    delete[] p->items;
    delete[] p->nombreCliente;
    delete p;
}

int main (){

    Pedido* pedido = crearPedido(101, "Carlos Perez", 3);

    pedido->items[0] = crearItem("Laptop", 1, 100);
    pedido->items[1] = crearItem("Mouse", 2, 200);
    pedido->items[2] = crearItem("Teclado", 3, 300);

    cout<<"Pedido N°: "<<pedido->numeroPedido<<endl;
    cout<<"Cliente: "<<pedido->nombreCliente<<endl;

    cout<<"\nItems:"<<endl;
    for (int i=0; i<pedido->cantidadItems; i++){
        cout<<"- "<<pedido->items[i].descripcion
            <<" | Cant: "<<pedido->items[i].cantidad
            <<" | Precio: "<<pedido->items[i].precioUnitario<<endl;
    }

    cout<<"\nTotal: "<<calcularTotal(pedido)<<endl;
    Item* caro = itemMasCaro(pedido);
    cout<<"\nItem mas caro: "<<caro->descripcion<<" | Precio: "<<caro->precioUnitario<<endl;  

    liberarPedido(pedido);

    return 0;
}