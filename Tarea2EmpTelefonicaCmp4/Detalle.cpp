#include "Detalle.h"

Detalle::Detalle(int id, int fecha)
{
	this->id = id;
	this->fecha = fecha;

}

Detalle::~Detalle()
{
}

int Detalle::getId()
{
	return id;
}

int Detalle::getFecha()
{
	return fecha;
}

string Detalle::toJsonPtr(Detalle* d)
{
	return d->toJson();
}
