#include "Mision.h"

Mision::Mision(int id, int idDron, int durMin)
{
	this->id = id;
	this->idDron = idDron;
	this->durMin = durMin;
}

Mision::~Mision()
{
}

int Mision::getId()
{
	return id;
}

int Mision::getDronid()
{
	return idDron;
}

int Mision::getDurMin()
{
	return durMin;
}

string Mision::getTipo()
{
	return tipo;
}

string Mision::toStringPtr(Mision* m)
{
	return m->toString();
}

bool Mision::OrdMision(Mision* m1, Mision* m2)
{
	if (m1->getTipo() != m2->getTipo())
		return m1->getTipo() > m2->getTipo();
	return m1->getId() > m2->getId();
}
