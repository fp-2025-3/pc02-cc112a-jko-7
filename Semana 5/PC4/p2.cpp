#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct Seleccion
    {
        string nombre;
        int PG, PE, PP;
        int GF, GC;
        int puntajeTotal;
        int diferenciaGoles;
        float rendimiento;
    };

int main (){

    srand(time(0));

    Seleccion seleccion[5];

    seleccion[0].nombre="Pais_1";
    seleccion[1].nombre="Pais_2";
    seleccion[2].nombre="Pais_3";
    seleccion[3].nombre="Pais_4";
    seleccion[4].nombre="Pais_5";

    for (int i=0; i<5; i++){
        seleccion[i].PG=rand()%101;
        seleccion[i].PE=rand()%(101-seleccion[i].PG);
        seleccion[i].PP=100-seleccion[i].PG-seleccion[i].PE;

        seleccion[i].puntajeTotal = 3*seleccion[i].PG+seleccion[i].PE;
        seleccion[i].rendimiento=((float)seleccion[i].puntajeTotal/300)*100;

        /*
        en cada partido los goles anotados por un equipo estaran en el rango de 0 a 5,
        en un partido ganado gf>gc
        en un partido perdido gf<gc
        en un partido empatado gf=gc
        */             
        seleccion[i].GF=0;
        seleccion[i].GC=0;


        seleccion[i].GF=seleccion[i].PG*(rand()%3+3)+seleccion[i].PE*3;
        seleccion[i].GC=seleccion[i].PP*(rand()%2)+seleccion[i].PE*3; 
        seleccion[i].diferenciaGoles= seleccion[i].GF-seleccion[i].GC;


    }

    for (int i=0; i<5-1; i++){
        for (int j=0; j<5-1;j++){
            if (seleccion[j].puntajeTotal<seleccion[j+1].puntajeTotal){
                swap(seleccion[j].puntajeTotal, seleccion[j+1].puntajeTotal);
                swap(seleccion[j].PG, seleccion[j+1].PG);
                swap(seleccion[j].PE, seleccion[j+1].PE);
                swap(seleccion[j].PP, seleccion[j+1].PP);
                swap(seleccion[j].nombre, seleccion[j+1].nombre);
                swap(seleccion[j].rendimiento, seleccion[j+1].rendimiento);
                swap(seleccion[j].GF, seleccion[j+1].GF);
                swap(seleccion[j].GC, seleccion[j+1].GC);
                swap(seleccion[j].diferenciaGoles, seleccion[j+1].diferenciaGoles);
            }
        }
    }
    

    cout<<"Seleccion\tPG\tPE\tPP\tGF\tGC\tDG\tPts\tRend(%)"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;

    for (int i=0; i<5; i++){
        cout<<seleccion[i].nombre<<"\t\t"<<seleccion[i].PG<<"\t"<<seleccion[i].PE<<"\t"
            <<seleccion[i].PP<<"\t"<<seleccion[i].GF<<"\t"<<seleccion[i].GC<<"\t"
            <<seleccion[i].diferenciaGoles<<"\t"<<seleccion[i].puntajeTotal<<"\t"
            <<fixed<<setprecision(1)<<seleccion[i].rendimiento<<endl;

    }

    cout<<"CAMPEON: "<<seleccion[0].nombre<<" | Puntaje: "<<seleccion[0].puntajeTotal
                    <<" | DG: "<<seleccion[0].diferenciaGoles<<" | Rendimiento: "
                    <<seleccion[0].rendimiento<<endl;



    return 0;
}

