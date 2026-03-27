

//  Callback: función pasada como argumento

#include <iostream>
#include <cmath>
using namespace std;

void ejecutar (int a, int b, int(*op)(int, int)){

    cout<<op(a,b)<<endl;
}

void ejecutar2 (int a, double(*op)(int)){

    cout<<op(a)<<endl;

}

int suma (int a, int b){
    return a+b;
}

int resta (int a, int b){
    return a-b;
}

double cuadrado(int a){
    return a*a;
}

double raiz (int a){
    return sqrt(a);
}

int main (){
    
    ejecutar(4,5, suma);
    ejecutar(9,5, resta);
    ejecutar2(7, cuadrado);
    ejecutar2(5, raiz);


    return 0;
}