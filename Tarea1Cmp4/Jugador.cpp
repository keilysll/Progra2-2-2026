#include "Jugador.h"
Jugador::Jugador(int ci)
{
	this->ci = ci;
}

Jugador::Jugador(int ci, string nombre, int fono)
{
	this->ci = ci;
	this->nombre = nombre;
	this->fono = fono;
}

Jugador::~Jugador()
{
}

int Jugador::getCi()
{
	return ci;
}

string Jugador::getNombre()
{
	return nombre;
}

int Jugador::getFono()
{
	return fono;
}

string Jugador::toString()
{
	stringstream ss;
	ss << "{\"ci\":"<<ci<<",\"nombre\":\""<<nombre<<"\",\"fono\":"<<fono<<"}";
	return ss.str();
}

string Jugador::toStringPtr(Jugador* j)
{
	return j->toString();
}

bool Jugador::ordenarCiAsc(Jugador* j1, Jugador* j2)
{
	return j1->getCi() > j2->getCi();
}

bool Jugador::operator==(Jugador* j)
{
	return ci == j->ci;
}
