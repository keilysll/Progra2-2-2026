#pragma once
#include"Vehiculo.h"
class ModVehiculo
{
private:
	Vehiculo** vehiculos;
	int tam;
	int ind;
public:
	ModVehiculo(int tam);
	~ModVehiculo();
	int getTam();
	int getInd();
	void registrar(Vehiculo * v);
	Vehiculo* buscar(string placa);
	string toJson();
};

