#pragma once
#include"Asiento.h"
class ModAsiento
{
private:
	Asiento** asientos;
	int tam;
	int ind;
public:
	ModAsiento(int tam);
	~ModAsiento();
	int getTam();
	int getInd();
	void registrar(Asiento* a);
	Asiento* buscar(int fila, int columna);
	string toJson();
};
