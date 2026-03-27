
// 3. Asignación y llamada mediante puntero


#include <iostream>
using namespace std;

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) { 
    return a - b; 
}

int cuadrado(int x) { 
    return x*x; 
}

int main (){

    int (*op)(int, int)=suma;
    int (*cu)(int);

    cout<<op(4,6)<<endl;

    op=resta;

    cout<<op(8,1)<<endl;
    
    cu=cuadrado;
    
    cout<<cu(8)<<endl;

    return 0;
}