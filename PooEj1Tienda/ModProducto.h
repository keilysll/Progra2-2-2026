#pragma once
#include"Producto.h"
class ModProducto
{
private:
	Producto** productos;
	int tam;
	int ind;
public:
	ModProducto(int tam);
	~ModProducto();
	void registrar(Producto* p);
	Producto* buscar(int codigo);
	void mostrar();


};

