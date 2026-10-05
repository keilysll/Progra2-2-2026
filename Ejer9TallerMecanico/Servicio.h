#pragma once
using namespace std;
#include<iostream>
#include<string>
#include<sstream>
class Servicio
{
protected:
	int codigo;
	string descrip;
	int costo;
public:
	Servicio(int codigo,string descrip,int costo);
	~Servicio();
	int getCodigo();
	string getDescrip();
	int getCosto();
	virtual string toJson() = 0;
};

