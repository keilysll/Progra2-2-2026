#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Investigador
{
private:
	int codigo;
	string nombre;
	string especialidad;
public:
	Investigador(int codigo);
	Investigador(int codigo,string nombre,string especialidad);
	~Investigador();
	int getCodigo();
	string getNombre();
	string getEspec();
	string toString();
	static string toStringPtr(Investigador * i);
	bool operator == (Investigador* i);
	static bool OrdenarPorNombre(Investigador* a, Investigador* b);
	Investigador* operator[](int codigo);

};

