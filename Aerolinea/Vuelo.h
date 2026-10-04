#pragma once
#include"Avion.h"
#include"ModAsiento.h"
class Vuelo
{
private:
	int numero;
	Avion* avion;
	ModAsiento asientos;
public:
	Vuelo(int numero, Avion* avion);
	~Vuelo();
	int getNumero();
	Avion* getAvion();
	ModAsiento& getAsientos();
	void registrarPasajero(int fila, int columna, Persona* p);
	void intercambiarAsiento(Asiento* a1, Asiento* a2);
	string toJson();
};
