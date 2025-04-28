#include "Parqueadero.h"
#include <iostream>
using namespace std;

Parqueadero::Parqueadero() : totalCarros(0), totalMotos(0), totalCamiones(0)
{
    //ctor
}
Parqueadero::~Parqueadero()
{
    //dctor
}

void Parqueadero::addVehiculo(const string& tipo, const string& placa, const string& marca, const string& color, int horaEntrada)
{
    vehiculos.push_back(Vehiculo(tipo, placa, marca, color, horaEntrada));
}

void Parqueadero::buscarVehiculo(const string& placa) const
{
    bool encontrado = false;

    for (const Vehiculo& vehiculo : vehiculos)
    {
        if (vehiculo.getPlaca() == placa)
        {
            cout << "\n--- Vehiculo Encontrado ---\n";
            cout << "\nTipo: "    << vehiculo.getTipo()
                 << " - Marca: " << vehiculo.getMarca()
                 << " - Placa: " << vehiculo.getPlaca()
                 << " - Color: " << vehiculo.getColor()
                 << " - Hora de Entrada: " << vehiculo.getHoraEntrada()
                 << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        cout << "\nVehiculo no encontrado\n";
    }
}

void Parqueadero::retirarVehiculo(const string& placa, int horaSalida)
{
    for (auto it = vehiculos.begin(); it != vehiculos.end(); ++it)
    {
        if (it -> getPlaca() == placa)
        {
            int horas = horaSalida - it -> getHoraEntrada();
            if (horas <= 0) horas = 1; // Siempre al menos 1 hora

            double valor = 0;
            string tipo = it->getTipo();

            if (tipo == "Carro")
            {
                if (horas == 1)
                    valor = 3000;
                else if (horas <= 12)
                    valor = 3000 + (horas - 1) * 2000;
                else
                    valor = 3000 + (11 * 2000) + (horas - 12) * 1000;

                totalCarros += valor;
            }
            else if (tipo == "Camion")
            {
                if (horas == 1)
                    valor = 4000;
                else if (horas <= 12)
                    valor = 4000 + (horas - 1) * 2500;
                else
                    valor = 4000 + (11 * 2500) + (horas - 12) * 1500;

                totalCamiones += valor;
            }
            else if (tipo == "Moto")
            {
                if (horas == 1)
                    valor = 2000;
                else if (horas <= 12)
                    valor = 2000 + (horas - 1) * 1000;
                else
                    valor = 2000 + (11 * 1000) + (horas - 12) * 500;

                totalMotos += valor;
            }
            else
            {
                cout << "Tipo de vehiculo no reconocido para facturar.\n";
            }

            cout << "\nEl valor a pagar por el vehiculo con placa - " << it->getPlaca()
                 << " - es de $" << valor << endl;

            vehiculos.erase(it); // eliminar el vehículo del vector
            return;
        }
    }
    cout << "\nVehiculo no encontrado.\n";
}

void Parqueadero::mostrarFacturacion() const
{
    cout << "\n--- Facturacion del dia ---\n";
    cout << "Total facturado Carros: $" << totalCarros << endl;
    cout << "Total facturado Motos: $" << totalMotos << endl;
    cout << "Total facturado Camiones: $" << totalCamiones << endl;
}

void Parqueadero::mostrarInforme() const
{
    cout << "\n--- Informe de Vehiculos en Parqueadero ---\n";
    for (const Vehiculo& vehiculo : vehiculos)
    {
        cout << "\nTipo: " << vehiculo.getTipo()
             << " - Marca: " << vehiculo.getMarca()
             << " - Placa: " << vehiculo.getPlaca()
             << " - Color: " << vehiculo.getColor()
             << " - Hora Entrada: " << vehiculo.getHoraEntrada() << "hrs"
             << endl;
    }
    if (vehiculos.empty())
    {
        cout << "No hay vehiculos registrados\n";
    }
}
