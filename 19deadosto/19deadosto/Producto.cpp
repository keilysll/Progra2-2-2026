#include "Producto.h"

Producto::Producto()
{
}
Producto::Producto(int codigo, string nombre, double precio)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this->precio = precio;
}

Producto::~Producto()
{
}

int Producto::getCodigo()
{
	return codigo;
}

string Producto::getNombre()
{
	return nombre;
}

double Producto::getPrecio()
{
	return precio;
}

void Producto::setCodigo(int codigo)
{
	this->codigo = codigo;
	

}

void Producto::setNombre(string nombre)
{
	this->nombre = nombre;
	
}

void Producto::setPrecio(double precio)
{
	this->precio = precio;
}

void Producto::mostrar()
{
	cout << "codigo: " << codigo << "nombre: " << nombre << "precio: " << precio << endl;
}