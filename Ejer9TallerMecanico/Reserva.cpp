#include "Reserva.h"

Reserva::Reserva(int id)
{
	this->id = id;
}

Reserva::~Reserva()
{
}

int Reserva::getInd()
{
	return id;
}
