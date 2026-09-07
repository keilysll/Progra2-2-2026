#include "Venta.h"

Venta::Venta(int num, Cliente* c):productos(CANT_MAX_DE_PRODS_EN_VENTA)
{
	this->nro = num;
	this->clientes = c;
}

Venta::~Venta()
{
}

int Venta::getNum()
{
	return nro;
}

Cliente* Venta::getCliente()
{
	return clientes;
}

ModProducto& Venta::getProducto()
{
	return productos;
}

void Venta::setNum(int num)
{
	this->nro = num;
}

void Venta::setCliente(Cliente* c)
{
	this->clientes = c;
}

void Venta::mostrar()
{
	cout << " num: " << nro << endl;

	cout << " cliente: " << endl;
	clientes->mostrar();

	cout << " productos: " << endl;
	productos.mostrar();
}