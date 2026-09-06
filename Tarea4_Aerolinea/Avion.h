#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Avion
{
private:
	int codigo;
	int capacidad;
	string modelo;
public:
	Avion(int codigo,int capacidad,string modelo);
	~Avion();
	int getCodigo();
	int getCapacidad();
	string getModelo();
	void setCodigo(int codigo);
	void setCapacidad(int capacidad);
	void setModelo(string modelo);
	string toJson();
};

