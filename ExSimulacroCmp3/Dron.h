#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Dron
{
protected:
	string tipo;
	int id;
	string modelo;
	int autoMin;

public:
	Dron(int id,string modelo,int autoMin);
	~Dron();
	int getId();
	string getModelo();
	int getAutomin();
	virtual string toString() = 0;
	bool operator ==(Dron& d);
	bool operator ==(Dron* d);
	static string toStringPtr(Dron * d);
	static bool CmpDesc(Dron* d1, Dron* d2);
	static bool CmpAscID(Dron* d1, Dron* d2);
	virtual string getTipo() = 0;


};

