#pragma once
#include"ListaArray.h"
#include"Partida.h"
#include"PartidaIndividual.h"
#include"PartidaEquipo.h"

class Torneo
{
private:
	int id;
	string nombre;
	ListaArray<Partida> partidas;
public:
	Torneo(int id, string nombre);
	~Torneo();
	bool operator<<(Partida* p);
	string toString();
	string jugadorMasVictorias();
	int duracionMaxima();
};

