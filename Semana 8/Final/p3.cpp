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

    ofstream archivo("proyectos.bin", ios::binary);                 
    if (!archivo){
        cerr<<"No se pudo abrir el archivo"<<endl;
        return 1;
    }   
    
    int n;

    Proyecto* proyecto = new Proyecto[n];
    cout<<"Cuantos proyectos desea ingresar: ";
    cin>>n;

    for (int i=0; i<n; i++){
        cout<<"Proyecto "<<i+1<<endl;
        cout<<"Ingrese id: ";
        cin>>proyecto[i].id;
        cin.ignore();
        cout<<"Ingrese titulo: ";
        cin.getline(proyecto[i].titulo, 40);
        cout<<"Ingrese prepuesto: ";
        cin>>proyecto[i].presupuesto;
        cout<<"Ingrese duracion en meses: ";
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
        archivo.write((char*)(proyecto), sizeof(Proyecto));
    }        

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (proyecto[j].id == proyecto[j+1].id){
                cout<<"Error existen 2 proyectos con el mismo id."<<endl;
                return 1;
            }
        }
    }

    Proyecto nuevoProyecto;
    cout<<"Ingrese el nuevo proyecto a insertar: "<<endl;
    cout<<"Ingrese id: ";
    cin>>nuevoProyecto.id;
    cin.ignore();
    cout<<"Ingrese titulo: ";
    cin.getline(nuevoProyecto.titulo, 40);
    cout<<"Ingrese prepuesto: ";                                                

    cin>>nuevoProyecto.presupuesto;
    cout<<"Ingrese duracion en meses: ";                                        

    cin>>nuevoProyecto.duracionMeses;   


    int pos = 0;
    while (pos < n && proyecto[pos].presupuesto > nuevoProyecto.presupuesto){
        pos++;
    }       

    archivo.seekp(pos*sizeof(Proyecto), ios::beg);
    for (int i=n-1; i>=pos; i--){
        archivo.write((char*)(&proyecto[i]), sizeof(Proyecto));
    }
    archivo.write((char*)(&nuevoProyecto), sizeof(Proyecto));     
    
    
    archivo.seekp(0, ios::beg);
    cout<<"\nProyectos almacenados en el archivo: "<<endl;
    for (int i=0; i<n+1; i++){
        Proyecto p;
        // No me funciona con archivo.read((char*)(&p), sizeof(Proyecto)); 
        cout<<"Id: "<<p.id<<endl;
        cout<<"Titulo: "<<p.titulo<<endl;
        cout<<"Presupuesto: "<<p.presupuesto<<endl;
        cout<<"Duracion en meses: "<<p.duracionMeses<<endl;
    }
    
    archivo.close();
    delete[] proyecto;              

    
    return 0;
}