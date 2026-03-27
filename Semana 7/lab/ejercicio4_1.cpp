#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Cuenta {
    int numero;
    char titular[50];
    double saldo;
};

const char* archivo = "output/cuentas.dat";

void crearCuenta(int numero, const char* nombre, double saldoInicial)
{
    if (saldoInicial < 0)
    {
        cout << "Error: saldo inicial invalido\n";
        return;
    }

    Cuenta c;
    c.numero = numero;
    strcpy(c.titular, nombre);
    c.saldo = saldoInicial;

    ofstream out(archivo, ios::binary | ios::app);
    out.write((char*)&c, sizeof(Cuenta));

    cout << "Cuenta creada correctamente\n";
}

int buscarCuenta(int numero)
{
    ifstream in(archivo, ios::binary);

    Cuenta c;
    int posicion = 0;

    while (in.read((char*)&c, sizeof(Cuenta)))
    {
        if (c.numero == numero)
            return posicion;

        posicion++;
    }

    return -1;
}

void depositar(int numero, double monto)
{
    if (monto <= 0)
    {
        cout << "Monto invalido\n";
        return;
    }

    fstream file(archivo, ios::binary | ios::in | ios::out);

    Cuenta c;

    while (file.read((char*)&c, sizeof(Cuenta)))
    {
        if (c.numero == numero)
        {
            c.saldo += monto;

            file.seekp(-sizeof(Cuenta), ios::cur);
            file.write((char*)&c, sizeof(Cuenta));

            cout << "Deposito exitoso\n";
            return;
        }
    }

    cout << "Cuenta no encontrada\n";
}

void retirar(int numero, double monto)
{
    if (monto <= 0)
    {
        cout << "Monto invalido\n";
        return;
    }

    fstream file(archivo, ios::binary | ios::in | ios::out);

    Cuenta c;

    while (file.read((char*)&c, sizeof(Cuenta)))
    {
        if (c.numero == numero)
        {
            if (monto > c.saldo)
            {
                cout << "Fondos insuficientes\n";
                return;
            }

            c.saldo -= monto;

            file.seekp(-sizeof(Cuenta), ios::cur);
            file.write((char*)&c, sizeof(Cuenta));

            cout << "Retiro exitoso\n";
            return;
        }
    }

    cout << "Cuenta no encontrada\n";
}

void mostrarCuenta(int numero)
{
    ifstream in(archivo, ios::binary);

    Cuenta c;

    while (in.read((char*)&c, sizeof(Cuenta)))
    {
        if (c.numero == numero)
        {
            cout << "Numero: " << c.numero << endl;
            cout << "Titular: " << c.titular << endl;
            cout << "Saldo: " << c.saldo << endl;
            return;
        }
    }

    cout << "Cuenta no encontrada\n";
}

int main()
{
    crearCuenta(1, "Carlos", 1000);

    depositar(1, 500);

    retirar(1, 200);

    mostrarCuenta(1);

    return 0;
}

/*
Analice cuidadosamente el código y responda a las siguientes preguntas

¿Dónde puede romperse el programa? Analice, el orden de ejecución, posibles errores lógicos, usos indebidos
Tiene un error lógico al retirar dinero de la cuenta bancaria ya que no se valida el saldo.

¿Quién garantiza que el saldo no sea negativo? ¿Existe alguna validación?
No existe ninguna validación. 

¿Qué pasa si olvidamos llamar a crearCuenta() antes de usar depositar()?
La variable global cuentaGlobal se inicializa con valores basura (o ceros según el compilador). 
Podrías estar depositando o retirando sobre una cuenta con numero = 0, titular = "" y saldo = 0.0. 
El programa no avisará nada, simplemente operará sobre datos inválidos silenciosamente.

¿Puede cualquier parte del programa modificar el saldo directamente? Por ejemplo: cuentaGlobal.saldo = -999999;
Al ser una variable global con todos sus campos públicos, no hay ninguna protección. 
Esto es exactamente el problema que la encapsulación en POO resuelve.

¿Qué sucede si tuviéramos 100 cuentas?
Este diseño colapsa porque solo existe cuentaGlobal, una única variable. 

Implemente una versión mejorada agregando

Validación de saldo negativo
Validación de monto > 0
Manejo de múltiples cuentas
Archivo binario
Acceso aleatorio por número de cuenta

*/
