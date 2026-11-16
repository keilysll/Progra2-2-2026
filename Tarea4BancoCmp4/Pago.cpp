#include "Pago.h"

Pago::Pago(int id, int fecha)
{
	this->id = id;
	this->fecha = fecha;
}

Pago::~Pago()
{
}

int Pago::getId()
{
	return id;
}

int Pago::getFecha()
{
	return fecha;
}

string Pago::toJsonPtr(Pago* p)
{
	return p->toJson();
}
