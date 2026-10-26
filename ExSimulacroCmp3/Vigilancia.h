#pragma once
#include "Dron.h"
class Vigilancia :
    public Dron
{
private:
    int resolucion;
public:
    Vigilancia(int id, string modelo, int autoMin, int resolucion);
    Vigilancia(int id);
    ~Vigilancia();
    int getResolucion();
    string toString();
    string getTipo();

};

