#include "Partida.h"

Partida::Partida(int id, int duracion)
{
	this->id = id;
	this->duracion = duracion;
}

Partida::~Partida()
{
}

int Partida::getId()
{
	return id;
}

int Partida::getDurac()
{
	return duracion;
}

string Partida::toStringPtr(Partida* p)
{
	return p->toString();
}

bool Partida::OrdenarDuracionDes(Partida* p1, Partida* p2)
{
	return p1->getDurac() > p2->getDurac();
}
