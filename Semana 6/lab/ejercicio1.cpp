#include <iostream>
#include <fstream>
using namespace std;

const int DIAS = 7;

int main (){

    // abrimos un archivo en modo escritura y append
    ofstream archivo("output/ventas.txt", ios::app);

    if (!archivo){
        cout<<"Error al abrir el archivo"<<endl;
        return 1;
    }

    double total=0.0;
    double mayorVenta;
    double menorVenta;

    double venta;
    for (int i=1; i<=DIAS; i++){
        cout<<"Ingrese la venta del dia "<<i<<": ";
        cin>>venta;

        archivo<<venta<<endl;
        total+=venta;

        if (i==1){
            mayorVenta=venta;
            menorVenta=venta;
        } else {
            if (venta > mayorVenta) {
                mayorVenta = venta;
            }

            if (venta < menorVenta) {
                menorVenta = venta;
            }
        }
    }

    double promedio = total/DIAS;

    archivo<<"----------------------"<<endl;
    archivo<<"RESUMEN"<<endl;
    archivo<<"Total: "<<total<<endl;
    archivo<<"Promedio: "<<promedio<<endl;
    archivo<<"Mayor venta: "<<mayorVenta<<endl;
    archivo<<"Menor venta: "<<menorVenta<<endl;

    archivo.close();

    return 0;
}