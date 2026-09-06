#include "ModCapacitacion.h"

ModCapacitacion::ModCapacitacion(int tam)
{
	this->tam = tam;
	this->ind = 0;
	capacitaciones = new Capacitacion * [tam];
}

ModCapacitacion::~ModCapacitacion()
{
	delete[] capacitaciones;
}

int ModCapacitacion::getTam()
{
	return tam;
}

int ModCapacitacion::getInd()
{
	return ind;
}

void ModCapacitacion::registrar(Capacitacion* c)
{
	if (ind < tam)
	{
		capacitaciones[ind] = c;
		ind++;
	}
}

Capacitacion* ModCapacitacion::buscar(int codigo)
{
	for (int i = 0; i < ind; i++)
	{
		if (capacitaciones[i]->getCodigo() == codigo)
		{
			return capacitaciones[i];
		}
	}
	return NULL;
}

void ModCapacitacion::ordenar()
{
	for (int i = 0; i < ind - 1; i++)
	{
		for (int j = 0; j < ind - 1 - i; j++)
		{
			if (capacitaciones[j]->getNombre() > capacitaciones[j + 1]->getNombre())
			{
				Capacitacion* temp = capacitaciones[j];
				capacitaciones[j] = capacitaciones[j + 1];
				capacitaciones[j + 1] = temp;
			}
		}
	}

}

string ModCapacitacion::toJson()
{
	ordenar();
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << capacitaciones[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}