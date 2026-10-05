#include "Medico.h"

Medico::Medico(string nombre):consultas(10)
{
	this->nombre = nombre;
}

Medico::~Medico()
{
}

string Medico::getNombre()
{
	return nombre;
}

ModConsulta& Medico::getConsultas()
{
	return consultas;
}

void Medico::registrar(Consulta* c)
{
	consultas.registrar(c);
}

int Medico::ingreso()
{
	return consultas.totalIngresos();
}
