#include <iostream>
using namespace std;

class Sensor
{
private:
    string id;
    double* posicion;
public:
    Sensor(){};


    virtual double areaCobertura() const = 0; 
    virtual bool detecta(double x, double y) const = 0; 
    virtual void imprimir () const = 0; 

    ~Sensor();
};


class SensorCircular:public Sensor
{
private:
    double radio;
public:
    SensorCircular(/* args */);

    virtual double areaCobertura();
    bool detecta(double x, double y);
    void imprimir ();


    ~SensorCircular();
};

    

class SensorRectangular:public Sensor
{
private:
    double ancho;
    double alto;    

public:
    SensorRectangular(/* args */);

    virtual double areaCobertura();
    bool detecta(double x, double y);
    void imprimir ();

    ~SensorRectangular();
};

class SistemaSensores
{
private:
    Sensor* sensores;
    int cantidad;
    int capacidad;    

public:
    SistemaSensores(/* args */);

    void agregarSensor

    ~SistemaSensores();
};



int main (){






    return 0;
}