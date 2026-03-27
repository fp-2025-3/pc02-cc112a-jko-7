#include <iostream>
#include <fstream>
using namespace std;

int main (){

    ofstream archivo("datos.txt");

    if (!archivo){
        cout<<"Error al abrir el archivo\n";
        return 1;
    }

    archivo<<"Hola mundo\n";
    archivo<<"25"<<endl;

    archivo.close();

    return 0;
}
