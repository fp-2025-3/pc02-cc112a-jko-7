#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
#include <string>
using namespace std;

// Definición de la clase base
class Vehiculo
{
private:
    // miembros datos
    string placa;
    string marca;
    int anio;
    double precioVenta;

public:
    // Funciones miembro
    // Constructores
    Vehiculo();     // Constructores por defecto
    Vehiculo(string p, string m, int a, double pv);

    // Destructor
    ~Vehiculo();
};


class Automovil: public Vehiculo
{
private:
    double numeroPuertas;

public:
    // Constructores
    Automovil(); //constructor por defecto
    Automovil(string p, string m, int a, double pv, int np);

    ~Automovil();
};

class Camion:public Vehiculo
{
private:
    double capacidad;

public:
    // Constructores
    Camion();   //constructor por defecto
    Camion(string p, string m, int a, double pv, double pt);

    ~Camion();
};

class Motocicleta:public Vehiculo 
{
private:
    double potencia;

public:
    Motocicleta();  //constructor por defecto
    Motocicleta(string p, string m, int a, double pv, double pt);

    ~Motocicleta();
};



