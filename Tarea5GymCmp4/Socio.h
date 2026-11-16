#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Socio
{
private:
	int ci;
	string nombre;
public:
	Socio(int ci);
	Socio(int ci,string nombre);
	~Socio();
	int getCi();
	string getNombre();
	string toString();
	static bool ordenarNombreAs(Socio* s1, Socio* s2);
	static string toStringPtr(Socio* s);
	bool operator== (Socio* s);
};

