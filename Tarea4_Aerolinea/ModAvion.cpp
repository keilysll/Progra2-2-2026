#include "ModAvion.h"

ModAvion::ModAvion(int tam)
{
	this->tam = tam;
	this->ind = 0;
	aviones = new Avion * [tam];
}

ModAvion::~ModAvion()
{
	delete[] aviones;
}

int ModAvion::getTam()
{
	return tam;
}

int ModAvion::getInd()
{
	return ind;
}

void ModAvion::registrar(Avion* a)
{
	if (ind < tam)
	{
		aviones[ind] = a;
		ind++;
	}
}

Avion* ModAvion::buscar(int codigo)
{
	for (int i = 0; i < ind; i++)
	{
		if (aviones[i]->getCodigo() == codigo)
		{
			return aviones[i];
		}
	}
	return NULL;
}

string ModAvion::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss<<aviones[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
