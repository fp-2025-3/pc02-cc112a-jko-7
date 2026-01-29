#include <iostream>
using namespace std;



int main (){

    char arr1[5] = {'H','o','l','a','!'};  //No tiene caracter nulo al final 
    char arr2[5] = "Hola";               //Tiene caracter nulo al final '\0'
    char palabra[] = "UNI";  //UNI tiene 3 caracteres visibles pero
                                //en memoria se guarda como 4 caracteres
                                //porque al final se agrega el caracter nulo '\0'
    cout<<arr1<<endl;   //Imprime hasta Hola! y luego caracteres basura
    cout<<arr2<<endl;   //Imprime hasta encontrar un caracter nulo
    cout<<palabra<<endl; //Imprime hasta encontrar un caracter nulo


    return 0;
}