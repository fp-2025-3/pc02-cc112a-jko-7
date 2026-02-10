#include <iostream>
#include <cmath>
#include <string>      
using namespace std;

struct Estudiante
{
    string curso;
    string nombre;
    float* notas;
};

int main (){

    int n,m;

    cout<<"Ingrese la cantidad de estudiantes: ";
    cin>>n;

    cout<<"Ingrese la cantidad de notas: ";
    cin>>m;

    cin.ignore ();

    Estudiante* estudiante = new Estudiante[n];

    for (int i=0; i<n; i++){
        cout<<"Estudiante "<<i+1<<": "<<endl;
        cout<<"Nombre: ";
        getline (cin, estudiante[i].nombre);
        cout<<"Curso: ";
        getline (cin, estudiante[i].curso);

        estudiante[i].notas = new float[m];

        for (int j=0; j<m; j++){
            cout<<"Nota "<<j+1<<": ";
            cin>>estudiante[i].notas[j];
        }        

        cin.ignore ();
    }

    cout<<"\n=======PROMEDIOS FINALES========="<<endl;
    for (int i=0; i<n; i++){
        float suma=0;
        
        for (int j=0; j<m; j++){
            suma+=estudiante[i].notas[j];    
        }

        float promedio=round(suma/m);
        cout<<"El alumno "<<estudiante[i].nombre<<" en el curso "
            <<estudiante[i].curso<<" tiene promedio "<<promedio<<endl;
    }

    for (int i=0; i<n; i++){
        delete[] estudiante[i].notas;   // Borra las notas de cada uno
    }

    delete [] estudiante;   // Borra el arreglo de estudiantes

    return 0;
}