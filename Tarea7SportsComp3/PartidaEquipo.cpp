#include "PartidaEquipo.h"

PartidaEquipo::PartidaEquipo(int id, Equipo* ganador, Equipo* perdedor, int duracion):Partida(id,duracion)
{
	this->ganador = ganador;
	this->perdedor = perdedor;
}

PartidaEquipo::~PartidaEquipo()
{
}

string PartidaEquipo::toString()
{
	stringstream ss;
	ss << "{\"PartidaEquipo\":{\"id\":"<<id<<",\"ganador\":"<<ganador->toString()<<",\"perdedor\":"<<perdedor->toString()<<",\"duracion\":"<<duracion<<"}}";
	return ss.str();
}
