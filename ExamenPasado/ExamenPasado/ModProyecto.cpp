#include "ModProyecto.h"

ModProyecto::ModProyecto(int tam)
{
	this->tam = tam;
	this->ind = 0;
	proyectos = new Proyecto * [tam];
}

ModProyecto::~ModProyecto()
{
}

int ModProyecto::getTam()
{
	return tam;
}

int ModProyecto::getInd()
{
	return ind;
}

void ModProyecto::registrar(Proyecto* p)
{
	if (ind < tam)
	{
		proyectos[ind] = p;
		ind++;
	}
}

Proyecto* ModProyecto::buscar(int num)
{
	for (int i = 0; i < ind; i++)
	{
		if (proyectos[i]->getNum() == num)
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

