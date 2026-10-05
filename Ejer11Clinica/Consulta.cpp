#include "Consulta.h"

Consulta::Consulta(string paciente, int costo)
{
	this->paciente = paciente;
	this->costo = costo;
}

Consulta::~Consulta()
{
}

string Consulta::getPaciente()
{
	return paciente;
}

int Consulta::getCosto()
{
	return costo;
}
