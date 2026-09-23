#include "EGSimple.h"

EGSimple::EGSimple(int id, int x, int y):ElementoGrafico(id)
{
	this->x = x;
	this->y = y;
}

int EGSimple::getX()
{
	return x;
}

int EGSimple::getY()
{
	return y;
}
