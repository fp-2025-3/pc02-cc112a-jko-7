#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Vertice      // porque tiene coordenadas (x,y)
{
    double x;
    double y;
};

struct Triangulo
{
    int v1,v2,v3;
};

double calcularArea(Vertice a, Vertice b, Vertice c){

    double area= fabs(a.x*(c.y-b.y)+b.x*(a.y-c.y)+c.x*(b.y-a.y))/2.0;

    return area;
}

int main (){

    ifstream archivoEntrada ("input/lagunas.txt");
    ofstream archivoSalida ("output/area.txt");

    if (!archivoEntrada || !archivoSalida){
        cout<<"Error no se abrio un archivo correctamente."<<endl;
        return 1;
    }

    int nt;      // número de triángulos
    int nv;      // número de vértices

    archivoEntrada>>nt>>nv;

    // crear arreglos dinámicos
    Vertice* vertices = new Vertice[nv];
    Triangulo* triangulos = new Triangulo[nt];

    // leer vertices
    for (int i=0; i<nv; i++){
        archivoEntrada>>vertices[i].x>>vertices[i].y;
    }

    // leer triángulos
    for (int i=0; i<nt; i++){
        archivoEntrada>>triangulos[i].v1>>triangulos[i].v2>>triangulos[i].v3;

        // convertir a índice base 0
        // el archivo usa índices desde 1, el arreglo usa desde 0
        triangulos[i].v1--;
        triangulos[i].v2--;
        triangulos[i].v3--;
    }

    // calcular área total
    double areaTotal=0;

    for (int i=0; i<nt; i++){

        Vertice a = vertices[triangulos[i].v1];
        Vertice b = vertices[triangulos[i].v2];
        Vertice c = vertices[triangulos[i].v3];

        areaTotal+=calcularArea(a,b,c);
    }

    // guardar resultado
    archivoSalida<<"Area total: "<<areaTotal<<endl;

    // liberar memoria
    delete[] vertices;
    delete[] triangulos;

    return 0;
}