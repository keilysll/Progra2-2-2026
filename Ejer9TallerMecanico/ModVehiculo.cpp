#include "ModVehiculo.h"

ModVehiculo::ModVehiculo(int tam)
{
	this->tam = tam;
	this->ind = 0;
	vehiculos = new Vehiculo * [tam];
}

ModVehiculo::~ModVehiculo()
{
	delete[]vehiculos;
}

int ModVehiculo::getTam()
{
	return tam;
}

int ModVehiculo::getInd()
{
	return ind;
}

void ModVehiculo::registrar(Vehiculo* v)
{
	if (ind < tam)
	{
		vehiculos[ind] = v;
		ind++;
	}
	
}

Vehiculo* ModVehiculo::buscar(string placa)
{
	for (int i = 0; i < ind; i++)
	{
		if (vehiculos[i]->getPlaca() == placa)
		{
			return vehiculos[i];
		}
	}
	return NULL;
}

string ModVehiculo::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << vehiculos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";

	return ss.str();
}
