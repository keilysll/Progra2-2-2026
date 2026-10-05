#include "Servicio.h"

Servicio::Servicio(int codigo, string descrip, int costo)
{
	this->codigo = codigo;
	this->descrip = descrip;
	this->costo = costo;
}

Servicio::~Servicio()
{
}

int Servicio::getCodigo()
{
	return codigo;
}

string Servicio::getDescrip()
{
	return descrip;
}

int Servicio::getCosto()
{
	return costo;
}
