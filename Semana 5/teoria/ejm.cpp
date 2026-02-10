#include <iostream>
using namespace std;

// 1.DEFINICIÓN DE UNA VARIABLE DEFINIDA POR EL USUARIO
struct Estudiante
{
    int codigo; //miembros de datos
    float promedio;
    char sexo;
};


// 6. Estructuras anidadas
struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Alumno
{
    int codigo;
    Fecha nacimiento;
};

// Paso por valor (copiamos contenido)
void mostrar (Estudiante e1){
    cout<<e1.codigo;
}

// Paso por referencia (util para progresar)
void aumentarPromedio (Estudiante &e1){
    e1.promedio+=1;
}

int main (){

    // 2. Declaración de una estructura
    Estudiante e1 = {25694, 18.5, 'M'};
    Estudiante e2 = {25695, 12.5, 'F'};

    // 3. Inicialización 
    // 3.1. Inicialización directa


    // 3.2 Inicialización miembro a miembro
    Estudiante e3;

    e3.codigo = 1234;
    e3.promedio = 11.2;
    e3.sexo = 'M';

    // 3.3. Asignación entre estructuras
    Estudiante e4 = e3;

    // 4. Lectura y escritura de estructuras
    // LECTURA
    Estudiante e5;
    cout<<"Ingrese el codigo: ";
    cin>>e5.codigo;

    cout<<"Ingrese el promedio: ";
    cin>>e5.promedio;

    cout<<"Ingrese el sexo: ";
    cin>>e5.sexo;

    // ESCRITURA
    cout<<"Codigo: "<<e5.codigo<<endl;
    cout<<"Promedio: "<<e5.promedio<<endl;
    cout<<"Sexo: "<<e5.sexo<<endl;

    // 5. Arreglo de estructuras
    Estudiante A[3];        // Define un arreglo de 3 estructuras

    // Código para leer los miembros del arreglo A
    // LECTURA ARREGLO DE ESTRUCTURAS
    for (int i=0; i<3; i++){
        cout<<"\nAlumno "<<i+1<<endl;
        cout<<"Codigo: ";
        cin>>A[i].codigo;

        cout<<"\nPromedio: ";
        cin>>A[i].promedio;

        cout<<"\nSexo: ";
        cin>>A[i].sexo;
    }

    // ESCRITURA DE UN ARREGLO DE ESTRUCTURAS 
    for (int i=0; i<3; i++){
        cout<<"\nAlumno "<<i+1<<endl;
        cout<<"Codigo: ";
        cout<<A[i].codigo;

        cout<<"\nPromedio: ";
        cout<<A[i].promedio;

        cout<<"\nSexo: ";
        cout<<A[i].sexo;
    }

    cout<<endl;

    // 6. Uso de estructuras anidadas
    Alumno a1;

    // Inicializo código
    a1.codigo = 1234;

    // Inicializo Fecha
    a1.nacimiento.dia = 12;
    a1.nacimiento.mes = 10;
    a1.nacimiento.anio = 2025;


    // 7. Puntero a estructura
    Estudiante e6 = {123, 14.5, 'F'};
    Estudiante *ptr;

    ptr = &e6;     // *ptr = *&e6 = e6;

    // Acceso mediante ptr a los miembros de la estructura
    // PRIMERA FORMA (usando operador flecha ->)
    // -> solo funciona si ptr es un puntero
    cout<<ptr->codigo<<endl;
    cout<<ptr->promedio<<endl;
    cout<<ptr->sexo<<endl;


    // SEGUNDA FORMA 
    cout<<(*ptr).codigo<<endl;
    cout<<(*ptr).promedio<<endl;
    cout<<(*ptr).sexo<<endl;


    return 0;
}