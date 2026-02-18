#include <iostream>
#include <fstream>
using namespace std;

int main (){

    ifstream archivoEntrada("input/notas.txt");
    ofstream archivoSalida("output/reporte.txt");

    if (!archivoEntrada || !archivoSalida){
        cout<<"Error no se pudo abrir un archivo"<<endl;
        return 1;
    }

    double nota;
    int count=0;
    double suma=0.0, notaMayor, notaMenor;
    int aprobados=0, desaprobados=0;
    while(archivoEntrada>>nota){
        count++;
        suma+=nota;

        if (count == 1){
            notaMayor = nota;
            notaMenor = nota;
        } else {
            if (nota > notaMayor) {
                notaMayor = nota;
            }

            if (nota < notaMenor) {
                notaMenor = nota;
            }
        }

        if (nota >= 10){
            aprobados++;
        } else {
            desaprobados++;
        }
    }

    double promedio=suma/count;

    archivoSalida<<"REPORTE GENERAL"<<endl;
    archivoSalida<<"-----------------------"<<endl;
    archivoSalida<<"Total estudiantes: "<<count<<endl;
    archivoSalida<<"Promedio: "<<promedio<<endl;
    archivoSalida<<"Mayor nota: "<<notaMayor<<endl;
    archivoSalida<<"Menor nota: "<<notaMenor<<endl;
    archivoSalida<<"Aprobados: "<<aprobados<<endl;
    archivoSalida<<"Desaprobados: "<<desaprobados<<endl;

    archivoSalida.close();
    archivoEntrada.close();

    return 0;
}