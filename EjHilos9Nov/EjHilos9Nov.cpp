
#include <iostream>
#include<thread>
#include<mutex>
using namespace std;

#include"HiloIncrementador.h"
#include"HiloDecrementador.h"
/*
long cont = 0;
mutex m;

void incrementar(int nroHilo)
{
	for (int i = 0; i < 100000; i++)//
	{
		// region critica
		m.lock(); // bloquear 
		cont++;
		m.unlock(); 
	}
}
*/
/*

void hola(int nroHilo)
{
	for (int i = 0; i < 1000; i++)
	{
		cout <<"Hilo: "<<nroHilo<< " dice hola " << (i+1)<< endl;
	}
	
}
*/

int main()
{
	HiloIncrementador* incr[5];
	HiloDecrementador* dec[5];


	for (int i = 0; i < 5; i++)
	{
		incr[i] = new HiloIncrementador(i + 1);
		dec[i] = new HiloDecrementador(i + 1);

	}

	for (int i = 0; i < 5; i++)
	{
		incr[i]->iniciar();
		dec[i]->iniciar();
	}

	for (int i = 0; i < 5; i++)
	{
		incr[i]->join();
		dec[i]->join();
	}


	
	HiloIncrementador hilo1(1);
	HiloDecrementador hilo2(2);
	hilo1.iniciar();
	hilo2.iniciar();
	hilo1.join();
	hilo2.join();
	cout << "Cont: " << ContSingleton::getInst().getCont() << endl;
	

	/*
	thread* hilos[10];
	for (int i = 0; i < 10; i++)
	{
		hilos[i] = new thread(incrementar, i + 1);
	}
	for (int i = 0; i < 10; i++)
	{
		hilos[i]->join();
	}
	cout<<"cont: "<<cont<< endl;
	*/



	/*
	thread hilo1(hola,1); 
	thread hilo2(hola,2);
	thread hilo3(hola,3);

	hilo1.join(); // espera al hilo
	hilo2.join();
	hilo3.join();
	*/
}


