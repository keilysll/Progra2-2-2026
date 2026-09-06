#pragma once
#include"Mesa.h"
#include"ModElector.h"
#define CANT_MAX_ELECT_MESASIG 10

class MesaAsignada
{
private:
	ModElector electores;
	ModElector jurados;
	Mesa* mesa;
	int nro;

public:
	MesaAsignada(Mesa* mesa, int nro);
	~MesaAsignada();
	ModElector& getElectores();
	ModElector& getJurados();
	Mesa* getMesa();
	int getNro();

	void setNro(int nro);
	void setElectores(ModElector& electores);
	void setJurados(ModElector& jurados);

	string toJson();


};

