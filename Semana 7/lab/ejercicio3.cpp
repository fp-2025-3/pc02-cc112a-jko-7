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

    ifstream archivoEntrada ("entradas/ventas.dat", ios::binary);
    ofstream archivoSalida ("output/reporte.txt");

    if(!archivoEntrada){
        cout<<"Error no se abrio correctamente archivoEntrada."<<endl;
        return 1;
    }

    if(!archivoSalida){
        cout<<"Error no se abrio correctamente archivoSalida."<<endl;
        return 1;
    }
   
    int totalRegistros=0;
    archivoEntrada.read((char*)&totalRegistros, sizeof(int));

    // Asumimos max 1000 (IDs del 1 al 1000)
    double totalPorVendedor[1001]={0};
    int unidadesPorProducto[1001]={0};

    double montoTotal=0;
    Venta ventasSospechosas[200];
    int totalSospechosas=0;

    double totalVenta=0;
    
    Venta v;
    
    for (int i=0; i<totalRegistros; i++){

        archivoEntrada.read((char*)&v, sizeof(Venta));

        totalVenta=v.cantidad*v.precioUnitario;
        montoTotal+=totalVenta;

        // Acumular por vendedor
        if(v.idVendedor>=0){
            totalPorVendedor[v.idVendedor]+=totalVenta;
        } 

        // Acumular por producto
        if (v.idProducto>=0){
            unidadesPorProducto[v.idProducto]+=v.cantidad;
        }

        // Ventas sospechosas
        if (v.cantidad>100){
            ventasSospechosas[totalSospechosas++] = v;
        }
    }

    // Buscar vendedor con mayor recaudación
    double totalVendidoMax=0;
    int idVendedorMax=0; 
    for (int i=0; i<1001; i++){
        if (totalPorVendedor[i]>totalVendidoMax){
            totalVendidoMax=totalPorVendedor[i];
            idVendedorMax=i;
        }
    }

    // Buscar producto más vendido por cantidad total
    int cantidadMax=0;
    int idProductoMax=0; 
    for (int i=0; i<1001; i++){
        if (unidadesPorProducto[i]>cantidadMax){
            cantidadMax=unidadesPorProducto[i];
            idProductoMax=i;
        }
    }

    archivoSalida<<"--- REPORTE GENERAL DE VENTAS ----"<<endl;
    archivoSalida<<"\nTotal de registros: "<<totalRegistros<<endl;
    archivoSalida<<"\nMONTO TOTAL VENDIDO:"<<endl;
    archivoSalida<<"S/. "<<montoTotal<<endl;
    archivoSalida<<"\n---------------------------------------"<<endl;
    archivoSalida<<"VENDEDOR CON MAYOR RECAUDACION:"<<endl;
    archivoSalida<<"ID Vendedor: "<<idVendedorMax<<endl;
    archivoSalida<<"Total vendido: S/. "<<totalVendidoMax<<endl;
    archivoSalida<<"\n---------------------------------------"<<endl;
    archivoSalida<<"PRODUCTO MÁS VENDIDO:"<<endl;
    archivoSalida<<"ID Producto: "<<idProductoMax<<endl;
    archivoSalida<<"Total unidades: "<<cantidadMax<<endl;
    archivoSalida<<"\n---------------------------------------"<<endl;
    archivoSalida << "VENTAS SOSPECHOSAS (cantidad > 100):" <<endl<<endl;

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