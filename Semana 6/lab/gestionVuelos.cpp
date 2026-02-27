#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Pasajero {
    int dni;
    char nombre[50];
};

struct Asiento {
    int numero;
    bool reservado;
    Pasajero* pasajero;
};

struct NodoReserva {
    Pasajero pasajero;
    int numeroAsiento;
    NodoReserva* siguiente;
};

struct Vuelo {
    char codigo[10];
    char destino[50];
    int capacidad;
    Asiento* asientos;
    NodoReserva* listaReservas;
};

bool verificarVuelo(bool vueloCreado);
int  contarReservas(const Vuelo& v);

void crearVuelo(Vuelo& v);
void mostrarMapa(const Vuelo& v);
void reservarAsiento(Vuelo& v);
void cancelarReserva(Vuelo& v);
void mostrarPasajeros(const Vuelo& v);
void mostrarEstadisticas(const Vuelo& v);
void liberarMemoria(Vuelo& v);
void guardarTexto(const Vuelo& v);
void guardarBinario(const Vuelo& v);
void cargarBinario(Vuelo& v);
bool pasajeroEnLista(const Vuelo& v, int dni);
void insertarNodo(Vuelo& v, const Pasajero& p, int numAsiento);
void eliminarNodo(Vuelo& v, int dni);
int  encontrarAsientoPorDni(const Vuelo& v, int dni);

int main()
{
    Vuelo vuelo{};
    bool vueloCreado = false;
    int opcion;

    do
    {
        cout << "\n===== SISTEMA DE VUELOS =====\n";
        cout << "1. Crear vuelo\n";
        cout << "2. Mostrar mapa\n";
        cout << "3. Reservar asiento\n";
        cout << "4. Cancelar reserva\n";
        cout << "5. Mostrar pasajeros\n";
        cout << "6. Estadisticas\n";
        cout << "7. Guardar texto\n";
        cout << "8. Guardar binario\n";
        cout << "9. Cargar binario\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            if (vueloCreado)
                liberarMemoria(vuelo);

            crearVuelo(vuelo);
            vueloCreado = true;
            break;

        case 2:
            if (verificarVuelo(vueloCreado))
                mostrarMapa(vuelo);
            break;

        case 3:
            if (verificarVuelo(vueloCreado))
                reservarAsiento(vuelo);
            break;

        case 4:
            if (verificarVuelo(vueloCreado))
                cancelarReserva(vuelo);
            break;

        case 5:
            if (verificarVuelo(vueloCreado))
                mostrarPasajeros(vuelo);
            break;

        case 6:
            if (verificarVuelo(vueloCreado))
                mostrarEstadisticas(vuelo);
            break;

        case 7:
            if (verificarVuelo(vueloCreado))
                guardarTexto(vuelo);
            break;

        case 8:
            if (verificarVuelo(vueloCreado))
                guardarBinario(vuelo);
            break;

        case 9:
            if (vueloCreado)
                liberarMemoria(vuelo);

            cargarBinario(vuelo);
            vueloCreado = true;
            break;

        case 0:
            liberarMemoria(vuelo);
            break;
        }

    } while (opcion != 0);

    return 0;
}

bool verificarVuelo(bool vueloCreado)
{
    if (!vueloCreado)
    {
        cout << "Primero cree un vuelo\n";
        return false;
    }
    return true;
}

int contarReservas(const Vuelo& v)
{
    int count = 0;
    NodoReserva* actual = v.listaReservas;

    while (actual)
    {
        count++;
        actual = actual->siguiente;
    }
    return count;
}


void crearVuelo(Vuelo& v)
{
    cout << "Codigo: ";
    cin >> v.codigo;

    cout << "Destino: ";
    cin.ignore();
    cin.getline(v.destino, 50);

    cout << "Capacidad: ";
    cin >> v.capacidad;

    v.asientos = new Asiento[v.capacidad];

    for (int i = 0; i < v.capacidad; i++)
    {
        Asiento& a = v.asientos[i];

        a.numero = i + 1;
        a.reservado = false;
        a.pasajero = nullptr;
    }

    v.listaReservas = nullptr;
}

void mostrarMapa(const Vuelo& v)
{
    for (int i = 0; i < v.capacidad; i++)
    {
        const Asiento& a = v.asientos[i];

        cout << a.numero
             << (a.reservado ? " [X]" : " [ ]")
             << "\n";
    }
}

void reservarAsiento(Vuelo& v)
{
    Pasajero p;

    cout << "DNI: ";
    cin >> p.dni;

    if (pasajeroEnLista(v, p.dni))
    {
        cout << "Ya tiene reserva\n";
        return;
    }

    cout << "Nombre: ";
    cin.ignore();
    cin.getline(p.nombre, 50);

    int num;
    cout << "Asiento: ";
    cin >> num;

    if (num < 1 || num > v.capacidad)
        return;

    Asiento& a = v.asientos[num - 1];

    if (a.reservado)
        return;

    a.pasajero = new Pasajero(p);
    a.reservado = true;

    insertarNodo(v, p, num);
}

void cancelarReserva(Vuelo& v)
{
    int dni;
    cin >> dni;

    int idx = encontrarAsientoPorDni(v, dni);

    if (idx == -1)
        return;

    Asiento& a = v.asientos[idx];

    delete a.pasajero;
    a.pasajero = nullptr;
    a.reservado = false;

    eliminarNodo(v, dni);
}

void mostrarPasajeros(const Vuelo& v)
{
    NodoReserva* actual = v.listaReservas;

    while (actual)
    {
        cout << actual->pasajero.dni << " "
             << actual->pasajero.nombre << " "
             << actual->numeroAsiento << "\n";

        actual = actual->siguiente;
    }
}

void mostrarEstadisticas(const Vuelo& v)
{
    int ocupados = contarReservas(v);

    cout << "Total: " << v.capacidad << "\n";
    cout << "Ocupados: " << ocupados << "\n";
    cout << "Libres: " << v.capacidad - ocupados << "\n";
}

void insertarNodo(Vuelo& v, const Pasajero& p, int numAsiento)
{
    NodoReserva* nuevo = new NodoReserva{p, numAsiento, nullptr};

    NodoReserva** actual = &v.listaReservas;

    while (*actual)
        actual = &((*actual)->siguiente);

    *actual = nuevo;
}

void eliminarNodo(Vuelo& v, int dni)
{
    NodoReserva** actual = &v.listaReservas;

    while (*actual && (*actual)->pasajero.dni != dni)
        actual = &((*actual)->siguiente);

    if (*actual)
    {
        NodoReserva* temp = *actual;
        *actual = temp->siguiente;
        delete temp;
    }
}

int encontrarAsientoPorDni(const Vuelo& v, int dni)
{
    for (int i = 0; i < v.capacidad; i++)
    {
        const Asiento& a = v.asientos[i];

        if (a.reservado && a.pasajero && a.pasajero->dni == dni)
            return i;
    }
    return -1;
}

void liberarMemoria(Vuelo& v)
{
    if (v.asientos)
    {
        for (int i = 0; i < v.capacidad; i++)
            delete v.asientos[i].pasajero;

        delete[] v.asientos;
    }

    while (v.listaReservas)
    {
        NodoReserva* temp = v.listaReservas;
        v.listaReservas = temp->siguiente;
        delete temp;
    }

    v.asientos = nullptr;
    v.capacidad = 0;
}