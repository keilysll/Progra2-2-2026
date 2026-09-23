#include "ElementoGrafico.h"

ElementoGrafico::ElementoGrafico(int id)
{
	this->id = id;
}

ElementoGrafico::~ElementoGrafico()
{
}

int ElementoGrafico::getInd()
{
	return id;
}
