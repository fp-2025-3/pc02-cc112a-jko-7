#include <iostream>
#include <fstream>
using namespace std;

struct Venta {
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

int main (){

    ifstream archivoEntrada ("entrada/ventas.dat", ios::binary);
    ofstream archivoSalida ("output/reporte.txt");

    if(!archivoEntrada || !archivoSalida){
        cout<<"Error no se abrio correctamente."<<endl;
        return 1;
    }

    float montoTotal=0;
    float totalVenta=0;
    float totalVendidoMax=0;
    int idVendedorMax=0;    
    int cantidadMax=0;
    int idProductoMax=0; 
    int totalRegistros=0;

    archivoEntrada.read((char*)&totalRegistros, sizeof(int));

    Venta v;
    Venta ventasSospechosas[100];
    int totalSospechosas=0;

    for (int i=0; i<totalRegistros; i++){

        archivoEntrada.read((char*)&v, sizeof(Venta));

        totalVenta=v.cantidad*v.precioUnitario;
        montoTotal+=totalVenta;


        if(totalVendidoMax<totalVenta){
            totalVendidoMax=totalVenta;
            idVendedorMax=v.idVendedor;
        } 

        if (cantidadMax<v.cantidad){
            cantidadMax=v.cantidad;
            idProductoMax=v.idProducto;
        }

        if (v.cantidad>100 && totalSospechosas<100){
            ventasSospechosas[totalSospechosas++] = v;
        }
        
    }
    

    archivoSalida<<"--- REPORTE GENERAL DE VENTAS ----"<<endl;
    archivoSalida<<"\nTotal de registros: "<<totalRegistros<<endl;
    archivoSalida<<"\nMONTO TOTAL VENDIDO:"<<endl;
    archivoSalida<<"S/. "<<montoTotal<<endl;
    archivoSalida<<"\n---------------------------------"<<endl;
    archivoSalida<<"VENDEDOR CON MAYOR RECAUDACION:"<<endl;
    archivoSalida<<"ID Vendedor: "<<idVendedorMax<<endl;
    archivoSalida<<"Total vendido: S/. "<<totalVendidoMax<<endl;
    archivoSalida<<"\n---------------------------------"<<endl;
    archivoSalida<<"PRODUCTO MÁS VENDIDO:"<<endl;
    archivoSalida<<"ID Producto: "<<idProductoMax<<endl;
    archivoSalida<<"Total unidades: "<<cantidadMax<<endl;
    archivoSalida<<"\n---------------------------------"<<endl;
    archivoSalida << "VENTAS SOSPECHOSAS (cantidad > 100):" << endl;

    for (int i = 0; i < totalSospechosas; i++) {
        archivoSalida << "ID Venta: " << ventasSospechosas[i].idVenta
                      << " | Vendedor: " << ventasSospechosas[i].idVendedor
                      << " | Producto: " << ventasSospechosas[i].idProducto
                      << " | Cantidad: " << ventasSospechosas[i].cantidad << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();

    return 0;
}