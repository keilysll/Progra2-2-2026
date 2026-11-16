#include "Credito.h"

Credito::Credito(int cuota)
{
	this->cuota = cuota;
}

Credito::~Credito()
{
}

int Credito::getCuota()
{
	return cuota;
}

string Credito::toJsonPtr(Credito* c)
{
	return c->toJson();
}
