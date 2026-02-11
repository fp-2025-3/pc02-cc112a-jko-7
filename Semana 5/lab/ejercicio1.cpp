#include <iostream>
using namespace std;

struct Estudiante
{
    string nombre;
    float nota;
};


int main (){

    int n;
    cout << "Ingrese el numero de estudiantes: ";
    cin>>n;

    cin.ignore();

    Estudiante* estudiante = new Estudiante[n];

    float notaMax=0;
    int nombreMax;

    for (int i=0; i<n; i++){
        cout<<"Ingrese el nombre del estudiante "<<i+1<<": ";
        getline(cin, estudiante[i].nombre);

        cout<<"Ingrese la nota del estudiante "<<i+1<<": ";
        cin>>estudiante[i].nota;

        cin.ignore();
    }

    for (int i=0; i<n; i++){
        if (notaMax<estudiante[i].nota){
            notaMax=estudiante[i].nota;
            nombreMax=i;
        }
    }

    cout<<"El estudiante con la mayor nota es: "<<estudiante[nombreMax].nombre<<endl;
    cout<<"Nota: "<<notaMax<<endl;


    return 0;
}