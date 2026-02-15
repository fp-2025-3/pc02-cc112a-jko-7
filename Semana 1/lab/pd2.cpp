#include <iostream>
using namespace std;

int recursivaDias (int n){

    if (n==0){
        return 0;
    }

    int dias = 1 + recursivaDias(n-1);

    if (n%2==0){
        int opcion2 = 1 + recursivaDias(n/2);
        if (opcion2<dias){
            dias=opcion2;
        }
    }

    if (n%3==0){
        int opcion3 = 1 + recursivaDias(n/3);
        if (opcion3<dias){
            dias=opcion3;
        }
    }

    return dias;

}

int main (){

    int n;
    cout<<"Ingrese el numero de manzanas: ";
    cin>>n;

    cout<<recursivaDias(n)<<endl;


    return 0;
}