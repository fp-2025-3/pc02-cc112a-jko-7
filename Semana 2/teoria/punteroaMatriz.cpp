#include <iostream>
using namespace std;

void imprimir (int (*a)[4]){

    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            cout<<*(*(a+i)+j)<<" ";
        }
        cout<<endl;
    }
    
}


void sumaFila (int (*a)[4]){

    for (int i=0; i<3; i++){
        int sum=0;
        for (int j=0; j<4; j++){
            sum+=*(*(a+i)+j);
        }
        cout<<sum<<endl;
    }

}


int maxMatriz(int (*a)[4]){

    int max = *(*(a+0)+0);

    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            
            if (max<*(*(a+i)+j)){
                max = *(*(a+i)+j);
            }
        }
    }

    return max;

}


int main (){

    int matriz[3][4];
    
    int (*ptr)[4]=matriz;


    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            cout<<"A["<<i<<"]["<<j<<"] = ";
            cin>>*(*(ptr+i)+j);
        }
    }

    imprimir(ptr);
    sumaFila(ptr);
    cout<<"Maximo "<<maxMatriz(ptr)<<endl;
    




    return 0;
}