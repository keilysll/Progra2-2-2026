#pragma once
#include"Venta.h"
class ModVenta
{
private:
	Venta** ventas;
	int tam;
	int ind;
public:
	ModVenta(int tam);
	~ModVenta();
	void registrar(Venta* v);
	Venta* buscar(int nro);
	void mostrar();


};

