#include "ModServicio.h"

ModServicio::ModServicio(int tam)
{
	this->tam = tam;
	this->ind = 0;
	servicios = new Servicio * [tam];
}

ModServicio::~ModServicio()
{
	delete[]servicios;
}

int ModServicio::getTam()
{
	return tam;
}

int ModServicio::getInd()
{
	return ind;
}

void ModServicio::registrar(Servicio* s)
{
	if (ind < tam)
	{
		servicios[ind] = s;
		ind++;
	}

}

void ModServicio::ordenar()
{
	for (int i = 0; i<ind-1;i++)
	{
		for (int j = i + 1; j < ind; j++)
		{
			if (servicios[i]->getCodigo() > servicios[j]->getCodigo())
			{
				Servicio* aux = servicios[i];
				servicios[i] = servicios[j];
				servicios[j] = aux;
			}
		}
	}
}

Servicio* ModServicio::buscar(int codigo)
{
	for (int i = 0; i < ind; i++)
	{
		if (servicios[i]->getCodigo() == codigo)
		{
			return servicios[i];
		}
	}
	return NULL;
}

string ModServicio::toJson()
{
	ordenar();
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << servicios[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";

	return ss.str();
}
