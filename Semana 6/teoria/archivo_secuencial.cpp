#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante {
    int codigo;
    char nombre[50];
    float promedio;
};

float sumaRecursiva(float* arr, int n) {
    if (n == 0) return 0;
    return arr[n-1] + sumaRecursiva(arr, n-1);
}

int main() {
    ifstream archivo("estudiantes.txt");

    // FIX 1: Verificar que el archivo se abrió correctamente
    if (!archivo) {
        cout << "Error al abrir el archivo\n";
        return 1;
    }

    Estudiante temp;
    float* promedios = new float[100];
    int n = 0;

    while (archivo >> temp.codigo >> temp.nombre >> temp.promedio) {
        promedios[n++] = temp.promedio;
    }

    // FIX 2: Validar división por cero
    if (n == 0) {
        cout << "No hay estudiantes en el archivo\n";
        delete[] promedios;
        archivo.close();
        return 1;
    }

    float suma = sumaRecursiva(promedios, n);
    cout << "Promedio general: " << suma / n << endl;

    // FIX 3: Liberar memoria
    delete[] promedios;
    archivo.close();

    return 0;
}
/*
Errores frecuentes:
No liberar memoria
No verificar archivo
No validar división por cero
*/