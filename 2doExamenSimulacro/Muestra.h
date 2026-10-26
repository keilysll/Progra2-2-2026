#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Muestra
{
protected:
	int cod;
	string descrip;
public:
	Muestra(int cod,string descrip);
	~Muestra();
	int getCod();
	string getDescrip();
	virtual string toString() = 0;
	static string toStringPtr(Muestra* m);
};

