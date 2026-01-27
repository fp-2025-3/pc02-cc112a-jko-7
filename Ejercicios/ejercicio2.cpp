/* Dado una lista de nombres ordenar

char nombres[][20] = {
    "Carlos",
    "Ana",
    "Pedro",
    "Beatriz",
    "Luis"
};  

ordenar la lista en orden alfabetico ascendente
no usar []
use aritmetica de punteros
*/

#include <iostream>
#include <cstring>
using namespace std;

int main (){

    const char* nombres[] = {
        "Carlos",
        "Ana",
        "Pedro",
        "Beatriz",
        "Luis"
    };  

    int n = 5; // numero de nombres

    for (int i = 0; i<n-1; i++) {
        for (int j = 0; j<n-i-1; j++) {
            if (strcmp(*(nombres+j), *(nombres+j+1)) > 0) {
                // Intercambiar nombres
                swap(*(nombres+j), *(nombres+j+1));
            }
        }
    }
    
    for (int i=0; i<n; i++){
        cout<<*(nombres+i)<<endl;
    }

    return 0;
}