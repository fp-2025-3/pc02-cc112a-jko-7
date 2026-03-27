#include <iostream>
#include <fstream>
using namespace std;

struct Alumno
{
    string apellido;
    string nombre;
    int nota;
};

int main(){

    ifstream archivoEntrada ("input/Entrada.csv");
    ofstream archivoSalida ("output/Salida.csv");

    if (!archivoEntrada) {
        cout<<"No se pudo abrir el archivoEntrada"<<endl;
        return 1;
    }

    if (!archivoSalida) {
        cout<<"No se pudo abrir el archivoSalida"<<endl;
        return 1;
    }

    Alumno alumnos[100];
    int n=0;

    char coma;

    while (getline(archivoEntrada, alumnos[n].apellido, ',')) {

        getline(archivoEntrada, alumnos[n].nombre, ',');
        archivoEntrada >> alumnos[n].nota;

        alumnos[n].nota += 2; 

        archivoEntrada.get(coma); 

        n++;
    }

    archivoEntrada.close();

    // Ordenamiento burbuja
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1-i; j++) {

            if (alumnos[j].apellido > alumnos[j+1].apellido){
                swap(alumnos[j], alumnos[j+1]);
            } else if (alumnos[j].apellido == alumnos[j+1].apellido) {
                if (alumnos[j].nombre > alumnos[j+1].nombre){
                    swap(alumnos[j], alumnos[j+1]);
                } else if (alumnos[j].nombre == alumnos[j+1].nombre) {
                    if (alumnos[j].nota > alumnos[j+1].nota){
                        swap(alumnos[j], alumnos[j+1]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        archivoSalida<<alumnos[i].apellido<< ","
                     <<alumnos[i].nombre << ","
                     <<alumnos[i].nota << endl;
    }

    archivoSalida.close();

    return 0;
}