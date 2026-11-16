#include "Gol.h"

Gol::Gol(int minuto, string equipo, string jugador):Evento(minuto,equipo)
{
	this->jugador = jugador;
}

Gol::~Gol()
{
}

string Gol::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"gol\",\"minuto\":" << minuto << ",\"equipo\":\"" << equipo << "\",\"jugador\":\"" << jugador << "\"}";
	return ss.str();
}
