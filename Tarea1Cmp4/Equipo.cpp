#include "Equipo.h"

Equipo::Equipo(string nombre)
{
	this->nombre = nombre;
}

Equipo::~Equipo()
{
}

string Equipo::getNombre()
{
	return nombre;
}


string Equipo::toStringPtr(Equipo* e)
{
	return e->toString();
}

bool Equipo::ordenarNombreDes(Equipo* e1, Equipo* e2)
{
	return e1->getNombre() < e2->getNombre();
}

void Equipo::nuevoJugador(int ci, string nombre, int fono)
{
	jugadores.registrar(new Jugador(ci, nombre, fono));
}

Jugador* Equipo::bucarJugador(int ci)
{
	return jugadores.buscar(new Jugador(ci));
}

bool Equipo::operator==(Equipo* e)
{
	return nombre == e->nombre;
}

void Equipo::eliminarJugador(int ci)
{
	jugadores.eliminar(new Jugador(ci));
}

void Equipo::agregarJugador(Jugador* j)
{
	jugadores.registrar(j);
}


string Equipo::toString()
{
	jugadores.ordenar(Jugador::ordenarCiAsc);
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"jugadores\":" << jugadores.toJson(Jugador::toStringPtr) << "}";
	return ss.str();
}