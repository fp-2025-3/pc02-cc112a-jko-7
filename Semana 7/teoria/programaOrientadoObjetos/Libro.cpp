#include "Libro.h"
#include <iostream>

Libro::Libro(): titulo("Desconocido"), autor("Desconocido"), paginas(0) {}

Libro::Libro(const string &t, const string &a, int p) : titulo(t), autor(a), paginas(p){}

Libro::~Libro(){}

string Libro::getTitulo() const{
    return titulo;
}

string Libro::getAutor() const{
    return autor;
}

int Libro::getPaginas() const{
    return paginas;
}

void Libro::setTitulo(const string &t){
    titulo = t;
}

void Libro::setAutor(const string &a){
    autor = a;
}

void Libro::setPaginas(int p){
    if (p>0)
        paginas = p;
}

void Libro::mostrarInfo() const {
    cout<<"Titulo: "<<titulo
        <<" Autor: "<<autor
        <<" Paginas: "<<paginas<<endl;
}