#include "Hilo.h"

Hilo::Hilo(int nro)
{
	this->nro = nro;
	t = NULL;
}

Hilo::~Hilo()
{
	if (t != NULL)
	{
		delete t;
	}
}

void Hilo::iniciar()
{
	t = new thread(ejecutarProcesar, this);
}

void Hilo::ejecutarProcesar(Hilo* h)
{
	h->procesar();
}

void Hilo::join()
{
	if (t != NULL)
	{
		t->join();
	}
}
