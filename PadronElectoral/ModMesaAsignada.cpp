#include "ModMesaAsignada.h"

ModMesaAsignada::ModMesaAsignada(int tam)
{
	this->tam = tam;
	this->ind = 0;
	mesas = new MesaAsignada * [tam];
}

ModMesaAsignada::~ModMesaAsignada()
{
	delete[] mesas;
}

void ModMesaAsignada::registrar(MesaAsignada* mesa)
{
	if (ind < tam)
	{
		mesas[ind] = mesa;
		ind++;
	}
}

MesaAsignada* ModMesaAsignada::buscar(int nro)
{

	for (int i = 0; i < ind; i++)
	{
		if (mesas[i]->getNro() == nro)
		{
			return mesas[i];
		}
	}
	return NULL;
}



int ModMesaAsignada::getInd()
{
	return ind;
}

int ModMesaAsignada::getTam()
{
	return tam;
}

string ModMesaAsignada::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << mesas[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}