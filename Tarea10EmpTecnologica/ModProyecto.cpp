#include "ModProyecto.h"

ModProyecto::ModProyecto(int tam)
{
	this->tam = tam;
	this->ind = 0;
	proyectos = new Proyecto * [tam];
}

ModProyecto::~ModProyecto()
{
	delete[]proyectos;
}

int ModProyecto::getTam()
{
	return tam;
}

int ModProyecto::getInd()
{
	return ind;
}

void ModProyecto::registrar(Proyecto* m)
{
	if (ind < tam)
	{
		proyectos[ind] = m;
		ind++;
	}
}

Proyecto* ModProyecto::buscar(string nombre)
{
	for (int i = 0; i < ind; i++)
	{
		if (proyectos[i]->getNombre() == nombre)
		{
			return proyectos[i];
		}
	}
	return NULL;
}

string ModProyecto::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << proyectos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}