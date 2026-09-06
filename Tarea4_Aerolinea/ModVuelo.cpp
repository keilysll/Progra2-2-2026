#include "ModVuelo.h"

ModVuelo::ModVuelo(int tam)
{
	this->tam = tam;
	this->ind = 0;
	vuelos = new Vuelo * [tam];
}

ModVuelo::~ModVuelo()
{
	delete[] vuelos;
}

int ModVuelo::getTam()
{
	return tam;
}

int ModVuelo::getInd()
{
	return ind;
}

void ModVuelo::registrar(Vuelo* v)
{
	if (ind < tam)
	{
		vuelos[ind] = v;
		ind++;
	}
}

Vuelo* ModVuelo::buscar(int codigo)
{
	for (int i = 0; i < ind; i++)
	{
		if (vuelos[i]->getCodigo() == codigo)
		{
			return vuelos[i];
		}
	}
	return NULL;
}

string ModVuelo::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss<<vuelos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
