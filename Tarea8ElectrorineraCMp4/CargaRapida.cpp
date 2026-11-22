#include "CargaRapida.h"

CargaRapida::CargaRapida(int id, int fecha, int kwh):Carga(id,fecha,kwh)
{
}

CargaRapida::~CargaRapida()
{
}

int CargaRapida::getCosto()
{
	return costo;
}

string CargaRapida::toJson()
{
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"fecha\":"<<fecha<<",\"tipo\":\"rapida\",\"kwh\":"<<kwh<<",\"costo\":"<<costo<<"}";
	return ss.str();
}

int CargaRapida::getTarifa()
{
	return 3;
}
