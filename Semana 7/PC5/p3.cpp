#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){

    ofstream archivo ("output/grafico.txt");

    if (!archivo){
        cout<<"Error al abrir el archivo grafico.txt"<<endl;
        return 1;
    }

    float resul[180];

    for (int j=0; j<180; j++){
        resul[j]=sin(5*j);

    }
    

    for (int i=0; i<10; i++){
        archivo<<"|"<<endl;

    }

    for (int i=0; i<80; i++){
        archivo<<"-";

    }
    cout<<endl;

    for (int i=0; i<10; i++){
        archivo<<"|"<<endl;


    }




    


    return 0;
}