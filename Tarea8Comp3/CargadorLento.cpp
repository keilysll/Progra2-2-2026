#include "CargadorLento.h"

CargadorLento::CargadorLento(string codigo, int potencia):Cargador(codigo,potencia)
{
	this->costo = 2;
}

CargadorLento::~CargadorLento()
{
}

int CargadorLento::getCosto()
{
	return costo;
}

string CargadorLento::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"lento\",\"codigo\":\""<<codigo<<"\",\"potenciaKw\":"<<potencia<<",\"tarifaKwh\":"<<costo<<"}";
	return ss.str();
}
