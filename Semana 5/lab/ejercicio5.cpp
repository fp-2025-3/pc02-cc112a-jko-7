#include <iostream>
#include <string>
using namespace std;

struct Proceso
{
    int id;
    string nombre;
    float consumoMemoria;
    Proceso* sig;
};

struct ListaProcesos
{
    Proceso* cabeza;
};

// 1. Inicializar
void inicializarLista(ListaProcesos &lista){
    lista.cabeza = nullptr;
}

// 2. Insertar al inicio
void insertarAlInicio(ListaProcesos &lista, int id, string nombre, float memoria){
    Proceso* nuevo = new Proceso;
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->consumoMemoria = memoria;
    nuevo->sig = lista.cabeza;
    lista.cabeza = nuevo;
}

// 3. Insertar al final
void insertarAlFinal(ListaProcesos &lista, int id, string nombre, float memoria){
    Proceso* nuevo = new Proceso;
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->consumoMemoria = memoria;
    nuevo->sig = nullptr;

    Proceso* aux = lista.cabeza;
    while (aux->sig != nullptr){
        aux = aux->sig;
    }
    aux->sig = nuevo;
}

void mostrarProcesos(ListaProcesos lista){
    Proceso* aux = lista.cabeza;
    while (aux != nullptr){
        cout<<aux->id<<" "<<aux->nombre<<" "<<aux->consumoMemoria<<endl;
        aux = aux->sig;
    }
}

void buscarProceso(ListaProcesos lista, int id){
    Proceso* aux = lista.cabeza;
    while(aux != nullptr){
        if (aux->id == id){
            cout<<"Encontrado"<<endl;
            return;
        }
        aux = aux->sig;
    }
}

void eliminarProceso(ListaProcesos &lista, int id){
    if (lista.cabeza->id == id){
        Proceso* temp = lista.cabeza;
        lista.cabeza = lista.cabeza->sig;
        delete temp;
    }
}

int contarProcesos(ListaProcesos lista){
    int cont = 0;
    Proceso* aux = lista.cabeza;
    while (aux != nullptr){
        cont++;
        aux = aux->sig;
    }
    return cont;
}

void insertarOrdenado(ListaProcesos &lista, int id, string nombre, float memoria) {
    Proceso* nuevo = new Proceso;
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->consumoMemoria = memoria;
    nuevo->sig = lista.cabeza;
    lista.cabeza = nuevo;
}

void liberarLista(ListaProcesos &lista) {
    while (lista.cabeza != nullptr) {
        Proceso* temp = lista.cabeza;
        lista.cabeza = lista.cabeza->sig;
        delete temp;
    }
}

int main (){
    ListaProcesos sistema;
    
    inicializarLista(sistema);
    
    insertarAlInicio(sistema, 101, "Navegador", 512.5);
    insertarAlInicio(sistema, 102, "Editor", 128.3);
    insertarAlInicio(sistema, 103, "Reproductor", 256.7);
    
    insertarAlFinal(sistema, 104, "Antivirus", 1024.0);
    insertarAlFinal(sistema, 105, "Email", 64.2);
    
    mostrarProcesos(sistema);
    buscarProceso(sistema, 102);
    eliminarProceso(sistema, 103);
   
    cout << "Total: " << contarProcesos(sistema) << endl;
   
    insertarOrdenado(sistema, 106, "Calc", 32.5);
    mostrarProcesos(sistema);
    
    
    liberarLista(sistema);

    return 0;
}