#include "Cliente.h"

Cliente::Cliente()
{
}

Cliente::Cliente(int ci, string nombre, int fono)
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

void Cliente::setCi(int ci)
{
	this->ci = ci;
	
}

void Cliente::serNombre(string nombre)
{
	this->nombre = nombre;
}

void Cliente::setFono(int fono)
{
	this->fono = fono;
}

void Cliente::mostrar()
{
	cout << "ci: " << ci << "nombre: " << nombre << "fono: " << fono << endl;
}

