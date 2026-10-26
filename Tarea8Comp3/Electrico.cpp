#include "Electrico.h"

Electrico::Electrico(string placa) :Vehiculo(placa," ",0)
{
}

Electrico::Electrico(string placa, string propetario, int capBat):Vehiculo(placa,propetario,capBat)
{
}

Electrico::~Electrico()
{
}

string Electrico::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"electrico\",\"placa\":\""<<placa<<"\",\"propietario\":\""<<propetario<<"\",\"bateriaKwh\":"<<capBat<<"}";
	return ss.str();
}
