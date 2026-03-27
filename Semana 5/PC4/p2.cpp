#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int N=5;  // Definir una constante ayuda a cambiar la cantidad de equipos facilmente

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

    Seleccion seleccion[N];

    for (int i=0; i<N; i++){
        seleccion[i].nombre="Pais_"+ to_string(i+1);
        seleccion[i].PG=rand()%101;
        seleccion[i].PE=rand()%(101-seleccion[i].PG);
        seleccion[i].PP=100-seleccion[i].PG-seleccion[i].PE;

        seleccion[i].puntajeTotal = 3*seleccion[i].PG+seleccion[i].PE;
        seleccion[i].rendimiento=((float)seleccion[i].puntajeTotal/300)*100;

        seleccion[i].GF=0;
        seleccion[i].GC=0;

        // Simular cada partido individualmente
        // Partidos ganados
        for (int j=0; j<seleccion[i].PG; j++){
            int GF, GC;
            do {
                GF = rand()%6;      // GF (goles a favor)
                GC = rand()%6;      // GC (goles en contra)
            } while(GF<=GC);  // Asegurar que GF>GC en partidos ganados

            seleccion[i].GF+=GF;
            seleccion[i].GC+=GC;            
        }

        // Partidos empatados
        for (int j=0; j<seleccion[i].PE; j++){
            int goles = rand()%6;   
        
            seleccion[i].GF+=goles;
            seleccion[i].GC+=goles;            
        }

        // Partidos perdidos
        for (int j=0; j<seleccion[i].PP; j++){
            int GF, GC;
            do {
                GF = rand()%6;      
                GC = rand()%6;      
            } while(GF>=GC);  // Asegurar que GF<GC en partidos perdidos

            seleccion[i].GF+=GF;
            seleccion[i].GC+=GC;            
        }

        seleccion[i].diferenciaGoles = seleccion[i].GF - seleccion[i].GC;

    }
    
    // Ordenamiento con criterios de desempate
    for (int i=0; i<N-1; i++){
        for (int j=0; j<N-1-i;j++){
            bool intercambiar = false;

            if (seleccion[j].puntajeTotal < seleccion[j+1].puntajeTotal){
                intercambiar = true;
            } 
            else if (seleccion[j].puntajeTotal == seleccion[j+1].puntajeTotal){
                if (seleccion[j].diferenciaGoles < seleccion[j+1].diferenciaGoles){
                    intercambiar = true;
                }
                else if (seleccion[j].diferenciaGoles == seleccion[j+1].diferenciaGoles){
                    if (seleccion[j].GF < seleccion[j+1].GF){
                        intercambiar = true;
                    }
                }
            }
                
            if (intercambiar){
                swap(seleccion[j], seleccion[j+1]);
            }
        }
    }
    
    cout<<"Seleccion\tPG\tPE\tPP\tGF\tGC\tDG\tPts\tRend(%)"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;

    for (int i=0; i<N; i++){
        cout<<seleccion[i].nombre<<"\t\t"<<seleccion[i].PG<<"\t"<<seleccion[i].PE<<"\t"
            <<seleccion[i].PP<<"\t"<<seleccion[i].GF<<"\t"<<seleccion[i].GC<<"\t"
            <<seleccion[i].diferenciaGoles<<"\t"<<seleccion[i].puntajeTotal<<"\t"
            <<fixed<<setprecision(1)<<seleccion[i].rendimiento<<endl;
    }

    cout<<"\nCAMPEON: "<<seleccion[0].nombre<<" | Puntaje: "<<seleccion[0].puntajeTotal
                    <<" | DG: "<<seleccion[0].diferenciaGoles<<" | Rendimiento: "
                    <<seleccion[0].rendimiento<<"%"<<endl;

    return 0;
}

