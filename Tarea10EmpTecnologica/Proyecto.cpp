#include "Proyecto.h"

Proyecto::Proyecto(string nombre):modelos(10)
{
	this->nombre = nombre;
}

Proyecto::~Proyecto()
{
}

string Proyecto::getNombre()
{
	return nombre;
}

ModModelo& Proyecto::getModelos()
{
	return modelos;
}

void Proyecto::asignar(Modelo* m)
{
	modelos.registrar(m);
}
