#include "Bono.h"

Bono::Bono(int kwh)
{
	this->kwh = kwh;
}

Bono::~Bono()
{
}

int Bono::getKwh()
{
	return kwh;
}

void Bono::usar(int Kw)
{
	kwh = kwh - Kw;
}

string Bono::toJsonPtr(Bono* b)
{
	return b->toJson();
}


