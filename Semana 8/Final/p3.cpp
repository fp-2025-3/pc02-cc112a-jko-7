#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Proyecto
{
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMeses;
};


int main (){

    fstream archivo("proyectos.bin", ios::binary | ios::in | ios::out | ios::trunc);                 
    if (!archivo){
        cerr<<"No se pudo abrir el archivo"<<endl;
        return 1;
    }   
    
    int n;
    cout<<"Numero de proyectos: ";
    cin>>n;

    Proyecto* proyecto = new Proyecto[n];
    
    for (int i=0; i<n; i++){
        cout<<"\nProyecto "<<i+1<<endl;
        cout<<"ID: ";
        cin>>proyecto[i].id;
        cin.ignore();
        cout<<"Titulo: ";
        cin.getline(proyecto[i].titulo, 40);
        cout<<"Prepuesto: ";
        cin>>proyecto[i].presupuesto;
        cout<<"Duracion (meses): ";
        cin>>proyecto[i].duracionMeses;   
    }

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (proyecto[j].presupuesto < proyecto[j+1].presupuesto){
                swap(proyecto[j], proyecto[j+1]);
            }
        }
    }

    for (int i=0; i<n; i++){
        archivo.write((char*)(&proyecto[i]), sizeof(Proyecto));
    }        

    Proyecto nuevoProyecto;
    cout<<"\nNuevo proyecto a insertar"<<endl;
    cout<<"ID: ";
    cin>>nuevoProyecto.id;
    cin.ignore();
    cout<<"Titulo: ";
    cin.getline(nuevoProyecto.titulo, 40);
    cout<<"Prepuesto: ";
    cin>>nuevoProyecto.presupuesto;
    cout<<"Duracion: "; 
    cin>>nuevoProyecto.duracionMeses;   

    // Verificar si hay IDs duplicados 
    bool duplicado = false;
    for (int i=0; i<n; i++){
        if (proyecto[i].id == nuevoProyecto.id){
            duplicado=true;
            break;
        }
    }

    if (duplicado){
        cout<<"Error: ya existe un proyecto con el mismo ID. No se insertara." << endl;
        archivo.close();
        delete[] proyecto;
        return 1;
    }

    int pos = 0;
    while (pos < n && proyecto[pos].presupuesto > nuevoProyecto.presupuesto){
        pos++;
    }       

    // Desplazar registros hacia adelante usando acceso aleatorio (sin archivo auxiliar)
    // Mover de atras hacia adelante para no sobrescribir
    Proyecto temp;
    for (int i = n - 1; i >= pos; i--) {
        // Leer registro en posicion i
        archivo.seekg(i * sizeof(Proyecto), ios::beg);
        archivo.read((char*)(&temp), sizeof(Proyecto));
        // Escribir en posicion i+1
        archivo.seekp((i + 1) * sizeof(Proyecto), ios::beg);
        archivo.write((char*)(&temp), sizeof(Proyecto));
    }
    
    // Escribir nuevo proyecto en su posicion correcta
    archivo.seekp(pos * sizeof(Proyecto), ios::beg);
    archivo.write((char*)(&nuevoProyecto), sizeof(Proyecto));

    archivo.seekg(0, ios::beg);
    cout<<"\nContenido del archivo"<<endl;
    Proyecto p;
    int total = n + 1;
    for (int i = 0; i < total; i++) {
        archivo.read((char*)(&p), sizeof(Proyecto));
        cout << p.id << " " << p.titulo << " "
             << p.presupuesto << " " << p.duracionMeses << endl;
    }
    archivo.close();
    delete[] proyecto;              

    return 0;
}