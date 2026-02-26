#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Punto {
    float x;
    float y;
};

// Función que rota un punto en sentido antihorario dado un ángulo en grados
Punto rotacion(Punto* p, float angulo) {
    float rad = angulo * M_PI / 180.0;
    Punto rotado;
    rotado.x = cos(rad) * p->x - sin(rad) * p->y;
    rotado.y = sin(rad) * p->x + cos(rad) * p->y;
    return rotado;
}

int main() {

    ifstream archivoEntrada("input/poligono1.txt");

    if (!archivoEntrada) {
        cout << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    int n;
    archivoEntrada >> n;

    Punto** vertices = new Punto*[n];
    for (int i = 0; i < n; i++) {
        vertices[i] = new Punto;
        archivoEntrada >> vertices[i]->x >> vertices[i]->y;
    }

    archivoEntrada.close();

    float angulo;
    cout << "\nIngrese el angulo de rotacion (en grados): ";
    cin >> angulo;

    ofstream archivoSalida("output/poligono2.txt");

    if (!archivoSalida) {
        cout << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    archivoSalida<<n<<endl;

    for (int i = 0; i < n; i++) {
        Punto rotado = rotacion(vertices[i], angulo);
        archivoSalida<<rotado.x<<" "<<rotado.y<<endl;
    }

    archivoSalida.close();

    // Liberar memoria
    for (int i = 0; i < n; i++) {
        delete vertices[i];
    }
    delete[] vertices;

    return 0;
}