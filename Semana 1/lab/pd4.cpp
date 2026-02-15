#include <iostream>
using namespace std;

int main (){

    int A[]={9, -3, 5, -2, -8, -6, 1, 3};

    int n=sizeof(A)/sizeof(A[0]);

    int pos=0;

    for (int i=0; i<n; i++){
        if (A[i]<0){
            
            int temp=A[i];

            for (int j=i; j>pos; j--){
                A[j]=A[j-1];
            }

            A[pos]=temp;
            pos++;
        }
    }

    for (int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;


    return 0;
}