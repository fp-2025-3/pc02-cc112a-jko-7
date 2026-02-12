#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>  // setprecision
using namespace std;

struct Seleccion
{
    int puntaje; 
    int PG; // partidos ganados
    int PE; // partidos empatados
    int PP; // partidos perdidos
    float rendimiento;
};


int main (){

    Seleccion seleccion[5];
    int n=5;

    srand(time(0));

    int seleccionMayor=0;

    for (int i=0; i<n; i++){
        seleccion[i].PG=rand()%101;
        seleccion[i].PE=rand()%(101-seleccion[i].PG);
        seleccion[i].PP=100-seleccion[i].PG-seleccion[i].PE;

        seleccion[i].puntaje=(3*seleccion[i].PG)+seleccion[i].PE;
        seleccion[i].rendimiento=((float)seleccion[i].puntaje*100)/300;

        if (seleccion[seleccionMayor].rendimiento<seleccion[i].rendimiento){
            seleccionMayor=i;
        }
    }

    cout<<"Seleccion\t\tPG\tPP\tPE\tPuntaje\t\tRendimiento"<<endl;
    for (int i=0; i<n; i++){
        cout<<"Pais_Seleccion "<<i<<"\t"<<seleccion[i].PG<<"\t"
            <<seleccion[i].PP<<"\t"<<seleccion[i].PE<<"\t"
            <<seleccion[i].puntaje<<"\t\t"<<fixed<<setprecision(1)<<seleccion[i].rendimiento<<endl;
    }

    cout<<"La seleccion con mejor rendimiento es: Seleccion "<<seleccionMayor
        <<" Rendimiento: "<<fixed<<setprecision(1)<<seleccion[seleccionMayor].rendimiento<<endl;

    
    return 0;
}