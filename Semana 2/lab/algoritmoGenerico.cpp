

// Algoritmo genérico simple con puntero a función

#include <iostream>
using namespace std;

bool mayor (int a, int b){
    return a>b;
}

bool menor (int a, int b){
    return a<b;
}

int seleccionar (int a, int b, bool (*cmp)(int, int)){

    return cmp(a,b) ? a:b;
}


int main (){

    cout<<seleccionar (3,7, mayor)<<endl;
    cout<<seleccionar (3,7, menor)<<endl;


    return 0;
}