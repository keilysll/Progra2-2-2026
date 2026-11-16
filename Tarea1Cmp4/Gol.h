#pragma once
#include "Evento.h"
class Gol :
    public Evento
{
private:
	string jugador;
public:
	Gol(int minuto, string equipo, string jugador);
	~Gol();
	string toString();
};

