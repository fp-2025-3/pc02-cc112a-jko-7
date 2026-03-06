#include <iostream>
#include <fstream>
using namespace std;

struct CuentaBancaria
{
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa; 
};

int calcularPosicion(int numeroCuenta){

    return sizeof(CuentaBancaria)*(numeroCuenta-1);
}

void crearArchivo(int N){

    fstream archivo ("cuentas.dat", ios::binary | ios::in | ios::out);

    if (!archivo){
        // Si no existe lo creamos
        archivo.open("cuentas.dat", ios::binary | ios::out);
        archivo.close();
        archivo.open("cuentas.dat", ios::binary | ios::in | ios::out);
    }

    CuentaBancaria cuenta;
    
    for (int i=0; i<N; i++){

        cout<<"Numero de cuenta "<<i+1<<endl;
        cin>>cuenta.numeroCuenta;

        int posicion = calcularPosicion(cuenta.numeroCuenta);

        // Movemos el puntero de lectura (seekg) a posicion
        archivo.seekg(posicion);

        // Creamos un objeto temporal para verificar si hay registros en esa posicion
        CuentaBancaria temp;
        archivo.read((char*)&temp, sizeof(CuentaBancaria));

        if (archivo && temp.numeroCuenta == cuenta.numeroCuenta){
            cout<<"Ya existe una cuenta con ese numero\n";
            i--;
        } else {
            // Si fallo la lectura, debemos reestablecer los valores de archivo
            archivo.clear();

            // mover el puntero de escritura
            archivo.seekp(posicion);

            cout<<"Titular: ";
            cin.ignore();
            cin.getline(cuenta.titular, 40);
            cout<<"Saldo: ";
            cin>>cuenta.saldo;
            cuenta.activa=true;

            archivo.write((char*)&cuenta, sizeof(CuentaBancaria));
        }

        // No se pueden repetir numero de cuentas
    }

    archivo.close();
}

void buscarCuenta(){
    fstream archivo("cuentas.dat", ios::binary | ios::in);

    if (!archivo) {
        cout << "Error al abrir el archivo."<<endl;
        return;
    }

    int numCuenta;
    cout << "Numero de cuenta a buscar: ";
    cin >> numCuenta;

    archivo.seekg(calcularPosicion(numCuenta));
    CuentaBancaria c;
    archivo.read((char*)&c, sizeof(CuentaBancaria));

    if (!archivo || c.numeroCuenta != numCuenta) {
        cout << "✗ Cuenta no encontrada.\n";
    } else {
        cout << "\n=== Cuenta encontrada ===\n";
        cout << "Numero : " << c.numeroCuenta << "\n";
        cout << "Titular: " << c.titular      << "\n";
        cout << "Saldo  : $" << c.saldo       << "\n";
        cout << "Estado : " << (c.activa ? "Activa" : "Inactiva") << "\n";
    }

    archivo.close();
}

void operacion(){
    fstream archivo("cuentas.dat", ios::binary | ios::in | ios::out);

    if (!archivo) {
        cout << "Error al abrir el archivo."<<endl;
        return;
    }

    int numCuenta;
    cout<<"Numero de cuenta: ";
    cin>>numCuenta;

    int posicion=calcularPosicion(numCuenta);
    archivo.seekg(posicion);
    CuentaBancaria c;
    archivo.read((char*)&c, sizeof(CuentaBancaria));

    if(!archivo || c.numeroCuenta != numCuenta){
        cout << "✗ Cuenta no encontrada.\n";
        archivo.close();
        return;
    }

    if (!c.activa){
        cout << "✗ La cuenta esta inactiva. Operacion no permitida.\n";
        archivo.close();
        return;
    }

    int tipo;
    cout << "1. Depositar\n2. Retirar\nOpcion: ";
    cin >> tipo;

    double monto;
    cout << "Monto: $";
    cin >> monto;

    if (monto <= 0) {
        cout << "✗ El monto debe ser positivo.\n";
        archivo.close();
        return;
    }

    if (tipo == 1) {
        c.saldo += monto;
        cout << "✓ Deposito exitoso. Nuevo saldo: $" << c.saldo << "\n";
    } else if (tipo == 2) {
        if (c.saldo - monto < 0) {
            cout << "✗ Saldo insuficiente. Saldo actual: $" << c.saldo << "\n";
            archivo.close();
            return;
        }
        c.saldo -= monto;
        cout << "✓ Retiro exitoso. Nuevo saldo: $" << c.saldo << "\n";
    } else {
        cout << "✗ Opcion invalida.\n";
        archivo.close();
        return;
    }

    // Escribir directo en el archivo
    archivo.seekp(posicion);
    archivo.write((char*)&c, sizeof(CuentaBancaria));

    archivo.close();
}

void desactivarCuenta(){
    fstream archivo("cuentas.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cerr << "Error al abrir el archivo.\n";
        return;
    }

    int numCuenta;
    cout << "Numero de cuenta a desactivar: ";
    cin >> numCuenta;

    long posicion = calcularPosicion(numCuenta);
    archivo.seekg(posicion);
    CuentaBancaria c;
    archivo.read((char*)&c, sizeof(CuentaBancaria));

    if (!archivo || c.numeroCuenta != numCuenta) {
        cout << "✗ Cuenta no encontrada.\n";
        archivo.close();
        return;
    }

    if (!c.activa) {
        cout << "⚠ La cuenta ya estaba inactiva.\n";
        archivo.close();
        return;
    }

    c.activa = false;
    archivo.seekp(posicion);
    archivo.write((char*)&c, sizeof(CuentaBancaria));

    cout << "✓ Cuenta " << numCuenta << " desactivada correctamente.\n";
    archivo.close();
}

void mostrarActivas(){

    ifstream archivo("cuentas.dat", ios::binary);
    if (!archivo) { 
        cerr << "Error al abrir el archivo."<<endl;
        return;
    }

    CuentaBancaria c;
    int count = 0;
    cout << "\n========== CUENTAS ACTIVAS ==========\n";

    while (archivo.read((char*)&c, sizeof(CuentaBancaria))) {
        if (c.activa && c.numeroCuenta != 0) { // ignorar posiciones vacías
            cout << "N°: "      << c.numeroCuenta << " | "
                 << "Titular: " << c.titular      << " | "
                 << "Saldo: $"  << c.saldo        << "\n";
            count++;
        }
    }

    if (count == 0) cout << "No hay cuentas activas.\n";
    cout << "=====================================\n";

    archivo.close();
}

int main (){

    int opcion;
    do {
        cout << "\n====== BANCO ======\n";
        cout << "1. Crear cuentas\n";
        cout << "2. Buscar cuenta\n";
        cout << "3. Depositar/Retirar\n";
        cout << "4. Desactivar cuenta\n";
        cout << "5. Ver cuentas activas\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int n;
                cout << "¿Cuantas cuentas? ";
                cin >> n;
                crearArchivo(n);
                break;
            }
            case 2: buscarCuenta();     break;
            case 3: operacion();        break;
            case 4: desactivarCuenta(); break;
            case 5: mostrarActivas();   break;
            case 0: cout << "Hasta luego.\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);


    return 0;
}