#include <iostream>
using namespace std;

int main() {
    
    int matriz[2][3] = {{1,2,3},{4,5,6}};
    int(* p) [3] = matriz;

    cout << (*p)[0] << endl;
    
    
    for (int i=0; i<3; i++){    // para imprimir la fila 0
        cout<<(*p)[i]<<" ";
    }
    cout<<endl;
    
    
    for (int i=0; i<3; i++){     // para imprimir la fila 1
        cout<<(*(p+1))[i]<<" ";
    }
    cout<<endl;
    
}