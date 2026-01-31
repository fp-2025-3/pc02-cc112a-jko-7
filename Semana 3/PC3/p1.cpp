#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

int main (){

    char texto[] = "1,2,4,7,11";
    int nums[10];
    int n=0;

    char *p=texto;

    // Extraer números del texto
    while (*p!='\0'){
        // Saltar comas
        while (*p==','){
            p++;
        }

        // Convertir numero
        if (isdigit(*p)){
            nums[n++] = atoi(p);

            // Avanzamos hasta la proxima coma o final
            while (*p && *p!=','){
                p++;
            }
        } 
    }

    // Algoritmo de 2 punteros para suma = 15
    int izq = 0;
    int der = n-1;
    bool encontrado=false;

    while (izq<der){
        int suma = nums[izq]+nums[der];
        if ((suma == 15) || (suma == 10)){
            cout<<"SI existen 2 numeros con suma 15"<<endl;
            encontrado = true;
            break;
        }
        if (suma < 15){
            izq++;
        } else {
            der--;
        } 
    }
    
    if (!encontrado){
        cout<<"NO existen 2 numeros con suma 15"<<endl;
    }

    izq = 0;
    der = n-1;
    encontrado=false;

    while (izq<der){
        int suma = nums[izq]+nums[der];
        if (suma == 10){
            cout<<"SI existen 2 numeros con suma 10"<<endl;
            encontrado = true;
            break;
        }
        if (suma < 10){
            izq++;
        } else {
            der--;
        }
    }

    if (!encontrado){
        cout<<"NO existen 2 numeros con suma 10"<<endl;
    }

    return 0;
}