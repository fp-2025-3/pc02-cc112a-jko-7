#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante {
    int codigo;
    char nombre[50];
    float promedio;
};

void guardarBinario(Estudiante* arr, int n) {
    ofstream archivo("estudiantes.dat", ios::binary);

    if (!archivo) {
        cout << "Error al abrir el archivo\n";
        return;
    }

    // Guarda todo el arreglo de una sola vez en bloque
    archivo.write(reinterpret_cast<char*>(arr), n * sizeof(Estudiante));

    archivo.close();
    cout << "Guardado correctamente.\n";
}

void leerBinario() {
    ifstream archivo("estudiantes.dat", ios::binary);

    if (!archivo) {
        cout << "Error al abrir el archivo\n";
        return;
    }

    Estudiante temp;

    cout << "\n--- Estudiantes guardados ---\n";

    // Lee estructura por estructura hasta el fin del archivo
    while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(Estudiante))) {
        cout << "Código:   " << temp.codigo  << "\n"
             << "Nombre:   " << temp.nombre  << "\n"
             << "Promedio: " << temp.promedio << "\n\n";
    }
    archivo.close();
}

int main() {
    int n;
    cout << "¿Cuántos estudiantes? ";
    cin >> n;

    Estudiante* arr = new Estudiante[n];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Estudiante " << i + 1 << " ---\n";
        cout << "Código:   "; cin >> arr[i].codigo;
        cout << "Nombre:   "; cin >> arr[i].nombre;
        cout << "Promedio: "; cin >> arr[i].promedio;
    }

    guardarBinario(arr, n);
    leerBinario();

    delete[] arr;
    return 0;
}