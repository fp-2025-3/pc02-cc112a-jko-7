#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// ============================================================
//  CLASE CuentaBancaria
// ============================================================
class CuentaBancaria {
private:
    int    numeroCuenta;
    char   titular[50];
    double saldo;

    // Validacion centralizada y PRIVADA
    bool validarMonto(double monto) const {
        if (monto <= 0) {
            cout << "  [Error] El monto debe ser mayor a cero.\n";
            return false;
        }
        return true;
    }

public:
    // Constructor por defecto (necesario para leer del archivo)
    CuentaBancaria() : numeroCuenta(0), saldo(0.0) {
        memset(titular, 0, sizeof(titular));
    }

    // Constructor principal — garantiza estado valido desde el inicio
    CuentaBancaria(int numero, const string& nombre, double saldoInicial) {
        numeroCuenta = numero;
        memset(titular, 0, sizeof(titular));
        strncpy(titular, nombre.c_str(), sizeof(titular) - 1);
        saldo = saldoInicial;
    }

    // Getters
    int    getNumeroCuenta() const { return numeroCuenta; }
    string getTitular()      const { return string(titular); }
    double getSaldo()        const { return saldo; }

    // Depositar
    bool depositar(double monto) {
        if (!validarMonto(monto)) return false;
        saldo += monto;
        return true;
    }

    // Retirar
    bool retirar(double monto) {
        if (!validarMonto(monto)) return false;
        if (monto > saldo) {
            cout << "  [Error] Fondos insuficientes.\n";
            return false;
        }
        saldo -= monto;
        return true;
    }

    void mostrar() const {
        cout << "\n========================================\n";
        cout << "  Numero de cuenta : " << numeroCuenta << "\n";
        cout << "  Titular          : " << titular      << "\n";
        cout << "  Saldo            : $" << fixed << saldo << "\n";
        cout << "========================================\n";
    }
};

// ============================================================
//  CLASE GestorArchivo — persistencia + acceso aleatorio
// ============================================================
class GestorArchivo {
private:
    string nombreArchivo;

    streampos posicion(int indice) const {
        return static_cast<streampos>(indice * sizeof(CuentaBancaria));
    }

public:
    explicit GestorArchivo(const string& archivo) : nombreArchivo(archivo) {}

    void guardar(const CuentaBancaria& cuenta) {
        fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);
        if (!archivo.is_open())
            archivo.open(nombreArchivo, ios::binary | ios::out);
        archivo.seekp(0, ios::end);
        archivo.write(reinterpret_cast<const char*>(&cuenta),
                      sizeof(CuentaBancaria));
        archivo.close();
    }

    int totalRegistros() const {
        ifstream archivo(nombreArchivo, ios::binary | ios::ate);
        if (!archivo.is_open()) return 0;
        return static_cast<int>(archivo.tellg() / sizeof(CuentaBancaria));
    }

    void listarTodos() const {
        int total = totalRegistros();
        if (total == 0) { cout << "\nNo hay cuentas registradas.\n"; return; }
        ifstream archivo(nombreArchivo, ios::binary);
        CuentaBancaria tmp;
        for (int i = 0; i < total; i++) {
            archivo.read(reinterpret_cast<char*>(&tmp), sizeof(CuentaBancaria));
            tmp.mostrar();
        }
    }

    int buscarIndice(int numeroCuenta) const {
        int total = totalRegistros();
        ifstream archivo(nombreArchivo, ios::binary);
        CuentaBancaria tmp;
        for (int i = 0; i < total; i++) {
            archivo.read(reinterpret_cast<char*>(&tmp), sizeof(CuentaBancaria));
            if (tmp.getNumeroCuenta() == numeroCuenta) return i;
        }
        return -1;
    }

    // Acceso aleatorio con seekg
    bool leer(int indice, CuentaBancaria& cuenta) const {
        ifstream archivo(nombreArchivo, ios::binary);
        if (!archivo.is_open()) return false;
        archivo.seekg(posicion(indice));
        archivo.read(reinterpret_cast<char*>(&cuenta), sizeof(CuentaBancaria));
        return archivo.good();
    }

    // Acceso aleatorio con seekp
    bool actualizar(int indice, const CuentaBancaria& cuenta) {
        fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);
        if (!archivo.is_open()) return false;
        archivo.seekp(posicion(indice));
        archivo.write(reinterpret_cast<const char*>(&cuenta),
                      sizeof(CuentaBancaria));
        return archivo.good();
    }
};

// ============================================================
//  CLASE SistemaBancario — menu interactivo
// ============================================================
class SistemaBancario {
private:
    GestorArchivo gestor;

