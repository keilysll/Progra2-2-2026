#include "ModEquipo.h"


ModEquipo::ModEquipo(int tam)
{
	this->tam = tam;
	this->ind = 0;
	equipos = new Equipo * [tam];
}

ModEquipo::~ModEquipo()
{
}

int ModEquipo::getTam()
{
	return tam;
}

int ModEquipo::getInd()
{
	return ind;
}

void ModEquipo::registrar(Equipo* p)
{
	if (ind < tam)
	{
		equipos[ind] = p;
		ind++;
	}
}

Equipo* ModEquipo::buscar(int nro)
{
	for (int i = 0; i < ind; i++)
	{
		if (equipos[i]->getNro() == nro)
		{
			return equipos[i];
		}
	}
	return NULL;
}

string ModEquipo::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << equipos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}

