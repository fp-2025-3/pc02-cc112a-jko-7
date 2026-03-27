#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LIBROS = 100;


struct Libro
{
    int codigo;
    char titulo[50];
    bool prestado;
};

struct Usuario
{
    int codigo;
    string nombre;
    int prestamo;
};


// Funciones a implementar
void registrarUsuario ();

void registrarLibro (Libro libros[], int &n){

    if (n >= MAX_LIBROS){
        cout<<"Capacidad máxima alcanzada\n";
        return;
    }

    cout<<"Codigo: ";
    cin>>libros[n].codigo;
    cin.ignore();
    cout<<"Titulo: ";
    cin.getline(libros[n].titulo, 50);
    libros[n].prestado=false;
    cout<<"Prestado: false";    

    n++;    // actualiza la cantidad de libros    
}

int buscarLibro (Libro libros[], int n, int codigo);
void prestarLibro (Libro libros[], int n);
void devolverLibro (Libro libros[], int n);
void guardarEnArchivo (Libro libros[], int n);
void cargarDesdeArchivo (Libro libros[], int n);
void mostrarLibros (Libro libros[], int n);


int main(){

    // Menu interactivo
    Libro libros[MAX_LIBROS];
    int cantidad = 0;
    int opcion;

    do
    {
        cout<<"\n=============================="<<endl;
        cout<<"    SISTEMA DE BIBLIOTECA     "<<endl;
        cout<<"=============================="<<endl;
        cout<<"1. Registrar libro"<<endl;
        cout<<"2. Prestar libro"<<endl;
        cout<<"3. Devolver libro"<<endl;
        cout<<"4. Buscar libro"<<endl;
        cout<<"5. Guardar archivo (binario)"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Ingrese una opcion: "<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            /* code */
            break;

        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;

        case 5:
            /* code */
            break;

        case 6:
            cout<<"Saliendo.........."<<endl;
            break;
        
        default:
            cout<<"Opcion invalida."<<endl;
            break;
        }


    } while (opcion!=6);
    

    return 0;
}
