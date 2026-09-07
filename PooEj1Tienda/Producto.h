#pragma once
#include <iostream>
#include<string>



using namespace std;
class Producto
{
private:
	int codigo;
	string nombre;
	double precio;
public:
	Producto();
	Producto(int codigo, string nombre, double precio);
	~Producto();
	int getCodigo();
	string getNombre();
	double getPrecio();
	void setCodigo(int codigo);
	void setNombre(string nombre);
	void setPrecio(double precio);
	void mostrar();
	void toJson();


};

