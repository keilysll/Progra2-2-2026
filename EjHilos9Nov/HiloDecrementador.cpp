#include "HiloDecrementador.h"

HiloDecrementador::HiloDecrementador(int nro) :Hilo(nro)
{
}

HiloDecrementador::~HiloDecrementador()
{
}

void HiloDecrementador::procesar()
{
	for (int i = 0; i < 100000; i++)
	{
		ContSingleton::getInst().decrementar();
		cout << "Decrementado: " << (i + 1) << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}
