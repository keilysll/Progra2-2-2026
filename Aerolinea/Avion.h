#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Avion
{
private:
	int placa;
	int filas;
	int columnas;
public:
	Avion(int placa, int filas, int columnas);
	~Avion();
	int getPlaca();
	int getFilas();
	int getColumnas();
	void setPlaca(int placa);
	void setFilas(int filas);
	void setColumnas(int columnas);
	string toJson();
};
