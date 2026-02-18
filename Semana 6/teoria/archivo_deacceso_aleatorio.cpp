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

    archivo.write(reinterpret_cast<char*>(arr), n * sizeof(Estudiante));
    archivo.close();
    cout << "Guardado correctamente.\n";
}

void mostrarTodos() {
    ifstream archivo("estudiantes.dat", ios::binary);

    if (!archivo) {
        cout << "Error al abrir el archivo\n";
        return;
    }

    Estudiante temp;
    int pos = 0;

    cout << "\n--- Lista de estudiantes ---\n";
    while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(Estudiante))) {
        cout << "[" << pos << "] "
             << "Código: "   << temp.codigo   << " | "
             << "Nombre: "   << temp.nombre   << " | "
             << "Promedio: " << temp.promedio  << "\n";
        pos++;
    }

    archivo.close();
}

void modificarPromedio(int posicion, float nuevoPromedio) {
    fstream archivo("estudiantes.dat", ios::in | ios::out | ios::binary);

    if (!archivo) {
        cout << "Error al abrir el archivo\n";
        return;
    }

    // Saltar directamente al bloque de la posición indicada
    // [Est0][Est1][Est2] → posicion=1 salta sizeof(Estudiante)*1 bytes
    archivo.seekp(posicion * sizeof(Estudiante));

    Estudiante e;
    archivo.read(reinterpret_cast<char*>(&e), sizeof(Estudiante));

    // Modificar el campo
    e.promedio = nuevoPromedio;

    // Volver a la misma posición para sobreescribir
    archivo.seekp(posicion * sizeof(Estudiante));
    archivo.write(reinterpret_cast<char*>(&e), sizeof(Estudiante));

    archivo.close();
    cout << "Promedio actualizado correctamente.\n";
}

void calcularPromedio() {
    ifstream archivo("estudiantes.dat", ios::binary);

    if (!archivo) {
        cout << "Error al abrir el archivo\n";
        return;
    }

    Estudiante temp;
    float suma = 0;
    int n = 0;

    while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(Estudiante))) {
        suma += temp.promedio;
        n++;
    }

    archivo.close();

    if (n == 0) {
        cout << "No hay estudiantes.\n";
        return;
    }

    cout << "\nPromedio general: " << suma / n << "\n";
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
    delete[] arr;

    mostrarTodos();
    calcularPromedio();

    // Modificar un estudiante por posición
    int pos;
    float nuevo;
    cout << "\n¿Qué posición desea modificar? ";
    cin >> pos;
    cout << "Nuevo promedio: ";
    cin >> nuevo;

    modificarPromedio(pos, nuevo);

    mostrarTodos();
    calcularPromedio();

    return 0;
}
/*

Lo más importante para entender el acceso aleatorio es visualizar 
el archivo así:

[Est0 = 56 bytes][Est1 = 56 bytes][Est2 = 56 bytes]
     posición 0        posición 1        posición 2

*/