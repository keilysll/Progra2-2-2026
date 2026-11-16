#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Evento
{
protected:
	int minuto;
	string equipo;
public:
	Evento(int minuto,string equipo);
	~Evento();
	int getMin();
	string getEquipo();
	virtual string toString() = 0;
	static string toStringPtr(Evento* e);
};

