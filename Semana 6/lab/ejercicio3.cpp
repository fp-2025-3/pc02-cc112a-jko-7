#include <iostream>
#include <fstream>
using namespace std;

struct Producto {
    int id;                  // Identificador único
    char nombre[30];         // Nombre del producto
    double precio;           // Precio unitario
    int stock;               // Cantidad disponible
    bool activo;             // true = activo, false = eliminado lógicamente
};
// [P1][P2][P3].....[Pn]

int buscarProductoPorID(const char* nombreArchivo, int idBuscado){

    // Como vamos a buscar un producto en un archivo binario instanciamos la clase ifstream
    ifstream archivo(nombreArchivo, ios::binary);

    if (!archivo){
        cout<<"Error al abrir el archivo"<<endl;
        return -1;
    }

    Producto p;
    int posicion=0;

    while(archivo.read((char*)&p, sizeof(Producto))){
        if (p.id == idBuscado){
            archivo.close();
            return posicion;
        }
        posicion++;
    }

    archivo.close();
    return -1;
}

void registrarProducto(const char* nombreArchivo){
    Producto p;

    cout<<"Ingrese ID: ";
    cin>>p.id;

    // No debe haber IDs repetidos
    if (buscarProductoPorID(nombreArchivo, p.id) != -1){
        cout<<"ERROR, el ID ya existe"<<endl;   // cout
        return;
    }

    cin.ignore();   // limpiamos el buffer
    cout<<"Ingrese el nombre: ";
    cin.getline(p.nombre, 30);

    do
    {
        cout<<"Ingrese el precio: ";
        cin>>p.precio;
        if (p.precio <= 0){
            cout<<"Precio invalido"<<endl;
        }
    } while (p.precio <= 0);
    
    do
    {
        cout<<"Ingrese el stock: ";
        cin>>p.stock;
        if (p.stock < 0){
            cout<<"Stock invalido"<<endl;
        }
    } while (p.stock < 0);

    p.activo = true;

    // USAMOS ARCHIVOS BINARIOS

    // Paso 1: instanciar un objeto de la clase ofstream y activar el modo binario
    ofstream archivo(nombreArchivo, ios::binary | ios::app);

    if (!archivo){
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }

    // Paso 2: Escribir en el archivo binario
    archivo.write((char*)&p, sizeof(Producto)); //archivo.write(reinterpret_cast<char*>(&p),sizeof(Producto))

    archivo.close();

    cout<<"Producto registrado correctamente"<<endl;
}

void mostrarProductos(const char* nombreArchivo){

    ifstream archivo (nombreArchivo, ios::binary);

    if (!archivo){
        cout<<"No se abrio correctamente"<<endl;
        return;
    }
    
    Producto p;
    int posicion = 0;
    bool hayActivos = false;      // flag para saber si hubo activos

    cout<<"\n--- LISTA DE PRODUCTOS ACTIVOS ---"<<endl;

    while(archivo.read((char*)&p, sizeof(Producto))){
        if (p.activo){
            cout<<"Posicion "<<posicion<<": "<<endl;
            cout<<"ID: "<<p.id<<endl;
            cout<<"Nombre: "<<p.nombre<<endl;
            cout<<"Precio: "<<p.precio<<endl;
            cout<<"Stock: "<<p.stock<<endl;
            cout<<"--------------------------"<<endl;
            hayActivos = true;
        } 
        posicion++;
    } 

    if (!hayActivos){
        cout<<"No hay productos activos."<<endl;
    }

    archivo.close(); 
}

