#include "ModMesa.h"

ModMesa::ModMesa(int tam)
{
	this->tam = tam;
	this->ind = 0;
	mesas = new Mesa * [tam];
}

ModMesa::~ModMesa()
{
	delete[] mesas;
}

void ModMesa::registrar(Mesa* m)
{
	if (ind < tam)
	{
		mesas[ind] = m;
		ind++;
	}
}

Mesa* ModMesa::buscar(int codigo)
{
	for (int i = 0; i < ind; i++)
	{
		if (mesas[i]->getCodigo() == codigo)
		{
			return mesas[i];
		}
	}
	return NULL;
}

int ModMesa::getInd()
{
	return ind;
}

int ModMesa::getTam()
{
	return tam;
}

string ModMesa::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << mesas[i]->toJson();
		if (i < ind - 1)
			ss << ",";
	}
	ss << "]";
	return ss.str();
}