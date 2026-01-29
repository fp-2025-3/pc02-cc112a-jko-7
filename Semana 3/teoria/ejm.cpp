#include <iostream>
#include <cstring>
using namespace std;

void imprimir (char* arr){

    for (char* ptr=arr+strlen(arr); ptr>=arr; ptr++){
        cout<<*ptr;
    }

}

int main (){

    char* diaz[] = {"Lunes", "Mares", "Miercoles"};

    for (int i=0; i<3; i++){
        imprimir (diaz[i]);
    }


    return 0;
}

