#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Socio
{
private:
	int ci;
	string nombre;
	string email;
public:
	Socio(int ci);
	Socio(int ci,string nombre,string email);
	~Socio();
	int getCi();
	string getNombre();
	string getEmail();
	string toString();
	static string toStringPtr(Socio* s);
	bool operator==(Socio* s);
	static bool ordenarNomSoc(Socio* s1, Socio*s2);
};

