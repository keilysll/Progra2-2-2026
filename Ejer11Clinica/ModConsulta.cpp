#include "ModConsulta.h"

ModConsulta::ModConsulta(int tam)
{
	this->tam = tam;
	this->ind = 0;
	consultas = new Consulta * [tam];
}

ModConsulta::~ModConsulta()
{
}

int ModConsulta::getTam()
{
	return tam;
}

int ModConsulta::getInd()
{
	return ind;
}

void ModConsulta::registrar(Consulta* c)
{
	if (ind < tam)
	{
		consultas[ind] = c;
		ind++;
	}
}

Consulta* ModConsulta::buscar(string paciente)
{
	for (int i = 0; i < ind; i++)
	{
		if (consultas[i]->getPaciente() == paciente)
		{
			return consultas[i];
		}
	}
	return NULL;
}

int ModConsulta::totalIngresos()
{
	int total = 0;
	for (int i = 0; i < ind; i++)
	{
		total = total + consultas[i]->ingreso();
	}
	return total;
}

string ModConsulta::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << consultas[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
