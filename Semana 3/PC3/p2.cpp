#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int contarPalabrasConVocal (char *texto){

    int i=0;
    char* p=texto;
    
    while (*p!='\0'){
        
        if ((p==texto && *p!=' ') || (*(p-1)==' ' && *p!=' ')){
            
            char letra=tolower(*p);

            if (letra=='a' || letra=='e' || letra=='i' || letra=='o' || letra=='u'){
                i++;
            }
        }
        p++;    
    }       
    return i;
}


int main (){

    char texto[]={"Este es    un ejemplo en C++     END"};

    int resultado=contarPalabrasConVocal(texto);
    cout<<"Numero de palabras que comienzan con vocal: "<<resultado<<endl;  

    return 0;
}