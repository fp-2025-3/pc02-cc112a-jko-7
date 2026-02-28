#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Venta
{
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

int main(){
    ifstream archivoEntrada("input/ventas.dat", ios::binary);
    ofstream archivoSalida("output/reporte.txt");

    if (!archivoEntrada)
    {
        cout << "Error no se abrio correctamente ventas.dat."<<endl;
        return 1;
    }

    if (!archivoSalida)
    {
        cout << "Error no se abrio correctamente reporte.txt."<<endl;
        return 1;
    }

    int totalRegistros=0;
    archivoEntrada.seekg(0, ios::end);
    int fin=archivoEntrada.tellg();    

    totalRegistros=fin/sizeof(Venta);

    archivoEntrada.seekg(0, ios::beg);  

    double totalPorVendedor[1000] = {0};
    int unidadesPorProducto[1000] = {0};

    double montoTotal=0;
    Venta ventasSospechosas[200];
    int totalSospechosas=0;

    double totalVenta=0;

    Venta v;

    for (int i=0; i<totalRegistros; i++)
    {
        archivoEntrada.read((char *)&v, sizeof(Venta));

        totalVenta=v.cantidad*v.precioUnitario;
        montoTotal+=totalVenta;

        // Por cada vendedor
        if (v.idVendedor >= 0)
        {
            totalPorVendedor[v.idVendedor]+=totalVenta;
        }

        // Ṕor producto
        if (v.idProducto >= 0)
        {
            unidadesPorProducto[v.idProducto]+=v.cantidad;
        }

        // Ventas sospechosas
        if (v.cantidad > 100)
        {
            ventasSospechosas[totalSospechosas++]=v; 
        }
    }

    double totalVendidoMax=0;
    int idVendedorMax=0;
    for (int i=0; i<1000; i++)
    {
        if (totalPorVendedor[i]>totalVendidoMax)
        {
            totalVendidoMax=totalPorVendedor[i];
            idVendedorMax=i;
        }
    }

    int cantidadMax = 0;
    int idProductoMax = 0;
    for (int i=0; i<1000; i++)
    {
        if (unidadesPorProducto[i]>cantidadMax)
        {
            cantidadMax=unidadesPorProducto[i];
            idProductoMax=i;
        }
    }

    archivoSalida<<"--- REPORTE GENERAL DE VENTAS ----"<<endl;
    archivoSalida<<"\nTotal de registros: "<<totalRegistros<<endl;
    archivoSalida<<"\nMONTO TOTAL VENDIDO:"<<endl;
    archivoSalida<<"S/. "<<fixed<<setprecision(2)<<montoTotal<<endl;
    archivoSalida<<"\n---------------------------------------"<<endl;
    archivoSalida<<"VENDEDOR CON MAYOR RECAUDACIÓN:"<<endl;
    archivoSalida<<"ID Vendedor: "<<idVendedorMax<<endl;
    archivoSalida<<"Total vendido: S/. " <<fixed<<totalVendidoMax<<endl;
    archivoSalida<<"\n---------------------------------------"<<endl;
    archivoSalida<<"PRODUCTO MÁS VENDIDO:"<<endl;
    archivoSalida<<"ID Producto: "<<idProductoMax<<endl;
    archivoSalida<<"Total unidades: "<<cantidadMax<<endl;
    archivoSalida<<"\n---------------------------------------"<<endl;
    archivoSalida<<"VENTAS SOSPECHOSAS (cantidad>100):"<<endl<<endl;

    for (int i=0; i<totalSospechosas; i++)
    {
        archivoSalida<<"ID Venta: "<<ventasSospechosas[i].idVenta
                    <<" | Vendedor: "<<ventasSospechosas[i].idVendedor
                    <<" | Producto: "<<ventasSospechosas[i].idProducto
                    <<" | Cantidad: "<<ventasSospechosas[i].cantidad<<endl;
    }

    archivoEntrada.close();
    archivoSalida.close();

    return 0;
}