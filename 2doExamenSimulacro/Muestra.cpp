#include "Muestra.h"

Muestra::Muestra(int cod, string descrip)
{
	this->cod = cod;
	this->descrip = descrip;
}

Muestra::~Muestra()
{
}

int Muestra::getCod()
{
	return cod;
}

string Muestra::getDescrip()
{
	return descrip;
}

string Muestra::toStringPtr(Muestra* m)
{
	return m->toString();
}
