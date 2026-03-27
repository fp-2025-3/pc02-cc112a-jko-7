#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// ============================================================
// Clase abstracta Sensor
// ============================================================
class Sensor
{
private:
    string id;
    double* posicion;
public:
    // constructor
    Sensor(const string&id, double x, double y) : id(id){
        posicion=new double[2];
        posicion[0]=x;
        posicion[1]=y;
    }

    // constructor de copia
    Sensor(const Sensor& otro) : id(otro.id){
        posicion=new double[2];
        posicion[0]=otro.posicion[0];
        posicion[1]=otro.posicion[1];
    }

    // Operador de asignación
    Sensor& operator=(const Sensor& otro){
        if (this != &otro){
            id = otro.id;
            posicion[0] = otro.posicion[0];
            posicion[1] = otro.posicion[1];
        }
        return *this;
    }

    // Destructor virtual
    virtual ~Sensor(){
        delete[] posicion;
    }

    // Getters
    string getId() const { return id; }
    double getX() const { return posicion[0]; }
    double getY() const { return posicion[1]; }

    // Métodos virtuales puros
    virtual double areaCobertura() const = 0;
    virtual bool detecta(double x, double y) const = 0;
    virtual void imprimir () const = 0;
};

// ============================================================
// Clase SensorCircular
// ============================================================
class SensorCircular:public Sensor
{
private:
    double radio;
public:
    SensorCircular(const string& id, double x, double y, double radio)
        : Sensor(id,x,y), radio(radio) {}

    // Constructor copia
    SensorCircular(const SensorCircular& otro)
        : Sensor(otro), radio(otro.radio) {}

    // Destructor
    ~SensorCircular() {}

    double areaCobertura() const override{
        return M_PI*radio*radio;
    }

    // Detecta si el punto (x,y) esta dentro del circulo
    bool detecta(double x, double y) const override{
        double dx = x-getX();
        double dy = y-getY();
        return (dx*dx+dy*dy)<=(radio*radio);
    }

    void imprimir() const override{
        cout << "+---------------------------------+" << endl;
        cout << "| Sensor Circular                 |" << endl;
        cout << "+---------------------------------+" << endl;
        cout << "  ID       : " << getId() << endl;
        cout << "  Posicion : (" << getX() << ", " << getY() << ")" << endl;
        cout << "  Radio    : " << radio << endl;
        cout << "  Area     : " << areaCobertura() << endl;
    }
};

// ============================================================
// Clase SensorRectangular
// ============================================================
class SensorRectangular:public Sensor
{
private:
    double ancho;
    double alto;    

public:
    SensorRectangular(const string& id, double x, double y, double ancho, double alto)
        : Sensor(id, x, y), ancho(ancho), alto(alto) {}

    // Constructor de copia
    SensorRectangular(const SensorRectangular& otro)
        : Sensor(otro), ancho(otro.ancho), alto(otro.alto) {}

    // Destructor
    ~SensorRectangular() {}

    double areaCobertura() const override {
        return ancho * alto;
    }

    // Detecta si el punto (x,y) está dentro del rectángulo centrado en posición
    bool detecta(double x, double y) const override {
        double mitadAncho = ancho / 2.0;
        double mitadAlto  = alto  / 2.0;
        return (x >= getX() - mitadAncho && x <= getX() + mitadAncho &&
                y >= getY() - mitadAlto  && y <= getY() + mitadAlto);
    }

    void imprimir() const override {
        cout << "+---------------------------------+" << endl;
        cout << "| Sensor Rectangular              |" << endl;
        cout << "+---------------------------------+" << endl;
        cout << "  ID       : " << getId() << endl;
        cout << "  Posicion : (" << getX() << ", " << getY() << ")" << endl;
        cout << "  Ancho    : " << ancho << endl;
        cout << "  Alto     : " << alto << endl;
        cout << "  Area     : " << areaCobertura() << endl;
    }
};

// ============================================================
// Clase SistemaSensores
// ============================================================
class SistemaSensores {
private:
    Sensor** sensores; // arreglo dinámico de punteros a Sensor
    int cantidad;
    int capacidad;

    // Redimensiona el arreglo al doble de capacidad
    void redimensionar() {
        capacidad *= 2;
        Sensor** nuevo = new Sensor*[capacidad];
        for (int i = 0; i < cantidad; i++) {
            nuevo[i] = sensores[i];
        }
        delete[] sensores;
        sensores = nuevo;
    }

public:
    // Constructor: capacidad inicial = 4
    SistemaSensores() : cantidad(0), capacidad(4) {
        sensores = new Sensor*[capacidad];
    }

