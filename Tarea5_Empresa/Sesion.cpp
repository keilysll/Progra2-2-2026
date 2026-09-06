#include "Sesion.h"

Sesion::Sesion(int nro):asistentes(10)
{
	this->nro = nro;
}

Sesion::~Sesion()
{
}

int Sesion::getNro()
{
	return nro;
}

ModEmpleado& Sesion::getAsistentes()
{
	return asistentes;
}

void Sesion::setNro(int nro)
{
	this->nro = nro;
}

void Sesion::registrarAsistencia(Empleado* e)
{
	asistentes.registrar(e);
}

string Sesion::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\Nro\":" << nro<< ",";
	ss << "\Asistentes\":" << asistentes.toJson() << ",";
	ss << "}";
	return ss.str();
}
