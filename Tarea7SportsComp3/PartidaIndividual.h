#pragma once
#include "Partida.h"
#include"Jugador.h"
class PartidaIndividual :
    public Partida
{
private:
    Jugador* ganador;
    Jugador* perdedor;
public:
    PartidaIndividual(int id, int idGanador, int idPerdedor, int duracion);
    ~PartidaIndividual();
    Jugador* getGanador();
    Jugador* getPerdedor();
    string toString();
};

