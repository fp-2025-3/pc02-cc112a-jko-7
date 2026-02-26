#include <iostream>
#include <fstream>
using namespace std;

int main (){

    ifstream archivo1("entradas/archivo1.txt");
    ifstream archivo2("entradas/archivo2.txt");
    ofstream archivo3("output/mezcla.txt");

    if (!archivo1 || !archivo2 || !archivo3){
        cout<<"Error: un archivo no se abrio correctamente"<<endl;
        return 1;
    }

    int v1,v2;

    archivo1>>v1;
    archivo2>>v2;


    while (v1!=-1 && v2!=-1){
        if (v1 < v2){
            archivo3<<v1<<endl;
            archivo1>>v1;
        } else {
            archivo3<<v2<<endl;
            archivo2>>v2;
        }
    }

    // copiar resto de datos archivo1
    while (v1 != -1)
    {
        archivo3<<v1<<endl;
        archivo1>>v1;
    }

    // copiar resto de datos archivo2
    while (v2 != -1){
        archivo3<<v2<<endl;
        archivo2>>v2;
    }

    archivo1.close();
    archivo2.close();
    archivo3.close();


    return 0;
}