    int leerEntero(const string& msg) const {
        int val;
        cout << msg;
        while (!(cin >> val)) {
            cin.clear();
            cin.sync();
            cout << "  [!] Ingrese un entero valido: ";
        }
        cin.sync();
        return val;
    }

    double leerDouble(const string& msg) const {
        double val;
        cout << msg;
        while (!(cin >> val)) {
            cin.clear();
            cin.sync();
            cout << "  [!] Ingrese un valor numerico valido: ";
        }
        cin.sync();
        return val;
    }

    void crearCuenta() {
        cout << "\n--- CREAR CUENTA ---\n";
        int numero = leerEntero("  Numero de cuenta  : ");

        if (numero <= 0) {
            cout << "  [Error] Numero de cuenta invalido.\n"; return;
        }
        if (gestor.buscarIndice(numero) != -1) {
            cout << "  [!] Ya existe una cuenta con ese numero.\n"; return;
        }

        cout << "  Nombre del titular: ";
        string nombre;
        getline(cin, nombre);

        if (nombre.empty()) {
            cout << "  [Error] El nombre no puede estar vacio.\n"; return;
        }

        double saldoInicial = leerDouble("  Saldo inicial     : $");
        if (saldoInicial < 0) {
            cout << "  [Error] El saldo inicial no puede ser negativo.\n"; return;
        }

        CuentaBancaria nueva(numero, nombre, saldoInicial);
        gestor.guardar(nueva);
        cout << "  [OK] Cuenta creada exitosamente.\n";
    }

    void depositar() {
        cout << "\n--- DEPOSITAR ---\n";
        int numero = leerEntero("  Numero de cuenta: ");
        int idx = gestor.buscarIndice(numero);
        if (idx == -1) { cout << "  [!] Cuenta no encontrada.\n"; return; }

        double monto = leerDouble("  Monto a depositar: $");
        CuentaBancaria cuenta;
        gestor.leer(idx, cuenta);           // seekg — acceso aleatorio
        if (cuenta.depositar(monto)) {
            gestor.actualizar(idx, cuenta); // seekp — acceso aleatorio
            cout << "  [OK] Nuevo saldo: $" << cuenta.getSaldo() << "\n";
        }
    }

    void retirar() {
        cout << "\n--- RETIRAR ---\n";
        int numero = leerEntero("  Numero de cuenta: ");
        int idx = gestor.buscarIndice(numero);
        if (idx == -1) { cout << "  [!] Cuenta no encontrada.\n"; return; }

        double monto = leerDouble("  Monto a retirar: $");
        CuentaBancaria cuenta;
        gestor.leer(idx, cuenta);
        if (cuenta.retirar(monto)) {
            gestor.actualizar(idx, cuenta);
            cout << "  [OK] Nuevo saldo: $" << cuenta.getSaldo() << "\n";
        }
    }

    void mostrarCuenta() {
        cout << "\n--- CONSULTAR CUENTA ---\n";
        int numero = leerEntero("  Numero de cuenta: ");
        int idx = gestor.buscarIndice(numero);
        if (idx == -1) { cout << "  [!] Cuenta no encontrada.\n"; return; }
        CuentaBancaria cuenta;
        gestor.leer(idx, cuenta);
        cuenta.mostrar();
    }

    void mostrarTodas() {
        cout << "\n--- TODAS LAS CUENTAS ---\n";
        gestor.listarTodos();
    }

public:
    explicit SistemaBancario(const string& archivo) : gestor(archivo) {}

    void ejecutar() {
        int opcion = 0;
        do {
            cout << "\n============= BANCO POO =============\n";
            cout << "  1. Crear cuenta\n";
            cout << "  2. Depositar\n";
            cout << "  3. Retirar\n";
            cout << "  4. Consultar cuenta\n";
            cout << "  5. Listar todas las cuentas\n";
            cout << "  0. Salir\n";
            cout << "=====================================\n";
            opcion = leerEntero("  Opcion: ");
            switch (opcion) {
                case 1: crearCuenta();   break;
                case 2: depositar();     break;
                case 3: retirar();       break;
                case 4: mostrarCuenta(); break;
                case 5: mostrarTodas();  break;
                case 0: cout << "  Hasta luego.\n"; break;
                default: cout << "  [!] Opcion invalida.\n";
            }
        } while (opcion != 0);
    }
};

// ============================================================
//  MAIN — sin variables globales
// ============================================================
int main() {
    SistemaBancario sistema("cuentas.dat");
    sistema.ejecutar();
    return 0;
}