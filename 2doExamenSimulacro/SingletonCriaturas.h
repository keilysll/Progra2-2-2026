#pragma once
#include"ListaArray.h"
#include"Criatura.h"
#include"Terrestre.h"
#include"Mistica.h"
class SingletonCriaturas
{
private:
	ListaArray<Criatura> criaturas;
public:
	~SingletonCriaturas();
	static SingletonCriaturas& getInst();
	bool operator<<(Criatura* c);
	Criatura* operator[](int id);
	string toString();
private:
	SingletonCriaturas();
};

