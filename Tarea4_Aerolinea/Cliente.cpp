#include "Cliente.h"

Cliente::Cliente(string nombre, int ci, int fono)
{
	this->nombre = nombre;
	this->ci = ci;
	this ->fono = fono;
}

Cliente::~Cliente()
{
}

string Cliente::getNombre()
{
	return nombre;
}

int Cliente::getCi()
{
	return ci;
}

int Cliente::getFono()
{
	return fono;
}

void Cliente::setNombre(string nombre)
{
	this->nombre = nombre;
	
}

void Cliente::setCi(int ci)
{
	this->ci = ci;
	
}

void Cliente::setFono(int fono)
{
	this->fono = fono;
}

string Cliente::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Nombre\":\"" << nombre << "\",";
	ss << "\"Ci\":" << ci << ",";
	ss << "\"Telefono\":" << fono;
	ss << "}";
	
	return ss.str();
}
