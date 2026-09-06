#include "MesaAsignada.h"

MesaAsignada::MesaAsignada(Mesa* mesa, int nro):electores(CANT_MAX_ELECT_MESASIG),jurados(CANT_MAX_ELECT_MESASIG)
{
	this->mesa = mesa;
	this->nro = nro;
}
MesaAsignada::~MesaAsignada()
{
}

ModElector& MesaAsignada::getElectores()
{
	return electores;
}

ModElector& MesaAsignada::getJurados()
{
	return jurados;
}

Mesa* MesaAsignada::getMesa()
{
	return mesa;
}

int MesaAsignada::getNro()
{
	return nro;
}

void MesaAsignada::setNro(int nro)
{
	this->nro = nro;
}

void MesaAsignada::setElectores(ModElector& electores)
{
	this->electores = electores;
}

void MesaAsignada::setJurados(ModElector& jurados)
{
	this->jurados = jurados;
}

string MesaAsignada::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Nro\":" << nro<< ",";
	ss << "\"Electores\":" << electores.toJson() << ",";
	ss << "\"Jurados\":" << jurados.toJson() << ",";
	ss << "\"Mesa\":" << mesa->toJson();
	ss << "}";
	return ss.str();
}
