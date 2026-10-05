#include "Consultorio.h"

Consultorio::Consultorio(int nro):medicos(10)
{
	this->nro = nro;
}

Consultorio::~Consultorio()
{
}

int Consultorio::getNro()
{
	return nro;
}

ModMedico& Consultorio::getMedicos()
{
	return medicos;
}

void Consultorio::registrar(Medico* m)
{
	medicos.registrar(m);
}

Medico* Consultorio::buscarMed(string nombre)
{
	return medicos.buscar(nombre);
}

string Consultorio::toJson()
{
	stringstream ss;
	ss << "{\"numero\":"<<nro<<",\"medicos\":"<<medicos.toJson()<<"}";
	return ss.str();
}

int Consultorio::totalIngresos()
{
	return medicos.totalIngresos();
}


Medico* Consultorio::medicoConMasIngresos()
{
	return medicos.medicoConMasIngresos();
}
