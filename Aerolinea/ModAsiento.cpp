#include "ModAsiento.h"

ModAsiento::ModAsiento(int tam)
{
	this->tam = tam;
	this->ind = 0;
	asientos = new Asiento * [tam];
}

ModAsiento::~ModAsiento()
{
	delete[] asientos;
}

int ModAsiento::getTam()
{
	return tam;
}

int ModAsiento::getInd()
{
	return ind;
}

void ModAsiento::registrar(Asiento* a)
{
	if (ind < tam)
	{
		asientos[ind] = a;
		ind++;
	}
}

Asiento* ModAsiento::buscar(int fila, int columna)
{
	for (int i = 0; i < ind; i++)
	{
		if (asientos[i]->getFila() == fila && asientos[i]->getColumna() == columna)
		{
			return asientos[i];
		}
	}

	return NULL;
}

string ModAsiento::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << asientos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}

	ss << "]";
	return ss.str();
}
