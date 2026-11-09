#include "HiloIncrementador.h"

HiloIncrementador::HiloIncrementador(int nro):Hilo(nro)
{
}

HiloIncrementador::~HiloIncrementador()
{
}

void HiloIncrementador::procesar()
{
	for (int i = 0; i < 100000; i++)
	{
		ContSingleton::getInst().incrementar();
		cout << "Incrementado: " << (i + 1) << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

