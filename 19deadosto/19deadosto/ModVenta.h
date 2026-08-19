#pragma once
#include"Venta.h"
class ModVenta
{
private:
	Venta** ventas;
	int tam;
	int ind;
public:
	ModVenta(int tamMax);
	~ModVenta();
	void registrar(Venta* c);
	Venta* buscar(int num);
	void mostrar();
};

