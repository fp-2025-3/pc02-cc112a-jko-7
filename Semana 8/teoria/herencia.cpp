#include <iostream>
using namespace std;

// Clase base
class Vehiculo
{
protected:      // para tener acceso a los datos desde clases derivadas
    int ruedas;
    string color;
    
public:
    // constructor
    Vehiculo(int r, string c): ruedas(r), color(c) {}

    // mostrar información
    void mostrarInfo(){
        cout<<"Numero de ruedas del vehiculo: "<<ruedas<<endl;
        cout<<"Color del vehiculo: "<<color<<endl;
    }

    // Destructor
    ~Vehiculo(){
        cout<<"Destructor vehiculo: "<<endl;
    }
};

// Clase derivada Coche
class Coche:public Vehiculo
{
private:
    int numeroPuertas;    

public:
    // constructor
    Coche(int r, string c, int np): Vehiculo(r,c), numeroPuertas(np){}

    // Metodo especifico para Coche
    void mostrarCoche(){
        cout<<"Numero de puertas del Coche: "<<numeroPuertas<<endl;
        cout<<"Color del Coche: "<<color<<endl;
        cout<<"Numero de ruedas del Coche: "<<ruedas<<endl;
    }

    ~Coche(){
        cout<<"Destructor Coche"<<endl;
    }
};

// Clase derivada Motocicleta
class Moto:public Vehiculo
{
private:
    bool concasco;

public:
    // constructor
    Moto(int r, string c, bool casco): Vehiculo(r,c), concasco(casco){}
    
    // Metodo especifico para Moto
    void mostrarMoto(){
        cout<<"Numero de ruedas de la Moto: "<<ruedas<<endl;
        cout<<"Color del Moto: "<<color<<endl;
        cout<<"Tiene casco Moto: "<<concasco<<endl;
    }

    ~Moto(){
        cout<<"Destructor Moto"<<endl;
    }
};

int main (){

    // Instanciar un objeto de la clase base
    Vehiculo v1(4, "Azul");
    v1.mostrarInfo();

    Coche c1(4, "Rojo", 4);
    c1.mostrarCoche();

    Moto m1(2, "Negro",true);
    m1.mostrarMoto();

    return 0;
}