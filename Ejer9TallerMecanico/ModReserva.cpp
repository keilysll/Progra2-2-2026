#include "ModReserva.h"

ModReserva::ModReserva(int tam)
{
	this->tam = tam;
	this->ind = 0;
	reservas = new Reserva * [tam];
}

ModReserva::~ModReserva()
{
	delete[]reservas;
}

int ModReserva::getTam()
{
	return tam;
}

int ModReserva::getInd()
{
	return ind;
}

void ModReserva::registrar(Reserva* r)
{
	if (ind < tam)
	{
		reservas[ind] = r;
		ind++;
	}

}

Reserva* ModReserva::buscar(int id)
{
	for (int i = 0; i < ind; i++)
	{
		if (reservas[i]->getInd() == id)
		{
			return reservas[i];
		}
	}
	return NULL;
}

string ModReserva::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << reservas[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";

	return ss.str();
}
