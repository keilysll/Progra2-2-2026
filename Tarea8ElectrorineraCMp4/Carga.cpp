#include "Carga.h"

Carga::Carga(int id, int fecha, int kwh)
{
	this->id = id;
	this->fecha = fecha;
	this->kwh = kwh;
	this->costo = 0;
}

Carga::~Carga()
{
}

int Carga::getId()
{
	return id;
}

int Carga::getFecha()
{
	return fecha;
}

int Carga::getKm()
{
	return kwh;
}

int Carga::getCosto()
{
	return costo;
}

void Carga::setCosto(int costo)
{
	this->costo = costo;
}

string Carga::toJsonPtr(Carga* c)
{
	return c->toJson();
}
