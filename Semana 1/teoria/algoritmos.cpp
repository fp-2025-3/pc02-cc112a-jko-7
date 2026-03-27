#include <iostream>

using namespace std;

// selectionSort 
// hay swap

void selectionSort (int A[], int n){

    for (int i=0; i<n-1; i++){

        int indMin=i;
        for (int j=i+1; j<n; j++){

            if (A[j]<A[indMin]){
                indMin=j;
            }
        }
        swap (A[i], A[indMin]);
    }
}


// insertionSort
// no hay swap
// primero va el for
// luego se declara el temp=A[i] y int j=i-1;
// usa while con j>=0 && A[j]>temp  (while tambien usa merge y busquedabinaria)
// dentro del while: A[j+1]=A[j] y j--;
// Fuera: A[j+1]=temp (inserta)
// basicamente dentro de las estructuras de control se manipula j

void insertionSort (int A[], int n){

    for (int i=1; i<n; i++){

        int temp=A[i];
        int j=i-1;

        while (j>=0 && A[j]>temp){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
    }
}

// quickSort
// no usa while, ni hay variable medio se usa 2 swap
// primero se declaran pivot=A[fin] y int i=inicio-1
// se usa if con A[j]<=pivot y dentro esta i++ y swap (A[i], A[j])
// luego de 2 parentesis esta swap de A[i+1],A[fin] y return i+1
// el i dentro de if va aumentan i++

int particion (int A[], int inicio, int fin){

    int pivot = A[fin];
    int i=inicio-1;

    for (int j=inicio; j<fin; j++){
        if (A[j]<=pivot){
            i++;
            swap (A[i], A[j]);
        }
    }
    swap (A[i+1], A[fin]);
    return i+1;

}

void quickSort (int A[], int inicio, int fin){

    if (inicio<fin){
        int indPiv=particion(A, inicio, fin);

        quickSort (A, inicio, indPiv-1);
        quickSort (A, indPiv+1, fin);
    }
}


// mergeSort 
// usa 3 while 
// el 1 while con i<n1 && j<n2 y dentro esta if(L[i]<=R[j])

void merge (int A[], int inicio, int medio, int fin){

    int n1=medio-inicio+1;
    int n2=fin-medio;

    int L[100], R[100];

    for (int i=0; i<n1; i++){
        L[i]=A[inicio+i];
    }

    for (int j=0; j<n2; j++){
        R[j]=A[medio+j+1];
    }

    int i=0, j=0, k=inicio;

    while (i<n1 && j<n2){  // AQUI &&

        if (L[i]<=R[j]){  // AQUI CUIDADO <=
            A[k]=L[i];
            i++;
        } else {
            A[k]=R[j];
            j++;
        }
        k++;
    }
    
    while (i<n1){
        A[k]=L[i];
        i++;
        k++;
    }

    while (j<n2){
        A[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort (int A[], int inicio, int fin){

    if (inicio<fin){

        int medio=inicio+(fin-inicio)/2;

        mergeSort (A, inicio, medio);
        mergeSort (A, medio+1, fin);
        merge (A, inicio, medio, fin);

    }
}

// busquedaBinaria
// OJO: hacer busquedaBinaria una vez este ordenado
// primero se declara el inicio fin medio ningun otro algoritmo hace eso
// while (inicio<=fin)

int busquedaBinaria (int A[], int n, int x){

    int inicio=0, fin=n-1, medio;

    while (inicio<=fin){

        medio = inicio + (fin-inicio)/2;

        if (A[medio]==x){
            return medio;
        } else if(A[medio]<x){
            inicio=medio+1;
        } else {
            fin=medio-1;
        }
    }
    
    return -1;
}

