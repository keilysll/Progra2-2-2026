#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Pago
{
protected:
	int id;
	int fecha;
public:
	Pago(int id,int fecha);
	~Pago();
	int getId();
	int getFecha();
	virtual string toJson() = 0;
	static string toJsonPtr(Pago* p);
	virtual string getTipo() = 0;
};

