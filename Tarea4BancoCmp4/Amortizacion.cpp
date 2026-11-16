#include "Amortizacion.h"

Amortizacion::Amortizacion(int id, int fecha, int monto):Pago(id,fecha)
{
	this->monto = monto;
}

Amortizacion::~Amortizacion()
{
}

int Amortizacion::getMonto()
{
	return monto;
}

string Amortizacion::toJson()
{
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"fecha\":"<<fecha<<",\"monto\":"<<monto<<",\"tipo\":\"amortizacion\"}";
	return ss.str();
}

string Amortizacion::getTipo()
{
	return "amortizacion";
}
