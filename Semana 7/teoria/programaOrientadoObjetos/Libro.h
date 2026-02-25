#ifndef LIBRO_H
#define LIBRO_H
#include <string>
using namespace std; // PARA BUENAS PRACTICAS EVITAR SU USO EN .h

// defición de la clase
class Libro
{
private:
    string titulo;
    string autor;
    int paginas;
    
public:
    // Constructores
    Libro();
    Libro(const string &t,const string &a, int p);

    // Destructor
    ~Libro();

    // Accesores (getters)
    string getTitulo() const;
    string getAutor() const;
    int getPaginas() const;

    // Modificadores (setters)
    void setTitulo(const string &t);
    void setAutor(const string &a);
    void setPaginas(int p);

    void mostrarInfo() const;
};

#endif
