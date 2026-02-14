#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <cmath>
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


Pedido* crearPedido(int numero, const char* cliente, int cantidadItems){
    // Reservar memoria dinamica para un pedido
    // Reservar memoria para nombreCliente
    // Reservar un arreglo dinamico Item
    // Inicializar los item llamando a una funcion

}

Item crearItem(const char* descripcion, int cantidad, double precio){
    
}


double calcularTotal(const Pedido* p){
    // total = sumatoria de cantidad * precioUnitario


}

Item* itemMasCaro(Pedido* p){
    // debe retornar un puntero al item con mayor precio unitario

}

void liberarPedido(Pedido* p){
    // liberar memoria

}


int main (){





    return 0;
}