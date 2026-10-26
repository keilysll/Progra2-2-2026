#pragma once
#include "Cargador.h"
#include "Vehiculo.h"
class Sesion
{
private:
	int id;
	Cargador* cargador;
	Vehiculo* vehiculo;
	int kwh;
public:
	Sesion(int id, Cargador* cargador, Vehiculo* vehiculo, int kwh);
	~Sesion();
	int getId();
	int getKwh();
	Cargador* getCargador();
	Vehiculo* getVehiculo();
	int getCosto();
	string toString();
	static bool CmpCostoAsc(Sesion* s1, Sesion* s2);
	static string toStringPtr(Sesion* s);
};
