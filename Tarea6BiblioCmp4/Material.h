#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Material
{
protected:
	string codigo;
	string titulo;
public:
	Material(string codigo,string titulo);
	~Material();
	string getCod();
	string getTitulo();
	virtual string toJson() = 0;
	static string toJsonPtr(Material* m);
	bool operator ==(Material* m);
	bool operator ==(Material& m);
	virtual int diasPrestamoMax() = 0;
};

