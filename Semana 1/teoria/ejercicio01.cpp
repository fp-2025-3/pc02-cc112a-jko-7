#include <iostream>
using namespace std;

int potenciaIterativa(int a, int n){

    int b=1;

    for (int i=0; i<n; i++){
        b=b*a;
    }

    return b;
}

int potenciaRecursiva(int a, int n){

    if (n==0){
        return 1;
    }

    return a*potenciaRecursiva (a, n-1);
}

int potenciaRapida (int a, int n){

    if (n==0){
        return 1;
    }

    if (n==1){
        return a;
    }

    if (n%2==0){  // Si n es par
        int mitad = potenciaRapida (a, n/2);
        return mitad*mitad;
    } else {
        return a*potenciaRapida (a, n-1);
    }
}

int main (){

    int a, n;
    cin>>a>>n;

    cout<<potenciaIterativa (a, n)<<endl;
    cout<<potenciaRecursiva (a, n)<<endl;
    cout<<potenciaRapida (a, n)<<endl;

    return 0;
}


/*



*/