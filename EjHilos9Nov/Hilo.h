#pragma once
#include<thread>
#include <iostream>
using namespace std;
class Hilo
{
private:
	thread* t;
	int nro;
public:
	Hilo(int nro);
	~Hilo();
	void join();
	void iniciar();

private:
	static void ejecutarProcesar(Hilo* h);

protected:
	virtual void procesar() = 0;
};

