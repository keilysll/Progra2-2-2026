#include "Elector.h"

Elector::Elector(int ci, string nombre, int fono)
{
	this->ci = ci;
	this->nombre = nombre;
	this->fono = fono;
}

Elector::~Elector()
{
}

int Elector::getCi()
{
	return ci;
}

string Elector::getNombre()
{
	return nombre;
}

int Elector::getFono()
{
	return fono;
}

void Elector::setCi(int ci)
{

	this->ci = ci;
	
}

void Elector::setNombre(string nombre)
{
	this->nombre = nombre;
	
}

void Elector::setFono(int fono)
{
	this->fono = fono;
}

string Elector::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"CI\":" << ci << ",";
	ss << "\"Nombre\":\"" << nombre << "\",";
	ss << "\"Fono\":" << fono;
	ss << "}";
	return ss.str();
}
