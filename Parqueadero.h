#ifndef PARQUEADERO_H
#define PARQUEADERO_H

#include "Vehiculo.h"
#include <vector>

class Parqueadero
{
    private:
        vector <Vehiculo> vehiculos;
        double totalCarros;
        double totalMotos;
        double totalCamiones;


    public:

        Parqueadero();
        virtual ~Parqueadero();

        void addVehiculo(const string& tipo, const string& placa, const string& marca, const string& color, int horaEntrada);
        void buscarVehiculo(const string& placa) const;
        void retirarVehiculo(const string& placa, int horaSalida);
        void mostrarFacturacion() const;
        void mostrarInforme() const;
};

#endif // PARQUEADERO_H
