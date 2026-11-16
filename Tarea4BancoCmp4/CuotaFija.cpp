#include "CuotaFija.h"

CuotaFija::CuotaFija(int id, int fecha):Pago(id,fecha)
{
}

CuotaFija::~CuotaFija()
{
}

string CuotaFija::toJson()
{
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"fecha\":"<<fecha<<",\"tipo\":\"cuota\"}";
	return ss.str();
}

string CuotaFija::getTipo()
{
	return "cuota";
}


