#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Carga
{
protected:
	int id;
	int fecha;
	int kwh;
	int costo;
public:
	Carga(int id,int fecha,int kwh);
	~Carga();
	int getId();
	int getFecha();
	int getKm();
	int getCosto();
	void setCosto(int costo);
	virtual int getTarifa() = 0;
	virtual string toJson() = 0;
	static string toJsonPtr(Carga* c);
};

