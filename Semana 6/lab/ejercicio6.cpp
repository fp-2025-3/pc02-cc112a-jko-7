#include <iostream>
#include <fstream>
using namespace std;

struct Empleado
{
    int id;
    char nombre[50];
    float salario;
};

// Crear e inicializar el archivo binario con 8 empleados
void crearArchivo(){

    ofstream archivo("output/empleados.bin", ios::binary);

    if (!archivo) {
        cout << "Error al crear el archivo." << endl;
        return;
    }

    Empleado empleados[8] = {
        {1,"Empleado A",3000},
        {2,"Empleado B",4000},
        {3,"Empleado C",3500},
        {4,"Empleado D",4500},
        {5,"Empleado E",3200},
        {6,"Empleado F",3800},
        {7,"Empleado G",4200},
        {8,"Empleado H",3900}
    };

    // Escribimos los 8 empleados
    archivo.write((char*)&empleados, sizeof(Empleado)*8);
    archivo.close();
}

// Mostrar todos los empleados del archivo
void mostrarEmpleados(){

    ifstream archivo("output/empleados.bin", ios::binary);

    if (!archivo) {
        cout << "Error al crear el archivo." << endl;
        return;
    }

    Empleado emp;
    cout<<"Informacion de los empleados"<<endl;

    // Leer de uno en uno hasta el final del archivo
    while (archivo.read((char*)&emp, sizeof(Empleado))){
        cout<<"ID: "<<emp.id<<", Nombre: "<<emp.nombre
            <<", Salario: $"<<emp.salario<<endl;
    }

    archivo.close();
}

void buscarPorRango(){

    ifstream archivo("output/empleados.bin", ios::binary);

    if (!archivo) {
        cout << "Error al crear el archivo." << endl;
        return;
    }

    float salarioMinimo,salarioMaximo;
    cout<<"Ingrese el salario minimo: $";
    cin>>salarioMinimo;
    cout<<"Ingrese el salario maximo: $";
    cin>>salarioMaximo;

    cout<<"\nInformación de los empleados en el rango de salarios: $"
        <<salarioMinimo<<" - $"<<salarioMaximo<<endl;

    Empleado emp;
    bool encontrado = false;
    
    while (archivo.read((char*)&emp, sizeof(Empleado))) {
        if (emp.salario>=salarioMinimo && emp.salario<=salarioMaximo) {
            cout <<"ID: "<<emp.id
                 <<", Nombre: "<<emp.nombre
                 <<", Salario: $"<<emp.salario << endl;
            encontrado = true;
        } 
    }

    if (!encontrado){
        cout << "No se encontraron empleados en ese rango." << endl;
    }

    archivo.close();
}

int main (){

    crearArchivo();
    mostrarEmpleados();
    buscarPorRango();

    return 0;
}