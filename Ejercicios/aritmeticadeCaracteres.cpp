#include <iostream>
using namespace std;

int main (){

    char c='A';
    c=c+1;
    cout<<c<<endl;  // Imprime 'B'

    cout<<'z'+1<<endl; // Imprime 123, que es el codigo ASCII del caracter '{'

    char d = {'D'};
    d = d + ('a'-'A'); // Convierte 'D' a minuscula 
                        // sumando la diferencia entre 'a' y 'A' (+32)
    cout<<d<<endl;     



    return 0;
}