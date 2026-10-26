#include "PartidaIndividual.h"
PartidaIndividual::PartidaIndividual(int id, int idGanador, int idPerdedor, int duracion) :Partida(id, duracion)
{
	this->ganador = SingletonJugadores::getInst().buscar(idGanador);
	this->perdedor = SingletonJugadores::getInst().buscar(idPerdedor);
}

PartidaIndividual::~PartidaIndividual()
{
}

Jugador* PartidaIndividual::getGanador()
{
	return ganador;
}

Jugador* PartidaIndividual::getPerdedor()
{
	return perdedor;
}

string PartidaIndividual::toString()
{
	stringstream ss;
	ss << "{\"PartidaIndividual\":{\"id\":"<<id<<",\"ganador\":"<<ganador->toString()<<",\"perdedor\":"<<perdedor->toString()<<",\"duracion\":"<<duracion<<"}}";
	return ss.str();
}
