#include <iostream>
using namespace std;

// Ordenamos por notas (descendente) y faltas (ascendente si hay empate)
void ordenarPorNota(float nota[], int codigo[], int faltas[], int n){

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (nota[j]<nota[j+1] || (nota[j]==nota[j+1] && faltas[j]>faltas[j+1])){
                swap (nota[j], nota[j+1]);
                swap (faltas[j], faltas[j+1]);
                swap (codigo[j], codigo[j+1]);
            }
        }
    }
}

// Reordenamos por codigo ascendente usamos selection sort
void ordenarPorCodigo(float nota[], int codigo[], int faltas[], int n){

    for (int i=0; i<n-1; i++){
        int minInd=i;
        for (int j=i+1; j<n; j++){
            if (codigo[j]<codigo[minInd]){
                minInd=j;
            }
        }
        swap (codigo[i], codigo[minInd]);
        swap (nota[i], nota[minInd]);
        swap (faltas[i], faltas[minInd]);
    }
}

int busquedaSecuencial (int codigo[], int n, int clave){
    for (int i=0; i<n; i++){
        if (codigo[i]==clave){
            return i;
        } 
    }
    return -1;
}

int busquedaBinaria(int codigo[], int n, int clave){
    int bajo=0, alto=n-1;
    
    while (bajo<=alto){
        int medio = (bajo+alto)/2;

        if (codigo[medio]==clave){
            return medio;
        } else if (codigo[medio]<clave){
            bajo = medio+1;
        } else {
            alto = medio-1;
        }
    }
    return -1;
}


int main (){

    int N;
    cout<<"Cantidad de estudiantes: ";
    cin>>N;

    int codigo[N];
    float nota[N], suma=0;
    int faltas[N], desaprobados=0;

    for (int i=0; i<N; i++){
        cout<<"Estudiante "<<i+1<<" (Codigo / Nota / Faltas): "<<endl;
        cin>>codigo[i]>>nota[i]>>faltas[i];
        suma+=nota[i];
        if (nota[i]<10){
            desaprobados++;
        }
    }

    ordenarPorNota (nota, codigo, faltas, N);

    cout<<"\nTop 5:"<<endl;
    for (int i=0; i<5; i++){
        cout<<"Codigo: "<<codigo[i]<<" Nota: "<<nota[i]<<endl;
    }
    cout<<"Promedio: "<<(float)suma/(float)N<<" Desaprobados: "<<desaprobados<<endl;

    int busq;

    cout<<"\nCodigo a buscar (Secuencial): ";
    cin>>busq;
    int posSec = busquedaSecuencial(codigo, N, busq);

    if (posSec!=-1){
        cout<<"Nota: "<<nota[posSec]<<" Faltas: "<<faltas[posSec]<<" Ranking: "<<posSec+1<<endl;
    } else {
        cout<<"No existe."<<endl;
    }

    ordenarPorCodigo (nota, codigo, faltas, N);

    int busq2;
    cout<<"\nCodigo a buscar (Binaria): "; 
    cin>>busq2;

    int posBin=busquedaBinaria(codigo, N, busq2);

    if (posBin!=-1){
        cout<<"Nota: "<<nota[posBin]<<" Faltas: "<<faltas[posBin]<<" Ranking: "<<posBin+1<<endl;
    } else {
        cout<<"No existe."<<endl;
    }

    return 0;
}