#pragma once
#include "Reserva.h"
#
class ReservaSimple :
    public Reserva
{

	private:
		Cliente* cliente;
		Vehiculo* vehiculo;
		Servicio* servicio;
	public:
		ReservaSimple(int id, Servicio * s, Cliente * c, Vehiculo * v);
		~ReservaSimple();
		string toJson();

};

