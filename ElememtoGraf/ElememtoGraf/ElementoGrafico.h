#pragma once
#include<iostream>
#include"Formato.h"
using namespace std;
class ElementoGrafico // clase abstracta
{
protected:
	int id;
public:
	ElementoGrafico(int id);
	~ElementoGrafico();
	int getInd();
	virtual void dibujar() = 0;// metodo abstracto o virtual puro 
	virtual void borrar() = 0;
};

