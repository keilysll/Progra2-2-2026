#pragma once
#include"Vehiculo.h"
#include"Electrico.h"
#include"Hibrido.h"
#include"ListaArray.h"
class SingletonVehiculos
{
private:
	ListaArray<Vehiculo> vehiculos;

public:
	~SingletonVehiculos();
	static SingletonVehiculos& getInst();
	bool operator<< (Vehiculo * v);
	Vehiculo* operator[] (string placa);
	string toString();


private:
	SingletonVehiculos();
};

