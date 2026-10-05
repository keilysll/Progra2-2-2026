#include "Vehiculo.h"

Vehiculo::Vehiculo(string placa, int km)
{
	this->placa = placa;
	this->km = km;
}

Vehiculo::~Vehiculo()
{
}

string Vehiculo::getPlaca()
{
	return placa;
}

int Vehiculo::getKm()
{
	return km;
}

string Vehiculo::toJson()
{
	stringstream ss;
	ss << "{\"placa\":\""<<placa<<"\",\"modelo\":"<<km<<"}";
	return ss.str();
}
