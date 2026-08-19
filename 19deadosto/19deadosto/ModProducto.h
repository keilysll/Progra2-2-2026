#pragma once
#include"Producto.h"
class ModProducto
{
private:
	Producto** Productos;
	int tam;
	int ind;
public:
	ModProducto(int tamMax);
	~ModProducto();
	void registrar(Producto* c);
	Producto* buscar(int codigo);
	void mostrar();
};

