#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Empleado
{
private:
	string nombre;
	int ci;
	string areaEsp;
	int aniosExp;
public:
	Empleado(string nombre,int ci, string areaEsp,int aniosExp);
	~Empleado();
	string getNombre();
	int getCi();
	string getArea();
	int getAniosExp();
	void setNombre(string nombre);
	void setCi(int ci);
	void ordenar();
	string toJson();


};

