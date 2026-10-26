#include "CargadorRapido.h"

CargadorRapido::CargadorRapido(string codigo, int potencia):Cargador(codigo,potencia)
{
	this->costo = 3;
}

CargadorRapido::~CargadorRapido()
{
}

int CargadorRapido::getCosto()
{
	return costo;
}

string CargadorRapido::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"rapido\",\"codigo\":\""<<codigo<<"\",\"potenciaKw\":"<<potencia<<",\"tarifaKwh\":"<<costo<<"}";
	return ss.str();
}
