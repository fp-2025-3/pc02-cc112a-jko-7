#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main (){

    ifstream archivoEntrada("input/notas.txt");

    if (!archivoEntrada){
        cout << "Error no se abrio correctamente archivoEntrada" << endl;
        return 1;
    }

    ofstream archivoSalida("output/reporteAlumnos.txt");

    if (!archivoSalida)
    {
        cout << "Error no se abrio correctamente archivoSalida" << endl;
        return 1;
    }

    int totaldeEstudiantes=0;
    float promedioGeneral=0;
    float suma=0;
    float estudianteMayorPromedio=-999;
    float estudianteMenorPromedio=999;
    int codigo;
    string condicion;
    string nombre;
    string nombreMayorPromedio, nombreMenorPromedio;  // agregando nombre y codigo
    int codigoMayorPromedio, codigoMenorPromedio;
    float n1,n2,n3;
    
    while(archivoEntrada>>codigo>>nombre>>n1>>n2>>n3){

        totaldeEstudiantes++;
        float promedio=(n1+n2+n3)/3;
        suma+=promedio;

        if (promedio>estudianteMayorPromedio){
            estudianteMayorPromedio=promedio;
            nombreMayorPromedio=nombre;
            codigoMayorPromedio = codigo;
        }

        if (promedio<estudianteMenorPromedio){
            estudianteMenorPromedio=promedio;
            nombreMenorPromedio=nombre;
            codigoMenorPromedio=codigo;
        }

        if (n1<5 || n2<5 || n3<5){
            condicion="DESAPROBADO POR REGLA ACADEMICA";
        } else if (promedio>=10){
            condicion="APROBADO";
        } else {
            condicion="DESAPROBADO";
        }

        archivoSalida<<codigo<<" "<<nombre<<" "<<fixed<<setprecision(2)<<promedio<<" "<<condicion<<endl;

    }

    // agregamos una validacion
    if (totaldeEstudiantes>0){
        promedioGeneral=suma/totaldeEstudiantes;
    }
    
    
    archivoSalida<<"\nTotal de estudiantes: "<<totaldeEstudiantes<<endl;
    archivoSalida<<"Promedio general del curso: "<<promedioGeneral<<endl;
    archivoSalida<<"Estudiante con mayor promedio: "<<endl;
    archivoSalida<<codigoMayorPromedio<<" "<<nombreMayorPromedio<<" "<<estudianteMayorPromedio<<endl;
    archivoSalida<<"Estudiante con menor promedio: "<<endl;
    archivoSalida<<codigoMenorPromedio<<" "<<nombreMenorPromedio<<" "<<estudianteMenorPromedio<<endl;

    archivoEntrada.close();
    archivoSalida.close();

    return 0;
}