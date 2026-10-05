#pragma once
#include "Medico.h"
class MedicoGeneral :
    public Medico
{
private:
    string turno;
public:
    MedicoGeneral(string nombre, string turno);
    ~MedicoGeneral();
    string getTurno();
    string toJson();
};

