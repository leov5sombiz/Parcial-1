#include "Parqueadero.h"
#include <iostream>
#include <string>
using namespace std;

string almacenarDato(string message)
{
    string dato = "";
    cout << message;
    getline(cin, dato);
    return dato;
}

int main()
{
    Parqueadero parqueadero;

    int opcion;

    do
    {
        cout << "\n--- MENU PARQUEADERO ---\n";
        cout << "1. Ingresar Vehiculo\n";
        cout << "2. Retirar Vehiculo\n";
        cout << "3. Buscar Vehiculo por Placa\n";
        cout << "4. Mostrar Facturacion por Tipo de Vehiculo\n";
        cout << "5. Mostrar Informe de Vehiculos en Parqueadero\n";
        cout << "6. Salir\n";
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Evitar problemas al leer strings después de int

        switch (opcion)
        {
            case 1:
            {
                string tipo = almacenarDato("\nIngrese el tipo de vehiculo [ Carro - Moto - Camion ]: ");
                string placa = almacenarDato("Ingrese la placa del vehiculo: ");
                string marca = almacenarDato("Ingrese la marca del vehiculo: ");
                string color = almacenarDato("Ingrese el color del vehiculo: ");
                int horaEntrada = stoi(almacenarDato("Ingrese la hora de entrada (00hrs - 23hrs): "));
                if (horaEntrada < 0 || horaEntrada > 24)
                {
                    cout << "Hora invalida. No se ingreso el vehiculo.\n";
                }
                else
                {
                    parqueadero.addVehiculo(tipo, placa, marca, color, horaEntrada);
                    cout << "Vehiculo ingresado exitosamente.\n";
                }
                break;
            }

            case 2:
            {
                string placa = almacenarDato("\nIngrese la placa del vehiculo a retirar: ");
                int horaSalida = stoi(almacenarDato("Ingrese la hora de salida (0-24): "));
                if (horaSalida < 0 || horaSalida > 24)
                {
                    cout << "Hora de salida invalida.\n";
                }
                else
                {
                    parqueadero.retirarVehiculo(placa, horaSalida);
                }
                break;
            }

            case 3:
            {
                string placa = almacenarDato("\nIngrese la placa del vehiculo a buscar: ");
                parqueadero.buscarVehiculo(placa);
                break;
            }

            case 4:
            {
                parqueadero.mostrarFacturacion();
                break;
            }

            case 5:
            {
                parqueadero.mostrarInforme();
                break;
            }

            case 6:
            {
                cout << "Saliendo del sistema...\n";
                break;
            }

            default:
            {
                cout << "Opcion invalida. Intente de nuevo.\n";
                break;
            }
        }

    } while (opcion != 6);

    return 0;
}
