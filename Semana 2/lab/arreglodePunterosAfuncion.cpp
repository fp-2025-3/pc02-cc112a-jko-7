

// Arreglo de punteros a funciones

#include <iostream>
using namespace std;

int suma(int a, int b) { return a + b; }
int resta(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }

int main() {
    int (*ops[3])(int,int) = {suma, resta, mult};

    for (int i = 0; i < 3; ++i) {
        cout << ops[i](10,5) << endl;
    }
}



