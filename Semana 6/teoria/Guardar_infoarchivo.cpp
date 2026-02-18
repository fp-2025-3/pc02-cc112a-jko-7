#include <iostream>
#include <fstream>
using namespace std;

// Definición
struct Estudiante {
    int codigo;
    char nombre[50];
    float promedio;
};

// Función para escribir archivo
void guardarTexto(Estudiante* arr, int n) {
    ofstream archivo("estudiantes.txt");

    for (int i = 0; i < n; i++) {
        archivo << arr[i].codigo << " "
                << arr[i].nombre << " "
                << arr[i].promedio << endl;
    }

    archivo.close();
    cout<<"Archivo guardado correctamente\n";
}

int main (){
    int n;
    cout<<"¿Cuántos estudiantes desea registrar? ";
    cin>>n;

    Estudiante* arr = new Estudiante[n];

    for (int i=0; i<n; i++){
        cout<<"\n--- Estudiante " << i + 1 << " ---\n";
        cout << "Código: ";
        cin >> arr[i].codigo;
        cout << "Nombre: ";
        cin >> arr[i].nombre;
        cout << "Promedio: ";
        cin >> arr[i].promedio;
    }

    guardarTexto(arr,n);

    delete[] arr; 

    return 0;
}