    // Destructor: libera cada sensor y luego el arreglo
    ~SistemaSensores() {
        for (int i = 0; i < cantidad; i++) {
            delete sensores[i];
        }
        delete[] sensores;
    }

    // Agrega un sensor; redimensiona si es necesario
    void agregarSensor(Sensor* s) {
        if (cantidad == capacidad) {
            redimensionar();
        }
        sensores[cantidad++] = s;
        cout << "  Sensor '" << s->getId() << "' agregado correctamente." << endl;
    }

    // Muestra todos los sensores
    void mostrarSensores() const {
        if (cantidad == 0) {
            cout << "  No hay sensores registrados." << endl;
            return;
        }
        cout << "\n=== Sensores registrados (" << cantidad << ") ===" << endl;
        for (int i = 0; i < cantidad; i++) {
            sensores[i]->imprimir();
        }
    }

    // Suma del área de cobertura de todos los sensores
    double areaTotalCobertura() const {
        double total = 0.0;
        for (int i = 0; i < cantidad; i++) {
            total += sensores[i]->areaCobertura();
        }
        return total;
    }

    // Cuántos sensores detectan el punto (x, y)
    int sensoresQueDetectan(double x, double y) const {
        int count = 0;
        for (int i = 0; i < cantidad; i++) {
            if (sensores[i]->detecta(x, y)) count++;
        }
        return count;
    }

    // Puntero al sensor con mayor área de cobertura
    Sensor* sensorMayorCobertura() const {
        if (cantidad == 0) return nullptr;
        Sensor* mayor = sensores[0];
        for (int i = 1; i < cantidad; i++) {
            if (sensores[i]->areaCobertura() > mayor->areaCobertura()) {
                mayor = sensores[i];
            }
        }
        return mayor;
    }
};

// ============================================================
// Función main con menú interactivo
// ============================================================
int main() {
    SistemaSensores sistema;
    int opcion;
    int contadorId = 1; // para generar IDs automáticos

    do {
        cout << "\n========================================" << endl;
        cout << "       SISTEMA DE SENSORES ROBOTICA     " << endl;
        cout << "========================================" << endl;
        cout << "  1. Agregar sensor circular" << endl;
        cout << "  2. Agregar sensor rectangular" << endl;
        cout << "  3. Mostrar todos los sensores" << endl;
        cout << "  4. Calcular area total de cobertura" << endl;
        cout << "  5. Consultar sensores que detectan un punto" << endl;
        cout << "  6. Sensor con mayor area de cobertura" << endl;
        cout << "  7. Salir" << endl;
        cout << "----------------------------------------" << endl;
        cout << "  Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string id;
                double x, y, radio;
                cout << "\n-- Agregar Sensor Circular --" << endl;
                cout << "  ID del sensor: ";
                cin >> id;
                cout << "  Posicion X   : ";
                cin >> x;
                cout << "  Posicion Y   : ";
                cin >> y;
                cout << "  Radio        : ";
                cin >> radio;
                sistema.agregarSensor(new SensorCircular(id, x, y, radio));
                break;
            }
            case 2: {
                string id;
                double x, y, ancho, alto;
                cout << "\n-- Agregar Sensor Rectangular --" << endl;
                cout << "  ID del sensor: ";
                cin >> id;
                cout << "  Posicion X   : ";
                cin >> x;
                cout << "  Posicion Y   : ";
                cin >> y;
                cout << "  Ancho        : ";
                cin >> ancho;
                cout << "  Alto         : ";
                cin >> alto;
                sistema.agregarSensor(new SensorRectangular(id, x, y, ancho, alto));
                break;
            }
            case 3: {
                sistema.mostrarSensores();
                break;
            }
            case 4: {
                cout << "\n  Area total de cobertura: "
                     << sistema.areaTotalCobertura() << endl;
                break;
            }
            case 5: {
                double x, y;
                cout << "\n-- Consultar punto --" << endl;
                cout << "  Coordenada X: ";
                cin >> x;
                cout << "  Coordenada Y: ";
                cin >> y;
                int cantidad = sistema.sensoresQueDetectan(x, y);
                cout << "  Sensores que detectan (" << x << ", " << y << "): "
                     << cantidad << endl;
                break;
            }
            case 6: {
                Sensor* mayor = sistema.sensorMayorCobertura();
                if (mayor == nullptr) {
                    cout << "\n  No hay sensores registrados." << endl;
                } else {
                    cout << "\n-- Sensor con mayor cobertura --" << endl;
                    mayor->imprimir();
                }
                break;
            }
            case 7: {
                cout << "\n  Saliendo del sistema. Hasta luego!" << endl;
                break;
            }
            default: {
                cout << "\n  Opcion invalida. Intente nuevamente." << endl;
            }
        }
    } while (opcion != 7);

    return 0;
}