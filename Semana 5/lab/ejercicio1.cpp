#include <iostream>
#include <cmath>
using namespace std;

struct Punto
{
    float x,y,z;
};

int main (){

    Punto p1,p2;    // crear 2 instancias (objetos)

    cout<<"Ingrese las coordenadas del primer punto:"<<endl;
    cout<<"X: ";
    cin>>p1.x;
    cout<<"Y: ";
    cin>>p1.y;
    cout<<"Z: ";
    cin>>p1.z;
    
    cout<<"Ingrese las coordenadas del segundo punto:"<<endl;
    cout<<"X: ";
    cin>>p2.x;
    cout<<"Y: ";
    cin>>p2.y;
    cout<<"z: ";
    cin>>p2.z;

    float distancia = sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2)+pow((p2.z-p1.z),2));
    cout<<"La distancia entre los dos puntos es: "<<distancia<<endl;
    
    return 0;
}

// GENERALIZANDO EL PROBLEMA 

/*
#include <iostream>
#include <cmath>

using namespace std;

struct Punto {
    int x, y, z;
};

// Función para calcular distancia entre dos puntos (opcional, pero ayuda a generalizar)
float calcularDistancia(Punto p1, Punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

int main() {
    int n;
    cout << "Ingrese la cantidad de puntos: ";
    cin >> n;

    // 1. Uso de puntero para arreglo dinámico
    Punto* puntos = new Punto[n];

    // 2. Bucle para llenar los datos
    for (int i = 0; i < n; i++) {
        cout << "\nIngrese coordenadas para el punto " << i + 1 << ":" << endl;
        cout << "X: "; cin >> puntos[i].x;
        cout << "Y: "; cin >> puntos[i].y;
        cout << "Z: "; cin >> puntos[i].z;
    }

    // 3. Ejemplo de cálculo (Distancia entre el primer y último punto ingresado)
    if (n >= 2) {
        float d = calcularDistancia(puntos[0], puntos[n - 1]);
        cout << "\nDistancia entre el punto 1 y el punto " << n << " es: " << d << endl;
    } else {
        cout << "\nSe necesitan al menos 2 puntos para calcular una distancia." << endl;
    }

    // 4. ¡MUY IMPORTANTE! Liberar la memoria
    delete[] puntos;

    return 0;
}

*/