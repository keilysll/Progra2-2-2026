#include "Biblioteca.h"

Biblioteca::Biblioteca() :libros(10), prestamos(10)
{
}

Biblioteca::~Biblioteca()
{
}

bool Biblioteca::operator<<(Libro* l)
{
	if (!l)
	{
		return false;
	}
	libros.registrar(l);
	return true;
	
}

Libro* Biblioteca::operator[](int i)
{
	return libros.operator[](i);
}



void Biblioteca::registrarPrestamoSimple(int id, int codLib, int ciSocio, int fechIni, int fechDev)
{
	Libro* l = libros.buscar(new LibroFisico(codLib));
	Socio* s = SingletonSocios::getInst().buscar(ciSocio);
	prestamos.registrar(new PrestamoSimple(id,l,s,fechIni,fechDev));
	
}

void Biblioteca::registrarPrestamoRenovado(int id, int codLib, int ciSocio, int fechIni, int fechDev, int nuevaFec, string motivo)
{
	Libro* l = libros.buscar(new LibroFisico(codLib));
	Socio* s = SingletonSocios::getInst().buscar(ciSocio);
	prestamos.registrar(new PrestamoRenovado(id, l, s, fechIni, fechDev,nuevaFec,motivo));
}

string Biblioteca::libroMasPrestado()
{
	Libro* mejor = NULL;
	int masPrestado = 0;
	for (int i = 0; i < prestamos.getInd(); i++)
	{
		Libro* candidato = prestamos[i]->getLibro();
		int cantidad = 0;
		for (int j = 0; j < prestamos.getInd(); j++)
		{
			if (prestamos[j]->getLibro()->getCod() == candidato->getCod())
			{
				cantidad++;
			}
		}
		if (cantidad > masPrestado)
		{
			masPrestado = cantidad;
			mejor = candidato;
		}
	}
	if (mejor == NULL) return "";
	return mejor->toString();
}


int dias(int fecha)
{
	int anio = fecha / 10000;
	int mes = (fecha / 100) % 100;
	int dia = fecha % 100;
	return anio * 360 + mes * 30 + dia;
}

int Biblioteca::periodoMaximo()
{
	int max = 0;
	for (int i = 0; i < prestamos.getInd(); i++)
	{
		int p = dias(prestamos[i]->getfechaDev()) - dias(prestamos[i]->getfechaIni());
		if (p > max)
		{
			max = p;

		}
	}
	return max;
}


string Biblioteca::toString()
{
	libros.ordenar(Libro::ordenarCodLib);
	prestamos.ordenar(Prestamo::OrdenarFechDevPres);
	
	stringstream ss;
	ss << "{\"libros\":" << libros.toString(Libro::toStringPtr) << ",\"prestamos\":" << prestamos.toString(Prestamo::toStringPtr) << "}";
	return ss.str();
}