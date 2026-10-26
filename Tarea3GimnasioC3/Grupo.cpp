#include "Grupo.h"

Grupo::Grupo(string id):inscritos(20),sesiones(20)
{
	this->id = id;
}

Grupo::~Grupo()
{
}

string Grupo::getId()
{
	return id;
}

void Grupo::inscribir(int ci)
{
	Socio* s = SingletonSocios::getInst().getSocios()->buscar(new Socio(ci));
	if (s != NULL)
	{
		inscritos.registrar(s);
	}
}

void Grupo::registrarSesion(int fecha)
{
	Sesion* s = sesiones.buscar(new Sesion(fecha));
	if (s == NULL)
	{
		sesiones.registrar(new Sesion(fecha));
	}
}


string Grupo::toStringPtr(Grupo* g)
{
	return g->toString();
}
