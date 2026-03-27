#include <iostream>
#include <cmath>
using namespace std;

struct Punto
{
    double x;
    double y;
};

void leerPunto(Punto* p){
    cout<<"Ingrese x: ";
    cin>>p->x;
    cout<<"Ingrese y: ";
    cin>>p->y;
}

double distanciaOrigen (const Punto* p){

    return sqrt(pow(p->x,2)+pow(p->y,2));
}

Punto* masLejano(Punto* p1, Punto* p2){

    double d1 = distanciaOrigen(p1);
    double d2 = distanciaOrigen(p2);

    if (d1>d2){
        return p1;
    } else {
        return p2;
    }

    return p1;
}

int main (){
    
    Punto *p1 = new Punto;
    Punto *p2 = new Punto;
    cout<<"Primera coordenada (p1)"<<endl;
    leerPunto(p1);
    cout<<"Segunda coordenada (p2)"<<endl;
    leerPunto(p2);

    if (masLejano(p1,p2)==p1){
        cout<<"El punto mas lejano del origen es p1 con coordenadas: ";
        cout<<"("<<p1->x<<", "<<p1->y<<")"<<endl;
    } else {
        cout<<"El punto mas lejano del origen es p2 con coordenadas: ";
        cout<<"("<<p2->x<<", "<<p2->y<<")"<<endl;
    }

    delete p1;
    delete p2;

    return 0;
}