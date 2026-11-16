#include "Torneo.h"
Torneo::Torneo()
{
	modo = 1;
}

Torneo::~Torneo()
{
}

Torneo& Torneo::getEquipos()
{
	modo = 1;
	return *this;
}

Torneo& Torneo::getPartidos()
{
	modo = 2;
	return *this;
}

void Torneo::registrar(string nombre)
{
	equipos.registrar(new Equipo(nombre));
}

void Torneo::registrar(int id, Equipo* local, Equipo* visitante)
{
	partidos.registrar(new Partido(id, local, visitante));
}

Equipo* Torneo::buscar(string nombre)
{
	Equipo* e = equipos.buscar(new Equipo(nombre));
	if (e == NULL)
	{
		throw exception(("Equipo "+ nombre+ " inexistente").c_str());
	}
	return e;
}

string Torneo::toString()
{
	stringstream ss;
	if (modo == 1)
	{
		equipos.ordenar(Equipo::ordenarNombreDes);
		ss << "{\"equipos\":" << equipos.toJson(Equipo::toStringPtr) << "}";
	}
	else
	{
		ss << "{partidos:"<<partidos.toJson(Partido::toStringPtr)<<"}";
	}
	
	return ss.str();
}

Partido* Torneo::buscar(int id)
{

	return partidos.buscar(new Partido(id));
}
