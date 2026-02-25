#include <iostream>
#include <fstream>
using namespace std;

int fibonacci(int n){
    
    if (n<=1){
        return n;
    }

    return fibonacci(n-1) + fibonacci (n-2);
}


void escribirFibonacciBinario(const char* nombreArchivo){

    ofstream archivo (nombreArchivo, ios::binary);

    if (!archivo){
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }

    for (int i=0; i<20; i++){
        int valor = fibonacci(i);
        archivo.write((char*)&valor, sizeof(int));
    }

    cout<<"Funcion escribirFibonacciBinario:"<<endl;
    cout<<"Terminos de Fibonacci escritos en el archivo correctamente."<<endl;

}

void leerFibonacciBinario(const char* nombreArchivo){

    ifstream archivo (nombreArchivo, ios::binary);

    if (!archivo){
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }

    int valor;
    int i=0;

    cout<<"\nFuncion leerFibonacciBinario: "<<endl;
    while (archivo.read((char*)&valor, sizeof(valor)))
    {
        cout<<"Termino "<<i+1<<": "<<valor<<endl;
        i++;
    }
    cout<<"-------------------------------------"<<endl;

}


int main (){

    const char* nombreArchivo = "output/fibonacci.bin";

    escribirFibonacciBinario(nombreArchivo);
    leerFibonacciBinario(nombreArchivo);

    
    return 0;
}