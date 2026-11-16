#include "Evento.h"
Evento::Evento(int minuto, string equipo)
{
	this->minuto = minuto;
	this->equipo = equipo;
}

Evento::~Evento()
{
}

int Evento::getMin()
{
	return minuto;
}

string Evento::getEquipo()
{
	return equipo;
}


string Evento::toStringPtr(Evento* e)
{
	return e->toString();
}
