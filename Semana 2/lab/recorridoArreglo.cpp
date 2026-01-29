
// 5. Recorrido de arreglo solo con punteros


#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1,2,3,4,5};

    for (int* p = arr; p < arr + 5; ++p) {
        cout << *p << " ";
    }
}