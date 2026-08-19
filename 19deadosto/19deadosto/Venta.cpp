#include "Venta.h"

Venta::Venta(int num, Cliente* c)
{
	this->num = num;
	this-> cliente = c;
}

Venta::~Venta()
{
}

int Venta::getNum()
{
	return num;
}

Cliente* Venta::getCliente()
{
	return cliente;
}

void Venta::setNum(int num)
{
	this->num = num;
	
}

void Venta::setCliente(Cliente* c)
{
	this->cliente = c;
}

void Venta::mostrar()
{
	cout << "num: " << num << "cliente: " << cliente << endl;
}
