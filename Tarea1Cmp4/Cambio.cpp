#include "Cambio.h"

Cambio::Cambio(int minuto, string equipo, string jugadorSale, string jugadorEntra):Evento(minuto,equipo)
{
	this->jugadorEntra = jugadorEntra;
	this->jugadorSale = jugadorSale;
}

Cambio::~Cambio()
{
}

string Cambio::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"cambio\",\"minuto\":"<<minuto<<",\"equipo\":\""<<equipo<<"\",\"entra\":\""<<jugadorEntra<<"\",\"sale\":\""<<jugadorSale<<"\"}";
	return ss.str();
}
