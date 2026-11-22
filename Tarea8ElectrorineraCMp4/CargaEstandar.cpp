#include "CargaEstandar.h"

CargaEstandar::CargaEstandar(int id, int fecha, int kwh):Carga(id,fecha,kwh)
{
}

CargaEstandar::~CargaEstandar()
{
}

int CargaEstandar::getCosto()
{
	return costo = kwh * 2;
}

string CargaEstandar::toJson()
{
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"fecha\":"<<fecha<<",\"tipo\":\"estandar\",\"kwh\":"<<kwh<<",\"costo\":"<<costo<<"}";
	return ss.str();
}

int CargaEstandar::getTarifa()
{
	return 2;
}
