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
        cout << "Error no se abrio correctamente el archivo" << endl;
        return 1;
    }

    Empleado emp;

    int idEmpleado;
    int nuevoSalario;
    int posicion=0;

    cout<<"Ingrese ID de empleado: ";
    cin>>idEmpleado;

    while (archivo.read((char*)&emp, sizeof(Empleado)))
    {
        if (idEmpleado == emp.id)
        {
            cout<<"\n--- DATOS DEL EMPLEADO ---"<<endl;
            cout<<"ID: "<<emp.id<<endl;
            cout<<"Nombre: "<<emp.nombre<<endl;
            cout<<"Salario: "<<emp.salario<<endl;

            break;
        }
        posicion++;
    }

    if (idEmpleado != emp.id)
    {
        cout<<"ID invalido."<<endl;
        return 1;
    }

    cout<<"\nIngrese nuevo salario: ";
    cin>>nuevoSalario;

    emp.salario=nuevoSalario;
    archivo.seekp(posicion*sizeof(Empleado), ios::beg);
    archivo.write((char*)&emp, sizeof(Empleado));       

    cout<<"\nSalario actualizado correctamente."<<endl;     

    return 0;
}