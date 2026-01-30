#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main (){

    int N; 
    cout<<"Ingrese cantidad de contactos: ";
    cin>>N;
    cin.ignore();  // Limpiar el buffer después de esto

    // Arrays para almacenar datos
    char nombres [N][100];
    char direccion[N][100];
    char celular[N][100];
    int edad[N];
    float talla[N];
    char entrada [500];
    
    int validos=0;

    // Leer entradas
    for (int i=0; i<N; i++){
        
        cout<<"Ingrese entrada "<<i+1<<": "<<endl;
        cin.getline (entrada, 500);

        // Separar por comas 
        char* token = strtok(entrada, ",");
        int campo=0;

        while (token !=nullptr){

            if (campo == 0) strcpy (nombres[i], token);
            else if (campo == 1) strcpy (direccion[i], token);
            else if (campo == 2) strcpy (celular[i], token);
            else if (campo == 3) edad[i] = atoi(token);
            else if (campo == 4) talla[i] = atof(token);

            token = strtok (nullptr, ",");
            campo++;
        }

        if (campo == 5){
            validos++;
        } else {
            cout<<"Entrada invalida, se descarta."<<endl;
        }
    }

    // Mostrar resultados
    cout << "\nLos datos guardados en el directorio son:"<<endl;
    cout << left << setw(20) << "Nombre" 
         << setw(30) << "Direccion" 
         << setw(15) << "Celular" 
         << setw(8) << "Edad" 
         << "Talla" << endl;
    
    for(int i = 0; i < validos; i++) {
        cout << left << setw(20) << nombres[i] 
             << setw(30) << direccion[i] 
             << setw(15) << celular[i] 
             << setw(8) << edad[i] 
             << talla[i] << endl;
    }

    return 0;
}