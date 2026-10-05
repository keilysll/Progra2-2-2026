#include "ModModelo.h"

ModModelo::ModModelo(int tam)
{
	this->tam = tam;
	this->ind = 0;
	modelos = new Modelo * [tam];
}

ModModelo::~ModModelo()
{
	delete[]modelos;
}

int ModModelo::getTam()
{
	return tam;
}

int ModModelo::getInd()
{
	return ind;
}

void ModModelo::registrar(Modelo* m)
{
	if (ind < tam)
	{
		modelos[ind] = m;
		ind++;
	}
}

Modelo* ModModelo::buscar(string nombre)
{
	for (int i = 0; i < ind; i++)
	{
		if (modelos[i]->getNombre() == nombre)
		{
			return modelos[i];
		}
	}
	return NULL;
}

string ModModelo::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << modelos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
