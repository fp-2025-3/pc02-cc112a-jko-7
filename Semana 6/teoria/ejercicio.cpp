/*
Crear un sistema que:
Permita registrar estudiantes dinámicamente.
Los guarde en binario.
Permita modificar uno usando acceso aleatorio.
Permita mostrar todos.
Calcule promedio.
*/
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
        cout << "No hay estudiantes registrados aún.\n";
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

    if (pos == 0) cout << "El archivo está vacío.\n";

    archivo.close();
}

void modificarPromedio() {
    mostrarTodos();

    int posicion;
    float nuevoPromedio;
    cout << "\n¿Qué posición desea modificar? ";
    cin >> posicion;
    cout << "Nuevo promedio: ";
    cin >> nuevoPromedio;

    fstream archivo("estudiantes.dat", ios::in | ios::out | ios::binary);

    if (!archivo) {
        cout << "Error al abrir el archivo\n";
        return;
    }

    archivo.seekp(posicion * sizeof(Estudiante));

    Estudiante e;
    archivo.read(reinterpret_cast<char*>(&e), sizeof(Estudiante));

    e.promedio = nuevoPromedio;

    archivo.seekp(posicion * sizeof(Estudiante));
    archivo.write(reinterpret_cast<char*>(&e), sizeof(Estudiante));

    archivo.close();
    cout << "Promedio actualizado correctamente.\n";
}

void calcularPromedio() {
    ifstream archivo("estudiantes.dat", ios::binary);

    if (!archivo) {
        cout << "No hay estudiantes registrados aún.\n";
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

    cout << "\nPromedio general de todos los estudiantes: " << suma / n << "\n";
}

void registrarEstudiantes() {
    int n;
    cout << "¿Cuántos estudiantes desea registrar? ";
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
}

int main() {
    int opcion;

    do {
        cout << "\n========= SISTEMA DE ESTUDIANTES =========\n";
        cout << "1. Registrar estudiantes\n";
        cout << "2. Mostrar todos\n";
        cout << "3. Modificar promedio\n";
        cout << "4. Calcular promedio general\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrarEstudiantes(); break;
            case 2: mostrarTodos();         break;
            case 3: modificarPromedio();    break;
            case 4: calcularPromedio();     break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }

    } while (opcion != 0);

    return 0;
}