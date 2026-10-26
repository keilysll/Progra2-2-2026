#include "Sesion.h"

Sesion::Sesion(int fecha):asistentes(20)
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

string Sesion::toString()
{
	stringstream ss;
	ss << "{\"fecha\":" << fecha << ",\"asistentes\":" << asistentes.toJson(Socio::toStringPtr) << "}";
	return ss.str();
}

string Sesion::toStringPtr(Sesion* s)
{
	return s->toString();
}

void Sesion::registrarAsistente(Socio* a)
{
	asistentes.registrar(a);
}

bool Sesion::operator==(Sesion* s)
{
	return fecha == s->fecha;
}
