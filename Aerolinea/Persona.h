#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
using namespace std;
class Persona
{
private:
	int ci;
	string nombre;
	string direccion;
	int fono;
public:
	Persona(int ci, string nombre, string direccion, int fono);
	~Persona();
	int getCi();
	string getNombre();
	string getDireccion();
	int getFono();
	void setCi(int ci);
	void setNombre(string nombre);
	void setDireccion(string direccion);
	void setFono(int fono);
	string toJson();
};
