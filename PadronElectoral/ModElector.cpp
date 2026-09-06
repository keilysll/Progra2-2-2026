#include "ModElector.h"

ModElector::ModElector(int tam)
{
	this->tam = tam;
	this->ind = 0;
	electores = new Elector * [tam];
}

ModElector::~ModElector()
{
	delete[] electores;
}

void ModElector::registrar(Elector* e)
{
	if (ind < tam)
	{
		electores[ind] = e;
		ind++;
	}
}

Elector* ModElector::buscar(int ci)
{
	for (int i = 0; i < ind; i++)
	{
		if (electores[i]->getCi() == ci)
		{
			return electores[i];
		}
	}
	return NULL;
}

int ModElector::getInd()
{
	return ind;
}

int ModElector::getTam()
{
	return tam;
}

string ModElector::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << electores[i]->toJson();
		if (i < ind - 1)
			ss << ",";
	}
	ss << "]";
	return ss.str();
}
