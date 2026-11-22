#include "BonoEstandar.h"

BonoEstandar::BonoEstandar(int kwh):Bono(kwh)
{
}

BonoEstandar::~BonoEstandar()
{
}

string BonoEstandar::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"estandar\",\"kwh\":"<<kwh<<"}";
	return ss.str();
}

bool BonoEstandar::aplicable(Carga* c)
{
	CargaEstandar* ce = dynamic_cast<CargaEstandar*>(c);
	return ce;
}
