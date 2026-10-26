#pragma once
#include"Equipo.h"
#include "Partida.h"
class PartidaEquipo :
    public Partida
{
private:
    Equipo* ganador;
    Equipo* perdedor;
public:
    PartidaEquipo(int id, Equipo* ganador, Equipo* perdedor, int duracion);
    ~PartidaEquipo();
    string toString();
};

