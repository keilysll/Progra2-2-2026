#include "ModMedico.h"

ModMedico::ModMedico(int tam)
{
	this->tam = tam;
	this->ind = 0;
	medicos = new Medico * [tam];
}

ModMedico::~ModMedico()
{
	delete[]medicos;
}

int ModMedico::getTam()
{
	return tam;
}

int ModMedico::getInd()
{
	return ind;
}

void ModMedico::registrar(Medico* m)
{
	if (ind < tam)
	{
		medicos[ind] = m;
		ind++;
	}
}

Medico* ModMedico::buscar(string nombre)
{
	for (int i=0;i<ind;i++)
	{
		if (medicos[i]->getNombre() == nombre)
		{
			return medicos[i];
		}
	}
	return NULL;
}

string ModMedico::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << medicos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}

int ModMedico::totalIngresos()
{
	int total = 0;
	for (int i = 0; i < ind; i++)
	{
		total = total + medicos[i]->ingreso();
	}
	return total;
}

Medico* ModMedico::medicoConMasIngresos()
{
	Medico* mejor = NULL;
	for (int i = 0; i < ind; i++)
	{
		if (mejor == NULL || medicos[i]->ingreso() > mejor->ingreso())
		{
			mejor = medicos[i];
		}
	}
	return mejor;
}
