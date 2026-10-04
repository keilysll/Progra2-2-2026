#include "Persona.h"

Persona::Persona(int ci, string nombre, string direccion, int fono)
{
	this->ci = ci;
	this->nombre = nombre;
	this->direccion = direccion;
	this->fono = fono;
}

Persona::~Persona()
{
}

int Persona::getCi()
{
	return ci;
}

string Persona::getNombre()
{
	return nombre;
}

string Persona::getDireccion()
{
	return direccion;
}

int Persona::getFono()
{
	return fono;
}

void Persona::setCi(int ci)
{
	this->ci = ci;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Persona::setDireccion(string direccion)
{
	this->direccion = direccion;
}

void Persona::setFono(int fono)
{
	this->fono = fono;
}

string Persona::toJson()
{
	stringstream ss;
	ss << "{\"ci\":" << ci << ",\"nombre\":\"" << nombre << "\",\"direccion\":\"" << direccion << "\",\"fono\":" << fono << "}";
	return ss.str();
}
