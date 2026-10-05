#include "Cliente.h"

Cliente::Cliente(int ci, string nombre, int fono):vehiculos(10)
{
	this->ci = ci;
	this->nombre = nombre;
	this->fono = fono;
}

Cliente::~Cliente()
{
}

int Cliente::getCi()
{
	return ci;
}

string Cliente::getNombre()
{
	return nombre;
}

int Cliente::getFono()
{
	return fono;
}

void Cliente::registrar(Vehiculo* v)
{
	vehiculos.registrar(v);
}

Vehiculo* Cliente::buscar(string placa)
{
	return vehiculos.buscar(placa);
}

string Cliente::toJson()
{
	stringstream ss;
	ss << "{\"ci\":"<<ci<<",\"nombre\":\""<<nombre<<"\",\"fono\":"<<fono<<",\"vehiculos\":"<<vehiculos.toJson()<<"}";
	return ss.str();
}
