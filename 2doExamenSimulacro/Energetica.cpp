#include "Energetica.h"

Energetica::Energetica(int cod, string descrip, int energia, int radiacion):Muestra(cod,descrip)
{
	this->energia = energia;
	this->radiacion = radiacion;
}

Energetica::~Energetica()
{
}

int Energetica::getEner()
{
	return energia;
}

int Energetica::getRad()
{
	return radiacion;
}

string Energetica::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"energetica\",\"codigo\":"<<cod<<",\"descripcion\":\""<<descrip<<"\",\"energia\":"<<energia<<",\"radiacion\":"<<radiacion<<"}";
	return ss.str();
}
