#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Libro
{
protected:
	int codigo;
	string titulo;
	string autor;
public:
	Libro(int codigo,string titulo,string autor);
	~Libro();
	int getCod();
	string getTitulo();
	string getAutor();
	virtual string toString() = 0;
	static string toStringPtr(Libro* l);
	static bool ordenarCodLib(Libro* l1, Libro* l2);
	bool operator==(Libro* l);

};

