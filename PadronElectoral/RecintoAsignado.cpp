#include "RecintoAsignado.h"

RecintoAsignado::RecintoAsignado(Recinto* recinto):mesas(CANT_MAX_DEMESA_A_RECINTO)
{
	this->recinto = recinto;
}

RecintoAsignado::~RecintoAsignado()
{
}

ModMesaAsignada& RecintoAsignado::getMesas()
{
	return mesas;
}

Recinto* RecintoAsignado::getRecinto()
{
	return recinto;
}

void RecintoAsignado::setRecinto(Recinto* recinto)
{
	this->recinto = recinto;
}
string RecintoAsignado::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Recinto\":" << recinto->toJson()<<",";
	ss << "\"MesasAsignada\":"<<mesas.toJson();
	ss << "}";
	return ss.str();
}
