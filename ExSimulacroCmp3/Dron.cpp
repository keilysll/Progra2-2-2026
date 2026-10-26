#include "Dron.h"

Dron::Dron(int id, string modelo, int autoMin)
{
	this->id = id;
	this->modelo = modelo;
	this->autoMin = autoMin;
}

Dron::~Dron()
{
}

int Dron::getId()
{
	return id;
}

string Dron::getModelo()
{
	return modelo;
}

int Dron::getAutomin()
{
	return autoMin;
}

bool Dron::operator==(Dron& d)
{
	return id == d.id;
}

bool Dron::operator==(Dron* d)
{
	return id==d->id;
}


string Dron::toStringPtr(Dron* d)
{
	return d->toString();
}

bool Dron::CmpDesc(Dron* d1, Dron* d2)
{
	if (d1->getTipo() != d2->getTipo())
		return d1->getTipo() > d2->getTipo();   
	return d1->getId() < d2->getId();
}

bool Dron::CmpAscID(Dron* d1, Dron* d2)
{
	return d1->id > d2->id;
}

