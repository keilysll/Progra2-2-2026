#include "Hibrido.h"

Hibrido::Hibrido(string placa, string propetario, int capBat, int capCom):Vehiculo(placa,propetario,capBat)
{
	this->capCom = capCom;
}

Hibrido::Hibrido(string placa) :Vehiculo(placa," ", 0)
{
	this->placa = placa;
}

Hibrido::~Hibrido()
{
}

int Hibrido::getCapCom()
{
	return capCom;
}

string Hibrido::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"hibrido\",\"placa\":\""<<placa<<"\",\"propietario\":\""<<propetario<<"\",\"bateriaKwh\":"<<capBat<<",\"tanqueLitros\":"<<capCom<<"}";
	return ss.str();
}
