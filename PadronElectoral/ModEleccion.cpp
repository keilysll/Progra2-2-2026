#include "ModEleccion.h"

ModEleccion::ModEleccion(int tam)
{
	this->tam = tam;
	this->ind = 0;
	elecciones = new Eleccion * [tam];
}

ModEleccion::~ModEleccion()
{
	delete[] elecciones;
}

void ModEleccion::registrar(Eleccion* e)
{
	if (ind < tam)
	{
		elecciones[ind] = e;
		ind++;
	}
}

Eleccion* ModEleccion::buscar(int codigo)
{
	for (int i = 0; i < ind; i++)
	{
		if (elecciones[i]->getCodigo() == codigo)
		{
			return elecciones[i];
		}
	}
	return NULL;
}

int ModEleccion::getInd()
{
	return ind;
}

int ModEleccion::getTam()
{
	return tam;
}

string ModEleccion::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << elecciones[i]->toJson();
		if (i < ind - 1)
			ss << ",";
	}
	ss << "]";
	return ss.str();
}

