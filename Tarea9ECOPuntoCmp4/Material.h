#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Material
{
protected:
	string nombre;
	int pts;
public:
	Material(string nombre, int pts);
	~Material();
	string getNombre();
	int getPts();
	string getClave() const;
	virtual string toJson() const = 0;
	virtual int puntos(int cantidad) = 0;
};

