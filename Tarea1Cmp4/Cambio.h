#pragma once
#include "Evento.h"
class Cambio :
    public Evento
{
private:
	string jugadorSale;
	string jugadorEntra;
public:
	Cambio(int minuto, string equipo, string jugadorSale,string jugadorEntra);
	~Cambio();
	string toString();
};

