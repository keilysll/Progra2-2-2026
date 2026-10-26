#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Vehiculo
{
protected:
	string placa;
	string propetario;
	int capBat;
public:
	Vehiculo(string placa, string propetario, int capBat);
	~Vehiculo();
	string getPlaca();
	string getPropetario();
	int getCapBat();
	bool operator == (Vehiculo& v);
	bool operator== (Vehiculo* v);
	static string toStringPtr(Vehiculo* v);
	static bool CmpAs(Vehiculo* v1, Vehiculo* v2);
	virtual string toString() = 0;
};

