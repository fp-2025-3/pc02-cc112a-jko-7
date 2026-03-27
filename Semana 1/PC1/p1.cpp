#include <iostream>
using namespace std;

int calcular (int n){

    if (n>=0 && n<10){
        return n;
    }

    int sum=0;

    while (n>0){
        sum+=n%10;

        n/=10;
    }

    return calcular(sum);

}


int main (){

    int n;
    cout<<"Ingrese n: ";
    cin>>n;

    cout<<calcular(n)<<endl;


    return 0;
}