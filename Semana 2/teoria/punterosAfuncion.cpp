#include <iostream>
using namespace std;

int suma (int a, int b){

    return a+b;
}

int resta (int a, int b){

    return a-b;
}


int main (){

    int (*operacion)(int, int);

    operacion=suma;

    cout<<operacion(5,9)<<endl;

    operacion=resta;
    cout<<operacion(9,4)<<endl;


    return 0;
}