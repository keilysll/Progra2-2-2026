#include "ContSingleton.h"

ContSingleton::ContSingleton()
{
	cont = 0;
}

ContSingleton::~ContSingleton()
{
}

ContSingleton& ContSingleton::getInst()
{
	static ContSingleton inst;
	return inst;
}

void ContSingleton::incrementar()
{
	m.lock(); // bloquear
	cont++;
	m.unlock();
}

void ContSingleton::decrementar()
{
	m.lock(); // bloquear
	cont--;
	m.unlock();
}

long ContSingleton::getCont()
{
	return cont;
}
