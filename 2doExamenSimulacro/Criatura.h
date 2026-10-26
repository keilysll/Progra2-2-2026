#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Criatura
{
protected:
	int codigo;
	string nombre;
	int peligro;
public:
	Criatura(int codigo,string nombre,int peligro);
	~Criatura();
	int getCodigo();
	string getNombre();
	int getPeligro();
	bool operator==(Criatura* c);
	bool operator==(Criatura& c);
	virtual string toString() = 0;
	static string toStringPtr(Criatura* c);
	static bool OrdenarDesPeli(Criatura* c1, Criatura* c2);

};

