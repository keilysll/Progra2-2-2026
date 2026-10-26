#pragma once
#include "Grupo.h"
class Controlado :
    public Grupo
{
public:
    Controlado(string id);
    ~Controlado();
    string toString();
    void registrarAsistente(int ci,int fecha);
};

