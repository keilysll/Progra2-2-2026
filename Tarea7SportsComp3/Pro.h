#pragma once
#include "Jugador.h"
class Pro :
    public Jugador
{
private:
    int ranking;
    int salario;

 public:
     Pro(int id);
     Pro(int id, string nick, string pais, int ranking,int salario);
     ~Pro();
     int getRank();
     int getSalario();
     string toString();

};

