#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include"Carga.h"
#include"CargaEstandar.h"
using namespace std;
class Bono
{
protected:
	int kwh;
public:
	Bono(int kwh);
	~Bono();
	int getKwh();
	void usar(int Kw);
	virtual bool aplicable(Carga* c) = 0;
	virtual string toJson() = 0;
	static string toJsonPtr(Bono* b);

};

