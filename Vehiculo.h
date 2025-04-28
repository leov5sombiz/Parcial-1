#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
using namespace std;

class Vehiculo
{
    private:
        //Atributos
        string tipo;
        string placa;
        string marca;
        string color;
        int horaEntrada;

    public:
        //ctor y dctor
        Vehiculo();
        Vehiculo(const string& tipo,
                 const string& placa,
                 const string& marca,
                 const string& color,
                 int horaEntrada);
        virtual ~Vehiculo();

        //setters
        void setTipo(const string& name);
        void setPlaca(const string& placa);
        void setMarca(const string& marca);
        void setColor(const string& color);
        void setHoraEntrada(int horaEntrada);

        //getters
        string getTipo()const;
        string getPlaca()const;
        string getMarca()const;
        string getColor()const;
        int getHoraEntrada() const;
};

#endif // VEHICULO_H
