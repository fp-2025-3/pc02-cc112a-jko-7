#include <iostream>
using namespace std;

void imprimir(const int* inicio, const int* fin){

    while(inicio<fin){

        cout<<*inicio<<" ";
        inicio++;

    }
    cout<<endl;

    /*
    tambien puede ser 
     for (const int *ptr=inicio; ptr<fin; ptr++){
        cout<<*ptr<<" ";
    }
    
    cout<<endl;
    */
}

int* buscarPrimerNegativo(int* inicio, int* fin){

    while (inicio<fin)
    {
        if (*inicio<0){
            return inicio;
        }
        inicio++;

    }
    return inicio;

    /*
    for (int *ptr=inicio; ptr<fin; ptr++){
        if (*ptr<0){
            return ptr;
        } 
    }

    return fin;
    */
}


int* buscarMenorNegativo(int* inicio, int* fin){

    int* min = inicio;

    while (inicio<fin)
    {
        if (*inicio<0 && *min>*inicio){
            min=inicio;
        }
        inicio++;
    }
    return min;
}

void intercambiar(int* a, int* b){

    swap(*a,*b);
}

void invertir(int* inicio, int* fin){

    while (inicio<fin)
    {   
        swap(*inicio,*fin);
        inicio++;
        fin--;
    }
}

int* maxAbsoluto(int* inicio, int* fin){

    int* max=inicio;

    while (inicio<fin)
    {   

        // int valActual = (*ptr<0)? -(*ptr):*ptr
        // int valMaximo = (*maxPtr<0)? -(*maxPtr):*maxPtr

        // if (valActual>valMaximo){
        //    maxPtr = ptr;
        // }


        if (abs(*max)<abs(*inicio)){
            max=inicio;
        }
        inicio++;
    }
    return max;
}

int* subarregloMaximoInicio(int* inicio, int* fin){

    int ultimaSuma = 0; // acumular ultima suma
    int sumaMax = *inicio; // asumo que el primer elemento es la sumaMax
    int* finMaxSubarray = inicio + 1;

    for (int *p = inicio; p < fin; ++p) {
        ultimaSuma += *p;

        if (ultimaSuma > sumaMax) {
            sumaMax = ultimaSuma;
            finMaxSubarray = p + 1;
        }
    }

    return finMaxSubarray;
}




int main (){

    int datos[] = {3, -2, 5, 7, -4, 10, -6, 1};

    int n=sizeof(datos)/sizeof(datos[0]);

    imprimir (datos, datos+n);

    int *ptr=buscarPrimerNegativo(datos, datos+n);
    cout<<*ptr<<endl;

    int *ptr2=buscarMenorNegativo(datos, datos+n);
    cout<<*ptr2<<endl;

    int* ptr4=subarregloMaximoInicio(datos, datos+n);
    cout << "Subarreglo de suma máxima desde el inicio:" << endl;
    imprimir(datos, ptr4);


    intercambiar (datos+3, datos+5);
    imprimir (datos, datos+n);

    invertir (datos, datos+n-1);
    imprimir (datos, datos+n);

    int *ptr3=maxAbsoluto(datos, datos+n);
    cout<<*ptr3<<endl;

    

    return 0;
}
