#include <iostream>
using namespace std;

// Clase base

// REGLA PRACTICA

// Cada vez que implementemos herencia y polimorfismo
// en clases, usar DESTRUCTORES VIRTUALES

class Animal
{
public:
    virtual void id(){  // no es virtual, enlace estatico
        cout<<"animal"; // siempre se ejecuta este metodo 
    }
    virtual ~Animal(){
        cout<<"destructor Animal"<<endl;
    }
};

// Clases derivadas

class Cat:public Animal // hereda de Animal
{
private:
    virtual void id() override{
        cout<<"cat";
    }

    virtual ~Cat() {
        cout<<"destructor Cat"<<endl;
    }
};

class Dog:public Animal // hereda de Animal
{
private:
    virtual void id() override{
        cout<<"dog";
    }

    virtual ~Dog() {
        cout<<"destructor Dog"<<endl;
    }
};

int main (){

    // Arreglo de punteros tipo Animal 
    // Puede almacenar direcciones de objetos Animal o derivados

    Animal *pA[] = {new Animal, new Dog, new Cat};
    for (int i=0; i<3; i++){
        pA[i]->id();
        cout<<endl;
    }

    // Liberar memoria
    for (int i=0; i<3; i++){
        delete pA[i];
    }
}


