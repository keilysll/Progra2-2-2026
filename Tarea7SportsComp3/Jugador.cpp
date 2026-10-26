#include "Jugador.h"

Jugador::Jugador(int id)
{
	this->id = id;
}

Jugador::Jugador(int id, string nick, string pais)
{
	this->id = id;
	this->nick = nick;
	this->pais = pais;
}

Jugador::~Jugador()
{
}

int Jugador::getId()
{
	return id;
}

string Jugador::getNick()
{
	return nick;
}

string Jugador::getPais()
{
	return pais;
}

bool Jugador::operator==(Jugador* j)
{
	return id == j->getId();
}

string Jugador::toStringPtr(Jugador* j)
{
	return j->toString();
}
