#include "Modelo.h"

Modelo::Modelo(string nombre)
{
	this->nombre = nombre;
}

Modelo::~Modelo()
{
}

string Modelo::getNombre()
{
	return nombre;
}
