#pragma once
#include "Detalle.h"
#include"Paquete.h"
class Llamada :
    public Detalle
{
private:
    int duracion;
public:
    Llamada(int id, int fecha,int duracion);
    ~Llamada();
    int getDuracion();
    int getCantidad();
    string toJson();
    int consumir(Paquete* p, int pendiente);
    int disponible(Paquete* p);
    string getTipo();

};

