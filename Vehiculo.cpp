#include "Vehiculo.h"

Vehiculo::Vehiculo() : tipo(""), placa(""), marca(""), color(""), horaEntrada(0) {}

Vehiculo::Vehiculo(const string& tipo,
                   const string& placa,
                   const string& marca,
                   const string& color,
                   int horaEntrada)
    : tipo(tipo), placa(placa), marca(marca), color(color), horaEntrada(horaEntrada) {}

Vehiculo::~Vehiculo() {}

void Vehiculo::setTipo(const string& tipo)
{
    this->tipo = tipo;
}
void Vehiculo::setPlaca(const string& placa)
{
    this->placa = placa;
}
void Vehiculo::setMarca(const string& marca)
{
    this->marca = marca;
}
void Vehiculo::setColor(const string& color)
{
    this->color = color;
}
void Vehiculo::setHoraEntrada(int horaEntrada)
{
    this->horaEntrada = horaEntrada;
}

string Vehiculo::getTipo()const
{
    return tipo;
}
string Vehiculo::getPlaca()const
{
    return placa;
}
string Vehiculo::getMarca()const
{
    return marca;
}
string Vehiculo::getColor()const
{
    return color;
}
int Vehiculo::getHoraEntrada() const
{
    return horaEntrada;
}
