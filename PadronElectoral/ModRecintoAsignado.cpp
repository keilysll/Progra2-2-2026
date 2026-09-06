#include "ModRecintoAsignado.h"

ModRecintoAsignado::ModRecintoAsignado(int tam)
{
	this->tam = tam;
	this->ind = 0;
	recintos = new RecintoAsignado * [tam];
}

ModRecintoAsignado::~ModRecintoAsignado()
{
	delete[] recintos;
}

void ModRecintoAsignado::registrar(RecintoAsignado* r)
{
	if (ind < tam)
	{
		recintos[ind] = r;
		ind++;
	}
}

RecintoAsignado* ModRecintoAsignado::buscar(int codigo)
{

	for (int i = 0; i < ind; i++)
	{
		if (recintos[i]->getRecinto()->getCodigo() == codigo)
		{
			return recintos[i];
		}
	}
	return NULL;
}


int ModRecintoAsignado::getInd()
{
	return ind;
}

int ModRecintoAsignado::getTam()
{
	return tam;
}

string ModRecintoAsignado::toJson()
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