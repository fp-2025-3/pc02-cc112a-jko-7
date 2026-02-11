#include <iostream>
#include <cmath>
using namespace std;

struct Punto
{
    int x;
    int y;
    int z;
};


int main (){

    int n=2;

    Punto* punto = new Punto[n];

    cout<<"Ingrese las coordenadas del primer punto:"<<endl;
    cout<<"X: ";
    cin>>punto[0].x;
    cout<<"Y: ";
    cin>>punto[0].y;
    cout<<"Z: ";
    cin>>punto[0].z;
    
    
    cout<<"Ingrese las coordenadas del segundo punto:"<<endl;
    cout<<"X: ";
    cin>>punto[1].x;
    cout<<"Y: ";
    cin>>punto[1].y;
    cout<<"z: ";
    cin>>punto[1].z;


    float distancia = sqrt(pow((punto[1].x-punto[0].x),2)+pow((punto[1].y-punto[0].y),2)+pow((punto[1].z-punto[0].z),2));
    cout<<"La distancia entre los dos puntos es: "<<distancia<<endl;

    delete[] punto;


    return 0;
}