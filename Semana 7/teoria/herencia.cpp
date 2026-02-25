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

// HERENCIA

class LibroDigital : public Libro
{
private:
    string formato; // PDF, EPUB..    

public:

    // No se heredan constructores
    LibroDigital(string t, string a, int p, string f):Libro(t,a,p),formato(f){}

    void mostrarInfoDigital(){
        mostrarInfo();
        cout<<"Formato digital "<<formato<<endl;        
    }
};

int main (){

    LibroDigital ld("Cien años de soledad", "Marquez", 400, "PDF");

    ld.mostrarInfoDigital();

    return 0;
}



