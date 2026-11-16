#pragma once
#include "Detalle.h"
class Descarga :
    public Detalle
{
private:
    int megas;
public:
    Descarga(int id, int megas, int fecha);
    ~Descarga();
    int getMegas();
    string toJson();
    int getCantidad();
    int consumir(Paquete* p, int pendiente);
    int disponible(Paquete* p);
    string getTipo();

};

