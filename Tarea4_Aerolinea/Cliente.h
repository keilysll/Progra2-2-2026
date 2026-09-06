#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Cliente
{
private:
	string nombre;
	int ci;
	int fono;

public:
	Cliente(string nombre,int ci, int fono);
	~Cliente();
	string getNombre();
	int getCi();
	int getFono();
	void setNombre(string nombre);
	void setCi(int ci);
	void setFono(int fono);
	string toJson();


};

