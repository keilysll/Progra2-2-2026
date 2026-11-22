#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Entrega
{
protected:
	int id;
	string material;
	int puntos;
public:
	Entrega(int id, string material);
	~Entrega();
	int getId();
	string getMaterial();
	int getPuntos();
	void setPuntos(int puntos);
	string getClave() const;
	virtual string toJson() = 0;
	virtual int getCantidad() = 0;
};

