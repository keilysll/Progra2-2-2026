#pragma once
#include "Reserva.h"
class ReservaCombo :
    public Reserva
{
private:
	Cliente* cliente;
	Vehiculo* vehiculo;
	Servicio* servicio1;
	Servicio* servicio2;
public:
	ReservaCombo(int id, Servicio* s1,Servicio* s2, Cliente* c, Vehiculo* v);
	~ReservaCombo();
	string toJson();


};

