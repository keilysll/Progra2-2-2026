#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Empleado
{
private:
	string nombre;
	int ci;
	int fono;

public:
	Empleado(string nombre, int ci, int fono);
	~Empleado();
	string getNombre();
	int getCi();
	int getFono();
	void setNombre(string nombre);
	void setCi(int ci);
	void setFono(int fono);
	string toJson();
};

