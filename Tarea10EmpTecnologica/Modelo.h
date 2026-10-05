#pragma once
using namespace std;
#include<iostream>
#include<sstream>
#include<string>
class Modelo
{
protected:
	string nombre;
public:
	Modelo(string nombre);
	~Modelo();
	string getNombre();
	virtual string toJson() = 0;

};

