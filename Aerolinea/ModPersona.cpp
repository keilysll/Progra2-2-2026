#include "ModPersona.h"

ModPersona::ModPersona(int tam)
{
	this->tam = tam;
	this->ind = 0;
	personas = new Persona * [tam];
}

ModPersona::~ModPersona()
{
	delete[] personas;
}

int ModPersona::getTam()
{
	return tam;
}

int ModPersona::getInd()
{
	return ind;
}

void ModPersona::registrar(Persona* p)
{
	if (ind < tam)
	{
		personas[ind] = p;
		ind++;
	}
}

Persona* ModPersona::buscar(int ci)
{
	for (int i = 0; i < ind; i++)
	{
		if (personas[i]->getCi() == ci)
		{
			return personas[i];
		}
	}

	return NULL;
}

void ModPersona::ordenar()
{
	for (int i = 0; i < ind - 1; i++)
	{
		for (int j = 0; j < ind - 1 - i; j++)
		{
			if (personas[j]->getCi() > personas[j + 1]->getCi())
			{
				Persona* temp = personas[j];
				personas[j] = personas[j + 1];
				personas[j + 1] = temp;
			}
		}
	}
}

string ModPersona::toJson()
{
	ordenar();
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << personas[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}

	ss << "]";
	return ss.str();
}
