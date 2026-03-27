#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Figura {
private:
    string nombre;
    double* colorRGB;

public:

    // constructor de parametros
    Figura(string nom, double r, double g, double b): nombre(nom) {
        colorRGB = new double[3];
        colorRGB[0] = r;
        colorRGB[1] = g;
        colorRGB[2] = b;
    }

    // constructor de copia profunda
    Figura(Figura & otro): nombre(otro.nombre){
        colorRGB = new double[3];

        for(int i = 0; i <3 ; ++i) {
            colorRGB[i] = otro.colorRGB[i];
        }
    }

    // operador asignacion
    Figura& operator=(Figura& otro) {

        if (this !=  &otro) {

            nombre = otro.nombre;

            delete [] colorRGB;

            colorRGB = new double[3];

            for (int i = 0; i < 3 ; i++) {
                colorRGB[i] = otro.colorRGB[i];
            }
        }

        return *this;
    }

    virtual ~Figura() {
        delete [] colorRGB;
    }

    // getters
    string getNombre() const { return nombre; }
    double getR() const { return colorRGB[0]; }
    double getG() const { return colorRGB[1]; }
    double getB() const { return colorRGB[2]; }

    //Metodos virtuales puros
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual void imprimir() const = 0;
};

//////////////////////////////////////////////////////

class Circulo : public Figura {

private:
    double radio;

public:

    Circulo(double r, string n, double R,double G,double B)
        : Figura(n,R,G,B)
    {
        radio = r;
    }

    double area() const{
        return M_PI * radio * radio;
    }

    double perimetro() const{
        return 2 * M_PI * radio;
    }

    void imprimir() const{

        cout<<"Circulo"<<endl;
        cout<<"Nombre: "<<getNombre()<<endl;
        cout<<"Radio: "<<radio<<endl;

        cout<<"Color RGB: "
            <<getR()<<" "
            <<getG()<<" "
            <<getB()<<endl;

        cout<<"Area: "<<area()<<endl;
        cout<<"Perimetro: "<<perimetro()<<endl;
    }
};

//////////////////////////////////////////////////////

class Rectangulo : public Figura {

private:
    double base;
    double altura;

public:

    Rectangulo(double b,double h,string n,double R,double G,double B)
        : Figura(n,R,G,B)
    {
        base = b;
        altura = h;
    }

    double area() const{
        return base * altura;
    }

    double perimetro() const{
        return 2*(base + altura);
    }

    void imprimir() const{

        cout<<"Rectangulo"<<endl;
        cout<<"Nombre: "<<getNombre()<<endl;

        cout<<"Base: "<<base<<endl;
        cout<<"Altura: "<<altura<<endl;

        cout<<"Color RGB: "
            <<getR()<<" "
            <<getG()<<" "
            <<getB()<<endl;

        cout<<"Area: "<<area()<<endl;
        cout<<"Perimetro: "<<perimetro()<<endl;
    }
};

//////////////////////////////////////////////////////

class GestorFiguras {

private:

    Figura** figuras;
    int cantidad;
    int capacidad;

public:

    GestorFiguras(int cap = 5){

        capacidad = cap;
        cantidad = 0;

        figuras = new Figura*[capacidad];
    }

    ~GestorFiguras(){

        for(int i=0;i<cantidad;i++){
            delete figuras[i];
        }

        delete[] figuras;
    }

    void agregarFigura(Figura* f){

        if(cantidad == capacidad){

            capacidad *= 2;

            Figura** nuevo = new Figura*[capacidad];

            for(int i=0;i<cantidad;i++){
                nuevo[i] = figuras[i];
            }

            delete[] figuras;

            figuras = nuevo;
        }

        figuras[cantidad] = f;
        cantidad++;
    }

    void mostrarFiguras() const{

        for(int i=0;i<cantidad;i++){

            figuras[i]->imprimir();
            cout<<"------------------"<<endl;
        }
    }

    double areaTotal() const{

        double suma = 0;

        for(int i=0;i<cantidad;i++){
            suma += figuras[i]->area();
        }

        return suma;
    }
};

//////////////////////////////////////////////////////

int main(){

    GestorFiguras gestor;

    gestor.agregarFigura(new Circulo(5,"circulo1",255,0,0));
    gestor.agregarFigura(new Rectangulo(4,6,"rect1",0,255,0));
    gestor.agregarFigura(new Circulo(3,"circulo2",0,0,255));

    gestor.mostrarFiguras();

    cout<<"Area total: "<<gestor.areaTotal()<<endl;

    return 0;
}