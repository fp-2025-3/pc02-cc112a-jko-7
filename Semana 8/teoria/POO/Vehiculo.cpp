#include <Vehiculos.h>

// Imlementación base
Vehiculo::Vehiculo(){
    cout<<"Llamando al constructor por defecto"<<endl;    
}

Vehiculo::Vehiculo(string p, string m, int a, double pv):placa(p), marca(m), anio(a), precioVenta(pv){}



