#pragma once
#include"ModRecinto.h"
#include"ModMesaAsignada.h"
#define CANT_MAX_DEMESA_A_RECINTO 10
class RecintoAsignado
{
private:
	ModMesaAsignada mesas;
	Recinto* recinto;
public:
	RecintoAsignado(Recinto* recinto);
	~RecintoAsignado();
	ModMesaAsignada& getMesas();
	Recinto* getRecinto();
	void setRecinto(Recinto* recinto);
	string toJson();
};

