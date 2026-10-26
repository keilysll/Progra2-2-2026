#pragma once
#include "Jugador.h"
class Amateur :
    public Jugador
{
private:
    string nivel;

public:
    Amateur(int id);
    Amateur(int id, string nick, string pais, string nivel);
    ~Amateur();
    string getNivel();
    string toString();

};

