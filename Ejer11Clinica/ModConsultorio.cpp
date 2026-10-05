#include "ModConsultorio.h"
ModConsultorio::ModConsultorio(int tam)
{
	this->tam = tam;
	this->ind = 0;
	consultorios = new Consultorio * [tam];
}

ModConsultorio::~ModConsultorio()
{
	delete[]consultorios;
}

int ModConsultorio::getTam()
{
	return tam;
}

int ModConsultorio::getInd()
{
	return ind;
}

void ModConsultorio::registrar(Consultorio* m)
{
	if (ind < tam)
	{
		consultorios[ind] = m;
		ind++;
	}
}

Consultorio* ModConsultorio::buscar(int nro)
{
	for (int i = 0; i < ind; i++)
	{
		if (consultorios[i]->getNro() == nro)
		{
			return consultorios[i];
		}
	}
	return NULL;
}

string ModConsultorio::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << consultorios[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}

int ModConsultorio::totalIngresos()
{
	int total = 0;
	for (int i = 0; i < ind; i++)
	{
		total = total + consultorios[i]->totalIngresos();
	}
	return total;
}

Medico* ModConsultorio::medicoConMasIngresos()
{
	Medico* mejor = NULL;
	for (int i = 0; i < ind; i++)
	{
		Medico* candidato = consultorios[i]->medicoConMasIngresos();
		if (candidato != NULL && (mejor == NULL || candidato->ingreso() > mejor->ingreso()))
		{
			mejor = candidato;
		}
	}
	return mejor;
}
