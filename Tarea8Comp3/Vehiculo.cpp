#include "Vehiculo.h"

Vehiculo::Vehiculo(string placa, string propetario, int capBat)
{
	this->placa = placa;
	this->propetario =propetario;
	this->capBat = capBat;
}

Vehiculo::~Vehiculo()
{
}

string Vehiculo::getPlaca()
{
	return placa;
}

string Vehiculo::getPropetario()
{
	return propetario;
}

int Vehiculo::getCapBat()
{
	return capBat;
}

bool Vehiculo::operator==(Vehiculo& v)
{
	return placa == v.placa;
}

bool Vehiculo::operator==(Vehiculo* v)
{
	return placa == v->placa;
}

string Vehiculo::toStringPtr(Vehiculo* v)
{
	return v->toString();
}

bool Vehiculo::CmpAs(Vehiculo* v1, Vehiculo* v2)
{
	return v1->placa > v2->placa;
}
