#include "Socio.h"

Socio::Socio(int ci)
{
	this->ci = ci;
}

Socio::Socio(int ci, string nombre, string email)
{
	this->ci = ci;
	this ->nombre = nombre;
	this->email = email;

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

string Socio::getEmail()
{
	return email;
}

string Socio::toString()
{
	stringstream ss;
	ss << "{\"ci\":"<<ci<<",\"nombre\":\""<<nombre<<"\",\"email\":\""<<email<<"\"}";
	return ss.str();
}

string Socio::toStringPtr(Socio* s)
{
	return s->toString();
}

bool Socio::operator==(Socio* s)
{
	return ci == s->ci;
}

bool Socio::ordenarNomSoc(Socio* s1, Socio* s2)
{
	return s1->getNombre() > s2->getNombre();
}