void modificarPrecio(const char* nombreArchivo, int id, double nuevoPrecio){

    // Validar nuevoPrecio
    if (nuevoPrecio <= 0){
        cout<<"Precio invalido"<<endl;
        return;
    }

    int posicion = buscarProductoPorID(nombreArchivo, id);

    if (posicion == -1){
        cout<<"Producto no encontrado"<<endl;
        return;
    }

    // Paso 1: Creamos un objeto fstream (para lectura y escritura)
    fstream archivo (nombreArchivo, ios::binary | ios::in | ios::out);

    if (!archivo){
        cout<<"No se abrio correctamente"<<endl;
        return;
    }

    // PARTE DE ACCESO ALEATORIO (leemos, modificamos algun dato, escribimos)
    // Mover el ptr de lectura: seekg();
    Producto p;

    archivo.seekg(posicion*sizeof(Producto), ios::beg);

    // Leemos el producto en posicion
    archivo.read((char*)&p, sizeof(Producto));

    // Comprobamos si el producto fue eliminado logicamente
    if (!p.activo){
        cout<<"El producto fue eliminado, no se puede modificar"<<endl;
        archivo.close();
        return;
    }

    // Actualizamos el precio
    p.precio = nuevoPrecio;

    // Mover el ptr de escritura seekp();
    archivo.seekp(posicion*sizeof(Producto), ios::beg);
    archivo.write((char*)&p, sizeof(Producto));
    archivo.close();

    cout<<"Se modifico el precio correctamente"<<endl;
}

void eliminarProducto(const char* nombreArchivo, int id){

    int posicion = buscarProductoPorID(nombreArchivo, id);

    if (posicion == -1){
        cout<<"Producto no encontrado"<<endl;
        return;
    }

    // Abrimos en modo lectura y escritura
    fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);

    if (!archivo){
        cout<<"No se abrio correctamente"<<endl;
        return;
    }

    // Nos posicionamos sobre el producto
    Producto p;
    archivo.seekg(posicion*sizeof(Producto), ios::beg);
    archivo.read((char*)&p, sizeof(Producto));

    // Verificamos que no este ya eliminado
    if (!p.activo){
        cout<<"El producto ya estaba eliminado"<<endl;
        archivo.close();
        return;
    }

    // Solo cambiamos el campo activo a false (baja logica)
    p.activo = false;

    // Volvemos a la posicion del registro y escribimos
    archivo.seekp(posicion*sizeof(Producto), ios::beg);
    archivo.write((char*)&p, sizeof(Producto));
    archivo.close();

    cout<<"Producto eliminado correctamente"<<endl;
}

double calcularValorInventario(const char* nombreArchivo){

    ifstream archivo (nombreArchivo, ios::binary);

    if (!archivo){
        cout<<"No se abrio correctamente"<<endl;
        return 0.0;
    }

    Producto p;
    double total=0;

    // Recorremos todos los registros sumando precio*stock de los activos
    while(archivo.read((char*)&p, sizeof(Producto))){
        if (p.activo){
            total+=p.precio*p.stock;
        }
    }

    archivo.close();
    return total;
}

int main (){

    const char* nombreArchivo = "inventario.dat";
    int opcion;

    do
    {
        cout<<"\n=============================="<<endl;
        cout<<"    SISTEMA DE INVENTARIO     "<<endl;
        cout<<"=============================="<<endl;
        cout<<"1. Registrar producto"<<endl;
        cout<<"2. Mostrar productos"<<endl;
        cout<<"3. Buscar producto"<<endl;
        cout<<"4. Modificar precio"<<endl;
        cout<<"5. Eliminar producto"<<endl;
        cout<<"6. Calcular valor total"<<endl;
        cout<<"7. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            registrarProducto(nombreArchivo);
            break;

        case 2:
            mostrarProductos(nombreArchivo);
            break;

        case 3:
        {
            int id;
            cout<<"Ingrese ID a buscar: ";
            cin>>id;
            int pos = buscarProductoPorID(nombreArchivo, id);
            if (pos != -1){
                cout<<"Producto encontrado en posicion"<<pos<<endl;
            } else {
                cout<<"Producto no encontrado"<<endl;
            }

            break;
        }

        case 4:
        {
            int id;
            double precio;
            cout<<"Ingrese ID: ";
            cin>>id;
            cout<<"Ingrese nuevo precio: ";
            cin>>precio;
            modificarPrecio(nombreArchivo,id, precio);
            break;
        }

        case 5:
        {
            int id;
            cout<<"Ingrese ID a eliminar: ";
            cin>>id;
            eliminarProducto(nombreArchivo,id);
            break;
        }

        case 6:
        {
            double total = calcularValorInventario(nombreArchivo);
            cout<<"Valor total del inventario: $"<<total<<endl;
            break;
        }

        case 7:
            cout<<"Saliendo del programa........."<<endl;
            break;
        
        default:
            cout<<"Opcion invalida."<<endl;
            break;
        }




    } while (opcion!=7);
    
    return 0;
}