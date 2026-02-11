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

// GENERALIZANDO EL PROBLEMA 

/*
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Punto {
    int x, y, z;
};

int main() {
    // Diccionario de ordinales para los primeros puntos
    string etiquetas[] = {"primer", "segundo", "tercer", "cuarto", "quinto"};
    
    int n;
    cout << "En este ejemplo usaremos maximo 5 puntos. ¿Cuantos desea? ";
    cin >> n;

    Punto* puntos = new Punto[n];

    for (int i = 0; i < n; i++) {
        // Si el índice está dentro de nuestro arreglo de etiquetas, usamos la palabra.
        // Si no, usamos el número normal (ej: "punto 6").
        if (i < 5) {
            cout << "\nIngrese las coordenadas del " << etiquetas[i] << " punto:" << endl;
        } else {
            cout << "\nIngrese las coordenadas del punto " << i + 1 << ":" << endl;
        }

        cout << "X: "; cin >> puntos[i].x;
        cout << "Y: "; cin >> puntos[i].y;
        cout << "Z: "; cin >> puntos[i].z;
    }

    // Cálculo de distancia entre el primer y segundo punto (como en tu código original)
    if (n >= 2) {
        float distancia = sqrt(pow((puntos[1].x - puntos[0].x), 2) + 
                               pow((puntos[1].y - puntos[0].y), 2) + 
                               pow((puntos[1].z - puntos[0].z), 2));
        cout << "\nLa distancia entre el primer y segundo punto es: " << distancia << endl;
    }

    delete[] puntos;
    return 0;
}

*/