/*
* Una biblioteca (CentralLib) desea una aplicación para administrar su
* catálogo de materiales y los préstamos que realiza a sus usuarios.
*
* La aplicación debe permitir:
* - Registrar materiales (libros y revistas) en el catálogo.
* - Registrar préstamos, calculando la multa cuando se exceden los
* días máximos de préstamo de cada material.
* - Consultar el detalle de un libro a partir de su código.
*
* Requisitos de diseño:
DONE Material es una clase base abstracta con un método virtual puro toJson() y un método virtual puro diasPrestamoMax().
DONELibro y Revista heredan de Material y redefinen ambos métodos (Libro: 14 días maximos de prestamo, Revista: 7 dias maximos).
DONE Material sobrecarga el operador == para comparar dos materiales por su código.
DONE Biblioteca sobrecarga el operador += para agregar un material (Biblioteca& operator+=(Material*)).
* - Biblioteca::prestar(codigo, diasUsados) busca el material (si no
* existe, lanza una excepción) y calcula la multa = (diasUsados -
* diasPrestamoMax) * 5, solo si diasUsados supera diasPrestamoMax.
* El total de multas se acumula en la biblioteca.
* - Biblioteca::detalleLibro(codigo) debe usar dynamic_cast para
* verificar que el material encontrado sea un Libro; si no lo es,
* debe lanzar una excepción. Si es un Libro, retorna su numero de
* paginas.
*/
#include<iostream>
using namespace std;

#include "Biblioteca.h"

int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout << "Resultado esperado:" << endl;
	cout << "{\"nombre\":\"CentralLib\",\"materiales\":[{\"codigo\":\"L001\",\"titulo\":\"Cien anios de soledad\",\"autor\":\"Gabriel Garcia Marquez\",\"paginas\":471,\"tipo\":\"libro\"},{\"codigo\":\"R001\",\"titulo\":\"National Geographic\",\"edicion\":305,\"tipo\":\"revista\"}]}" << endl;
	// crear biblioteca(nombre)
	Biblioteca biblio("CentralLib");
	// registrar libro(codigo, titulo, autor, numero de paginas) usando operator+=
	biblio += new Libro("L001", "Cien anios de soledad", "Gabriel Garcia Marquez", 471);
	// registrar revista(codigo, titulo, edicion) usando operator+=
	biblio += new Revista("R001", "National Geographic", 305);

	cout << "Resultado obtenido:" << endl;
	cout << biblio.toJson() << endl;

	if (biblio.toJson() == "{\"nombre\":\"CentralLib\",\"materiales\":[{\"codigo\":\"L001\",\"titulo\":\"Cien anios de soledad\",\"autor\":\"Gabriel Garcia Marquez\",\"paginas\":471,\"tipo\":\"libro\"},{\"codigo\":\"R001\",\"titulo\":\"National Geographic\",\"edicion\":305,\"tipo\":\"revista\"}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta2()
{
	cout << "----Pregunta 2----" << endl;
	cout << "Resultado esperado:" << endl;
	cout << "r1eq=1 r2eq=0" << endl;

	// dos libros con el mismo codigo pero distinto titulo/autor/paginas deben ser == (compara solo codigo)
	Libro l1("L001", "Titulo1", "Autor1", 100);
	Libro l2("L001", "Titulo2", "Autor2", 200);
	// un libro y una revista con codigos distintos no deben ser ==
	Revista r1("R001", "Rev", 1);

	bool r1eq = (l1 == l2);
	bool r2eq = (l1 == r1);

	cout << "Resultado obtenido:" << endl;
	cout << "r1eq=" << r1eq << " r2eq=" << r2eq << endl;

	if (r1eq == true && r2eq == false)
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta3()
{
	cout << "----Pregunta 3----" << endl;
	cout << "Resultado esperado: m1=30 m2=15 m3=0 total=45" << endl;
	// multa = (diasUsados - diasPrestamoMax) * 5, solo si diasUsados > diasPrestamoMax
	// L001 (libro, max=14): prestar 20 dias -> (20-14)*5 = 30
	// R001 (revista, max=7): prestar 10 dias -> (10-7)*5 = 15
	// L001 (libro, max=14): prestar 5 dias -> 0 (no excede)
	// total = 30 + 15 + 0 = 45

	Biblioteca biblio("CentralLib");
	biblio += new Libro("L001", "Libro A", "Autor A", 100);
	biblio += new Revista("R001", "Revista A", 1);

	double m1 = biblio.prestar("L001", 20);
	double m2 = biblio.prestar("R001", 10);
	double m3 = biblio.prestar("L001", 5);

	cout << "Resultado obtenido: m1=" << m1 << " m2=" << m2 << " m3=" << m3 << " total=" << biblio.getTotalMultas() << endl;

	if (m1 == 30 && m2 == 15 && m3 == 0 && biblio.getTotalMultas() == 45)
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta4()
{
	cout << "----Pregunta 4----" << endl;
	cout << "Resultado esperado: error=material no encontrado: X001 total=0" << endl;

	Biblioteca biblio("CentralLib");
	biblio += new Libro("L001", "Libro A", "Autor A", 100);

	string error;
	try {
		// X001 no esta registrado -> debe lanzar excepcion
		biblio.prestar("X001", 5);
	}
	catch (exception& e) {
		error = e.what();
	}

	cout << "Resultado obtenido: error=" << error << " total=" << biblio.getTotalMultas() << endl;

	if (error == "material no encontrado: X001" && biblio.getTotalMultas() == 0)
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta5()
{
	cout << "----Pregunta 5----" << endl;
	cout << "Resultado esperado: paginas=471 error=R001 no es un libro" << endl;

	Biblioteca biblio("CentralLib");
	biblio += new Libro("L001", "Libro A", "Autor A", 471);
	biblio += new Revista("R001", "Revista A", 10);

	// detalleLibro de L001 (es un libro) -> retorna numero de paginas
	int paginas = biblio.detalleLibro("L001");

	string error;
	try {
		// detalleLibro de R001 (es una revista) -> debe lanzar excepcion (dynamic_cast)
		biblio.detalleLibro("R001");
	}
	catch (exception& e) {
		error = e.what();
	}

	cout << "Resultado obtenido: paginas=" << paginas << " error=" << error << endl;

	if (paginas == 471 && error == "R001 no es un libro")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int main()
{
	int nota = pregunta1() + pregunta2() + pregunta3() + pregunta4()+pregunta5();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}