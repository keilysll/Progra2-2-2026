#pragma once
#include"Reserva.h"
#include"ReservaSimple.h"
#include"ReservaCombo.h"
class ModReserva
{
private:
	Reserva** reservas;
	int tam;
	int ind;
public:
	ModReserva(int tam);
	~ModReserva();
	int getTam();
	int getInd();
	void registrar(Reserva* r);
	//void ordenar();
	Reserva* buscar(int id);
	string toJson();
};

