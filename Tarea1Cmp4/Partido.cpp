#include "Partido.h"

Partido::Partido(int id)
{
	this->id = id;
}

Partido::Partido(int id, Equipo* local, Equipo* visitante)
{
	this->id = id;
	this->local = local;
	this->visitante = visitante;
}

Partido::~Partido()
{
}

int Partido::getId()
{
	return id;
}

string Partido::toString()
{
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"local\":"<<local->toString()<<",\"visitante\":"<<visitante->toString()<<",\"eventos\":"<<eventos.toJson(Evento::toStringPtr)<<"}";
	return ss.str();
}

string Partido::toStringPtr(Partido* p)
{
	return p->toString();
}

bool Partido::operator==(Partido* p)
{
	return id == p->id;
}

void Partido::gol(int minuto, string equipo, int ci)
{
	Equipo* e;
	if (local->getNombre() == equipo)
		e = local;
	else
		e = visitante;

	Jugador* j = e->bucarJugador(ci);
	eventos.registrar(new Gol(minuto, equipo, j->getNombre()));
}

void Partido::cambio(int minuto, string equipo, int ci, Jugador* nuevo)
{
	Equipo* e;
	if (local->getNombre() == equipo)
		e = local;
	else
		e = visitante;
	Jugador* j = e->bucarJugador(ci);
	eventos.registrar(new Cambio(minuto, equipo, j->getNombre(), nuevo->getNombre()));
	e->eliminarJugador(ci);
	e->agregarJugador(nuevo);
}
