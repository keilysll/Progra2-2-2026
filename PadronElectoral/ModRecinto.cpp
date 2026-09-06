#include "ModRecinto.h"

ModRecinto::ModRecinto(int tam)
{
	this->tam = tam;
	this->ind = 0;
	recintos = new Recinto * [tam];
}

ModRecinto::~ModRecinto()
{
	delete[] recintos;
}

void ModRecinto::registrar(Recinto* r)
{
	if (ind < tam)
	{
		recintos[ind] = r;
		ind++;
	}
}

Recinto* ModRecinto::buscar(int codigo)
{
	for (int i = 0; i < ind; i++)
	{
		if (recintos[i]->getCodigo() == codigo)
		{
			return recintos[i];
		}
	}
	return NULL;
}

int ModRecinto::getInd()
{
	return ind;
}

int ModRecinto::getTam()
{
	return tam;
}

string ModRecinto::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << recintos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
