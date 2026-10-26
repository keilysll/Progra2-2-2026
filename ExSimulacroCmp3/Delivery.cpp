#include "Delivery.h"

Delivery::Delivery(int id, string modelo, int autoMin, double capac):Dron(id,modelo,autoMin)
{
	this->capac = capac;
	tipo = "delivery";
}

Delivery::Delivery(int id) :Dron(id," ", 0)
{
}

Delivery::~Delivery()
{
}

double Delivery::getCapc()
{
	return capac;
}

string Delivery::toString()
{
	
	stringstream ss;
	ss << "{\"tipo\":\""<<tipo<<"\",\"id\":"<<id<<",\"modelo\":\""<<modelo<<"\",\"autonomiaMin\":"<<autoMin<<",\"capacidadKg\":"<<capac<<"}";
	return ss.str();
}

string Delivery::getTipo()
{
	return tipo;
}



