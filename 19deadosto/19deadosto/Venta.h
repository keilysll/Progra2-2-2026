#pragma once
#include"Cliente.h"
class Venta
{
private:
	int num;
	Cliente* clientes; //CLIENTE AGREGADO
public:
	Venta(int num, Cliente* c);
	~Venta();
	int getNum();
	Cliente* getCliente();
	void setNum(int num);
	void setCliente(Cliente* c);
	void mostrar();
};

