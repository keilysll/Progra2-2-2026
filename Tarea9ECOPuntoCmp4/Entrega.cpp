#include "Entrega.h"

Entrega::Entrega(int id, string material)
{
	this->id = id;
	this->material = material;
}

Entrega::~Entrega()
{
}

int Entrega::getId()
{
	return id;
}

string Entrega::getMaterial()
{
	return material;
}

int Entrega::getPuntos()
{
	return puntos;
}

void Entrega::setPuntos(int puntos)
{
	this->puntos = puntos;
}

string Entrega::getClave() const
{
	return to_string(id);
}
