#include "Criatura.h"

Criatura::Criatura(int codigo, string nombre, int peligro)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this->peligro = peligro;
}

Criatura::~Criatura()
{
}

int Criatura::getCodigo()
{
	return codigo;
}

string Criatura::getNombre()
{
	return nombre;
}

int Criatura::getPeligro()
{
	return peligro;
}

bool Criatura::operator==(Criatura* c)
{
	return codigo == c->codigo;
}

bool Criatura::operator==(Criatura& c)
{
	return codigo == c.codigo;
}

string Criatura::toStringPtr(Criatura* c)
{
	return c->toString();
}

bool Criatura::OrdenarDesPeli(Criatura* c1, Criatura* c2)
{
	return c1->getPeligro() < c2->getPeligro();
}
