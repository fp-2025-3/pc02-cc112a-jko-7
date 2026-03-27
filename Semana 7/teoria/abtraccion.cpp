#include <iostream>
using namespace std;

class Libro
{
private:
    string titulo;
    string autor;
    int paginas;

    // void numeroCuenta();
    
public:
    // constructor con parámetros
    Libro(string t, string a, int p):titulo(t), autor(a), paginas(p) {
        cout<<"Se ejecuto el constructor con parametros\n";
    };

    // Constructor por defecto
    Libro(){
        cout<<"Contructor por defecto"<<endl;
    };

    // Destructor por defecto
    ~Libro(){
        cout<<"Llamando al destructor\n";
    };

    // getter
    string getTitulo() const{ // buena practica
        return titulo;
    }

    // setter
    void setTitulo(string t){
        titulo = t;
    }

    void mostrarInfo (){
        cout<<"Titulo: "<<titulo<<", Autor: "<<autor<<", Paginas: "<<paginas;
    }

};

int main (){

    Libro libro1("El principito", "Antoine", 100);
    Libro libro2("Don Quijote", "Cervantes", 800);
    
    // Cada objeto tiene su propio estado
    libro1.mostrarInfo();
    libro2.mostrarInfo();

    libro1.setTitulo("El principito - Nueva edicion");
    cout<<"Despues de cambiar el titulo";
    libro1.mostrarInfo();
    libro2.mostrarInfo();

    return 0;
}



