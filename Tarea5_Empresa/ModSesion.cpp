#include "ModSesion.h"

ModSesion::ModSesion(int tam)
{
	this->tam = tam;
	this->ind = 0;
	sesiones = new Sesion * [tam];
}

ModSesion::~ModSesion()
{
	delete[] sesiones;
}

int ModSesion::getTam()
{
	return tam;
}

int ModSesion::getInd()
{
	return ind;
}

void ModSesion::registrar(Sesion* s)
{
	if (ind < tam)
	{
		sesiones[ind] = s;
		ind++;
	}
}

Sesion* ModSesion::buscar(int nro)
{
	for (int i = 0; i < ind; i++)
	{
		if (sesiones[i]->getNro() == nro)
		{
			return sesiones[i];
		}
	}
	return NULL;
}


string ModSesion::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << sesiones[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
