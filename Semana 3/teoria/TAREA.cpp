/*
Se tiene un arreglo de cadenas definido mediante
const char* cad[];

Implemente una funcion que cuente cuantas cadenas 
tienen una longitud mayor que la longitud promedio
del arreglo


*/

#include <iostream>
#include <cstring>
using namespace std;


int main (){

    const char* cad[] = {
        "Hola",
        "Adios",
        "Buenos dias",
        "Buenas tardes",
        "Buenas noches"
    };


    int n = 5; // numero de cadenas

    int sumaLongitudes = 0;
    for (int i = 0; i < n; i++) {
        sumaLongitudes += strlen(*(cad + i));
    }
    
    double prom = sumaLongitudes/n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strlen(*(cad + i)) > prom) {
            count++;
        }
    }
    cout << "Numero de cadenas con longitud mayor que el promedio: " << count << endl;
    

    return 0;

}