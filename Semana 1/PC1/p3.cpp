#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int particion (double A[], int inicio, int fin){

    double pivot = A[fin];
    int i=inicio-1;

    for (int j=inicio; j<fin; j++){

        if (A[j]>pivot){

            i++;
            swap (A[i], A[j]);          
        }
    }
    swap (A[i+1], A[fin]);
    return i+1;


}

void quickSort (double A[], int inicio, int fin){

    if (inicio<fin){

        int indPiv = particion (A, inicio, fin);

        quickSort (A, inicio, indPiv-1);
        quickSort (A, indPiv+1, fin);

    }
}


int main (){

    int N;

    do
    {
        cout<<"Ingrese cantidad de alumnos (5-30): ";
        cin>>N;

    } while (N<5 || N>30);

    int notas [30][5];
    double promedios [30];
    double promediosCopia [30];
    char estados [30];


    srand (time(0));

    for (int i=0; i<N; i++){
        double sum=0;
        for (int j=0; j<5; j++){
            notas[i][j]= rand()%21;
            sum+=notas[i][j];
        }
        promedios[i]=sum/5.0;
        promediosCopia[i]=promedios[i];
    }

    int cont=0;
    double sumatotal=0;
    double sumaAp=0;

    for (int i=0; i<N; i++){
        sumatotal+=promedios[i];
        if (promedios[i]>=10){
            sumaAp+=promedios[i];
            estados[i]='A';
            cont++;
        } else {
            estados[i]='D';
        }
    }

    double promedioG=sumatotal/N; 

    double promedioA;
    if (cont==0){
        promedioA=0;
    } else {
        promedioA=sumaAp/cont;
    }
    
    int maxNota = notas[0][0];
    int minNota = notas[0][0];

    for (int i=0; i<N; i++){
        for (int j=0; j<5; j++){

            if (maxNota < notas[i][j]){
                maxNota = notas[i][j];
            }

            if (minNota > notas[i][j]){
                minNota = notas[i][j];
            }
        }
    }

    cout<<"\nPromedio general de la clase: "<<promedioG<<endl;
    cout<<"Cantidad de aprobados: "<<cont<<endl;
    cout<<"Nota maxima: "<<maxNota<<endl;
    cout<<"Nota minima: "<<minNota<<endl;
    cout<<"Promedio de aprobados: "<<promedioA;

    cout<<"\n\n--- LISTA ORIGINAL ---"<<endl;
    cout<<"Alumnos\tPromedio\tEstado\tNotas"<<endl;
    cout<<"---------------------------------------"<<endl;
    
    for (int i=0; i<N; i++){
        cout<<"A"<<i+1<<"\t"<<promedios[i]<<"\t\t"<<estados[i]<<"\t";
        for (int j=0; j<5; j++){
            cout<<notas[i][j];
            if (j<4) cout<<", ";  // Si no es la última nota, pone coma
        }
        cout<<endl;
    }

    quickSort (promedios, 0, N-1);


    for (int i=0; i<N; i++){
        for (int j=0; j<N-i-1; j++){

            if (promediosCopia[j]<promediosCopia[j+1]){

                swap(promediosCopia[j], promediosCopia[j+1]);

                for (int k=0; k<5; k++){
                    swap(notas[j+1][k], notas[j][k]);

                }
            }
        }
    }


    cout<<"\n--- LISTA ORDENADA POR PROMEDIO (DESCENDENTE) ---"<<endl;
    cout<<"Alumnos\tPromedio\tEstado\tNotas"<<endl;
    cout<<"---------------------------------------"<<endl;
    
    for (int i=0; i<N; i++){
        cout<<"A"<<i+1<<"\t"<<promedios[i]<<"\t\t"<<(promedios[i]>=10?'A':'D')<<"\t";
        for (int j=0; j<5; j++){
            cout<<notas[i][j];  
            if (j<4) cout<<", ";
        }
        cout<<endl;
    }


    return 0;
}