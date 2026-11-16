#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include"Paquete.h"
using namespace std;
class Detalle
{
protected:
	int id;
	int fecha;
public:
	Detalle(int id,int fecha);
	~Detalle();
	int getId();
	int getFecha();
	virtual string toJson() = 0;
	static string toJsonPtr(Detalle* d);
	virtual int getCantidad() = 0;
	virtual int consumir(Paquete* p,int pendiente) = 0;
	virtual int disponible(Paquete* p) = 0;
	virtual string getTipo() = 0;
};

