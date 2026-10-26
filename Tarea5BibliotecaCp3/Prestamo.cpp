#include "Prestamo.h"

Prestamo::Prestamo(int id, Libro* l, Socio* s, int fechaIni, int fechaDev)
{
	this->id = id;
	this-> l = l;
	this->s = s;
	this->fechaIni = fechaIni;
	this->fechaDev = fechaDev;
}

Prestamo::~Prestamo()
{
}

int Prestamo::getId()
{
	return id;
}

int Prestamo::getfechaIni()
{
	return fechaIni;
}

int Prestamo::getfechaDev()
{
	return fechaDev ;
}

Libro* Prestamo::getLibro()
{
	return l;
}

string Prestamo::toStringPtr(Prestamo* p)
{
	return p->toString();
}

bool Prestamo::OrdenarFechDevPres(Prestamo* p1, Prestamo* p2)
{
	return p1->getfechaDev() > p2->getfechaDev();
}


