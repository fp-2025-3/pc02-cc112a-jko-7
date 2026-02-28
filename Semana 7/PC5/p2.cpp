#include <iostream>
#include <fstream>
using namespace std;

struct Empleado
{
    int id;  // comienza en 1
    char nombre[30];
    double salario;
};

int main(){

    fstream archivo("input/empleados.dat", ios::in | ios::out | ios::binary);

    if (!archivo){
        cout << "Error no se abrio correctamente el archivo." << endl;
        return 1;
    }

    Empleado emp;
    int idEmpleado;
    double nuevoSalario;

    cout<<"Ingrese ID de empleado: ";
    cin>>idEmpleado;

    // Calcular posición directamente
    int posicion=(idEmpleado-1)*sizeof(Empleado);
    archivo.seekg(posicion, ios::beg);

    if (!archivo.read((char*)&emp, sizeof(Empleado)) || emp.id != idEmpleado){
        cout << "ID inválido o no encontrado." << endl;
        return 1;
    }

    cout<<"\n--- DATOS DEL EMPLEADO ---"<<endl;
    cout<<"ID: "<<emp.id<<endl;
    cout<<"Nombre: "<<emp.nombre<<endl;
    cout<<"Salario: "<<emp.salario<<endl;

    cout<<"\nIngrese nuevo salario: ";
    cin>>nuevoSalario;

    emp.salario=nuevoSalario;

    archivo.seekp(posicion, ios::beg);
    archivo.write((char*)&emp, sizeof(Empleado));       

    cout<<"\nSalario actualizado correctamente."<<endl;   
    
    archivo.close();

    return 0;
}