#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Recinto
{
private:
	int codigo;
	string nombre;
	string direccion;
public:
	Recinto(int codigo, string nombre, string direccion);
	~Recinto();
	int getCodigo();
	string getNombre();
	string getDireccion();
	void setCodigo(int codigo);
	void setNombre(string nombre);
	void setDireccion(string direccion);
	string toJson();

};

