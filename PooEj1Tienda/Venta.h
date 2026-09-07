#pragma once
#include"Cliente.h"
#include"ModProducto.h"
#define CANT_MAX_DE_PRODS_EN_VENTA 10
class Venta
{
private:
	int nro;
	Cliente* clientes; //CLIENTE AGREGADO
	ModProducto productos;
public:
	Venta(int num, Cliente* c);
	~Venta();
	int getNum();
	Cliente* getCliente();
	ModProducto& getProducto();
	void setNum(int num);
	void setCliente(Cliente* c);
	void mostrar();
};

