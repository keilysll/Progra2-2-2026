#include "Empleado.h"

Empleado::Empleado(string nombre, int ci, int fono)
{
	this->nombre = nombre;
	this->ci = ci;
	this-> fono = fono;
}

Empleado::~Empleado()
{
}

string Empleado::getNombre()
{
	return nombre;
}

int Empleado::getCi()
{
	return ci;
}

int Empleado::getFono()
{
	return fono;
}

void Empleado::setNombre(string nombre)
{
	this->nombre = nombre;

}

void Empleado::setCi(int ci)
{
	this->ci = ci;
}

void Empleado::setFono(int fono)
{
	this->fono = fono;
}

string Empleado::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Nombre\":\"" << nombre << "\",";
	ss << "\"Ci\":" << ci << ",";
	ss << "\"Fono\":" << fono;
	ss << "}";
	return ss.str();
}
