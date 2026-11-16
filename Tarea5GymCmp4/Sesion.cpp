#include "Sesion.h"

Sesion::Sesion(int fecha)
{
	this->fecha = fecha;
}

Sesion::~Sesion()
{
}

int Sesion::getFecha()
{
	return fecha;
}

bool Sesion::operator==(Sesion* s)
{
	return fecha == s->fecha;
}

string Sesion::toString()
{
	stringstream ss;
	ss << "{\"fecha\":"<<fecha<<",\"asistentes\":"<<asistentes.toJson(Socio::toStringPtr)<<"}";
	return ss.str();
}

string Sesion::toStringPtr(Sesion* s)
{
	return s->toString();
}

void Sesion::registrarAsistente(Socio* s)
{
	asistentes.registrar(s);
}


