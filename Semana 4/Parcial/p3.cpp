#include <iostream>
using namespace std;

const int N = 4;

bool esFilaDominanteEstricta (int (*M)[N], int fila){
    bool colsEstricta = false;
    for (int j=0; j<N; j++){
        for (int i=0; i<N; i++){

            if (i!=fila){
                if (*(*(M+fila)+j)<*(*(M+i)+j)){ 
                    return false;
                }
                
                if (*(*(M+fila)+j)>*(*(M+i)+j)){
                    colsEstricta=true;
                }
            }
        }
    }

    return colsEstricta;  
}

bool esFilaFuertementeDominante (int (*M)[N], int fila){
    if (!esFilaDominanteEstricta(M,fila)){
        return false;
    }
    int sumaFila=0;

    for (int i=0; i<N; i++){
        sumaFila+=*(*(M+fila)+i);
    }

    for (int i=0; i<N; i++){

        if (i!=fila){
            int sumaotraFila=0;

            for (int j=0; j<N; j++){
                sumaotraFila+=*(*(M+i)+j);
            }

            if (sumaFila<=sumaotraFila){
                return false;
            }
        }
    }

    return true;
}


int main (){

    int M[N][N] = {{2,3,1,4},
                   {1,2,3,2},
                   {5,6,7,8},
                   {0,1,2,1}};

    cout<<"Fila\tDominante Estricta\t\tFuertemente Dominante"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    for (int i = 0; i < N; i++){
        cout<<i<<"\t";
        if (esFilaDominanteEstricta(M,i)==true){
            cout<<"SI";
        } else {
            cout<<"NO";
        }
            
        cout<<"\t\t\t\t";
        if (esFilaFuertementeDominante(M,i)==true){
            cout<<"SI";
        } else {
            cout<<"NO";
        }

        cout<<endl;
    }

    return 0;
}