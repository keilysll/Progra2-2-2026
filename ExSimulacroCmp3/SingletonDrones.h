#pragma once
#include"Dron.h"
#include"Delivery.h"
#include"Vigilancia.h"
#include"ModGenerico.h"
class SingletonDrones
{
private:
	ModGenerico<Dron> drones;

public:
	~SingletonDrones();
	static SingletonDrones& getInst();
	bool operator <<(Dron* d);
	string toString();
	Dron* operator[] (int id);
private:
	SingletonDrones();
};

