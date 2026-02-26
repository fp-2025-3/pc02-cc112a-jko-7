#include <iostream>
#include <fstream>
using namespace std;

int main (){

    ifstream archivo ("entradas/baseUNI.txt");

    if(!archivo){
        cout<<"El archivo no se abrio correctamente"<<endl;
        return 1;
    }

    int num;
    string apellido, nombre;
    float n1,n2;
    float promedio=0;
    float promedioMax=0;
    string apellidoMax;
    string nombreMax;
    char punto,coma,guion;

    cout << "Num\tApellido\tNombre\tNota1\tNota2\tPromedio" << endl;

    while (archivo >> num >> punto){

        getline(archivo, apellido,',');
        getline(archivo, nombre,'-');
        archivo>>n1>>guion>>n2;

        promedio=(n1+n2)/2;
        cout<<num<<"\t"<<apellido<<"\t"<<nombre<<"\t"<<n1<<"\t"<<n2<<"\t"<<promedio<<endl;

        if (promedioMax<promedio){
            promedioMax=promedio;
            apellidoMax=apellido;
            nombreMax=nombre;
        }
    }   

    cout<<"\nEl promedio maximo: "<<promedioMax<<endl;
    cout<<"Alumno: "<<nombreMax<<" "<<apellidoMax<<endl; 

    return 0;
}