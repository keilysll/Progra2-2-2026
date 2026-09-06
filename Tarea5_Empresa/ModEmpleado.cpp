#include "ModEmpleado.h"

ModEmpleado::ModEmpleado(int tam)
{
	this->tam = tam;
	this->ind = 0;
	empleados = new Empleado * [tam];
}

ModEmpleado::~ModEmpleado()
{
	delete[] empleados;
}

int ModEmpleado::getTam()
{
	return tam;
}

int ModEmpleado::getInd()
{
	return ind;
}

void ModEmpleado::registrar(Empleado* e)
{
	if (ind < tam)
	{
		empleados[ind] = e;
		ind++;
	}
}

Empleado* ModEmpleado::buscar(int ci)
{
	for (int i = 0; i < ind; i++)
	{
		if (empleados[i]->getCi() == ci)
		{
			return empleados[i];
		}
	}
	return NULL;
}

void ModEmpleado::ordenar()
{
	for (int i = 0; i < ind - 1; i++)
	{
		for (int j = 0; j < ind - 1 - i; j++)
		{
			if (empleados[j]->getCi() > empleados[j + 1]->getCi())
			{
				Empleado* temp = empleados[j];
				empleados[j] = empleados[j + 1];
				empleados[j + 1] = temp;
			}
		}
	}
	
}

string ModEmpleado::toJson()
{
	ordenar();
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << empleados[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
