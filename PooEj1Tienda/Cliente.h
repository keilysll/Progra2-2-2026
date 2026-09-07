#pragma once
#include <iostream>
#include<string>
using namespace std;
class Cliente
{
private:
	int ci;
	string nombre;
	int fono;
public:
	Cliente(int ci, string nombre,int fono);
	~Cliente();
	int getCi();
	string getNombre();
	int getFono();
	void setCi(int ci);
	void setNombre(string nombre);
	void setFono(int fono);
	void mostrar();

};

