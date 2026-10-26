#include "Socio.h"

Socio::Socio(int ci)
{
	this->ci = ci;
}

Socio::Socio(int ci, string nombre)
{
	this->ci = ci;
	this->nombre = nombre;
}

Socio::~Socio()
{
}

int Socio::getCi()
{
	return ci;
}

string Socio::getNombre()
{
	return nombre;
}

string Socio::toString()
{
	stringstream ss;
	ss << "{\"ci\":"<<ci<<",\"nombre\":\""<<nombre<<"\"}";
	return ss.str();
}

string Socio::toStringPtr(Socio* s)
{
	return s->toString();
}

bool Socio::OrdenarSociNom(Socio* s1, Socio* s2)
{
	return s1->getNombre() > s2->getNombre();
}

bool Socio::operator==(Socio* s)
{
	return ci == s->ci;
}
