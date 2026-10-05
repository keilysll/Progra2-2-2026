#pragma once
#include"ModVehiculo.h"
class Cliente
{
private:
	int ci;
	string nombre;
	int fono;
	ModVehiculo vehiculos;
public:
	Cliente(int ci, string nombre, int fono);
	~Cliente();
	int getCi();
	string getNombre();
	int getFono();
	void registrar(Vehiculo* v);
	Vehiculo* buscar(string placa);
	string toJson();
};

