#pragma once
#include"Cliente.h"
#include"Vehiculo.h"
#include"Servicio.h"
class Reserva
{
protected:
	int id;
public:
	Reserva(int id);
	~Reserva();
	int getInd();
	virtual string toJson() = 0;
};

