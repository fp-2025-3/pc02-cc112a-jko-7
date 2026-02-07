#include <iostream>
#include <iomanip> // Para que la tabla se vea mejor
using namespace std;

const int N = 4;

bool esFilaDominanteEstricta (int (*M)[N], int fila){
    bool existecolsMayor = false;

    for (int j=0; j<N; j++){
        bool esMayorIgual = true;
        bool esEstrictamenteMayor = true;

        for (int i=0; i<N; i++){
            if (i!=fila){
                if (*(*(M+fila)+j) < *(*(M+i)+j)){ 
                    return false;
                }
                
                if (*(*(M+fila)+j) <= *(*(M+i)+j)){
                    esEstrictamenteMayor = false;
                }
            }
        }
        if (esEstrictamenteMayor){
            existecolsMayor = true;
        }

    }

    return existecolsMayor;  
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

            if (sumaFila <= sumaotraFila){
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

    cout<<left<<setw(8)<<"Fila"
        <<setw(25)<<"Dominante Estricta"
        <<setw(25)<<"Fuertemente Dominante"<<endl;
    cout<<string(58, '-')<<endl;

    for (int i = 0; i < N; i++){
        
        bool de = esFilaDominanteEstricta(M,i);
        bool fd = esFilaFuertementeDominante(M,i);
            
        cout<<left<<setw(8)<<i
            <<setw(25)<<(de ? "SI" : "NO")
            <<setw(25)<<(de ? "SI" : "NO")<<endl;
    }

    return 0;
}