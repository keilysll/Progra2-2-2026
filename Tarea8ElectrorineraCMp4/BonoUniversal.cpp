#include "BonoUniversal.h"

BonoUniversal::BonoUniversal(int kwh):Bono(kwh)
{
}

BonoUniversal::~BonoUniversal()
{
}

string BonoUniversal::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"universal\",\"kwh\":"<<kwh<<"}";
	return ss.str();
}

bool BonoUniversal::aplicable(Carga* c)
{
	return true;
}
