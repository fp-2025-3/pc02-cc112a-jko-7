/* 
Ejercicio 2
Implementar una agenda de contactos.
Cada contacto tiene nombre y fecha de nacimiento (estructura Fecha)
La cantidad de contactos es desconocida:

a) Reservar memoria dinámica para N contactos
b) Leer datos
c) y mostrar los nacidos en un año específico

*/

#include <iostream>
#include <string>
using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int anio;
};


struct Contactos
{
    string nombre;
    Fecha nacimiento;
};

void leerContactos (Contactos* contactos, int n){

    cin.ignore();

    for (int i=0; i<n; i++){
        cout<<"Contacto "<<i+1<<endl;
        cout<<"Nombre: ";
        getline (cin, contactos[i].nombre);
        cout<<"Fecha de nacimiento (Dia/Mes/Anio): ";
        cin>>contactos[i].nacimiento.dia
            >>contactos[i].nacimiento.mes
            >>contactos[i].nacimiento.anio;

        cin.ignore();
    }
}

// En un año especifico
void mostrarContactos (Contactos* contactos, int n){

    int anio;
    cout<<"\nIngrese el anio de nacimiento a buscar: ";
    cin>>anio;

    cout<<"\nResultados: "<<endl;

    for (int i=0; i<n; i++){
        if (contactos[i].nacimiento.anio==anio){
            cout<<"Nombre: "<<contactos[i].nombre<<endl;
            cout<<"Fecha de nacimiento: "<<contactos[i].nacimiento.dia<<"/"
                <<contactos[i].nacimiento.mes<<"/"<<contactos[i].nacimiento.anio<<endl;
        }
    }
}


int main (){    

    int n;
    cout<<"Ingrese numero de contactos: ";
    cin>>n;

    if (n<=0){
        cout<<"Cantidad no valida."<<endl;
        return 1;
    }

    // Reserva memoria dinámica
    Contactos* contactos = new Contactos[n];

    leerContactos (contactos, n);
    mostrarContactos (contactos,n);

    delete[] contactos;

    return 0;
}