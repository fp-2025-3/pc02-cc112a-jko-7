#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante {
    int codigo;
    char nombre[50];
    float promedio;
};

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

/*
arr es un puntero a estructura
Se usa indexación como arreglo
No se guarda la estructura como bloque
Se serializa campo por campo
*/

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