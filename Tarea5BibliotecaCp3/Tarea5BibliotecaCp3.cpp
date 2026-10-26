/*
Una biblioteca publica desea un sistema para gestionar su catalogo de libros
y los prestamos que realiza a sus socios.

Existen dos tipos de libros:
• Fisico, del cual se registra: codigo, titulo, autor y numero de ejemplares disponibles.
• Digital, del cual se registra: codigo, titulo, autor y tamanio en MB.

Los prestamos pueden ser de dos tipos:
• Prestamo Simple, en el cual se registra: id, libro, socio y fecha de devolucion.
• Prestamo Renovado, que extiende un prestamo simple agregando una nueva fecha de devolucion
y el motivo de la renovacion.

El sistema debe permitir:
• Registrar socios (usando <<) y mostrarlos ordenados por nombre.
• Registrar libros (usando <<) y mostrarlos ordenados por codigo.
• Registrar prestamos y mostrarlos ordenados por fecha de devolucion.
• Calcular el libro con mayor numero de prestamos y el periodo de prestamo mas largo.
*/

#include "SingletonSocios.h"
#include "Biblioteca.h"

// instancia global de la biblioteca
Biblioteca biblioteca;
#include<iostream>
using namespace std;

int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout <<"[{\"ci\":3001,\"nombre\":\"Alvaro Castro\",\"email\":\"alvaro@mail.com\"},{\"ci\":3003,\"nombre\":\"Elena Castro\",\"email\":\"elena@mail.com\"},{\"ci\":3002,\"nombre\":\"Leonardo Castro\",\"email\":\"leonardo@mail.com\"}]" << endl;
	// Registramos socios(ci, nombre, email) usando operador <<
	SingletonSocios::getInst() << new Socio(3001, "Alvaro Castro", "alvaro@mail.com");
	SingletonSocios::getInst() << new Socio(3002, "Leonardo Castro", "leonardo@mail.com");
	SingletonSocios::getInst() << new Socio(3003, "Elena Castro", "elena@mail.com");
	string result = SingletonSocios::getInst().toString();
	cout << result << endl;
	if (result == "[{\"ci\":3001,\"nombre\":\"Alvaro Castro\",\"email\":\"alvaro@mail.com\"},{\"ci\":3003,\"nombre\":\"Elena Castro\",\"email\":\"elena@mail.com\"},{\"ci\":3002,\"nombre\":\"Leonardo Castro\",\"email\":\"leonardo@mail.com\"}]")
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
	cout<< "{\"libros\":[{\"tipo\":\"fisico\",\"codigo\":1,\"titulo\":\"Cien Anios de Soledad\",\"autor\":\"Garcia Marquez\",\"ejemplares\":3},{\"tipo\":\"digital\",\"codigo\":2,\"titulo\":\"El Principito\",\"autor\":\"Saint-Exupery\",\"tamanioMB\":5},{\"tipo\":\"fisico\",\"codigo\":3,\"titulo\":\"Don Quijote\",\"autor\":\"Cervantes\",\"ejemplares\":2},{\"tipo\":\"digital\",\"codigo\":4,\"titulo\":\"1984\",\"autor\":\"Orwell\",\"tamanioMB\":8}],\"prestamos\":[]}"<<endl;
	// Registramos libros usando operador <<
	biblioteca << new LibroFisico(1, "Cien Anios de Soledad", "Garcia Marquez", 3);
	biblioteca << new LibroFisico(3, "Don Quijote", "Cervantes", 2);
	biblioteca << new LibroDigital(2, "El Principito", "Saint-Exupery", 5);
	biblioteca << new LibroDigital(4, "1984", "Orwell", 8);
	// Accedemos a un libro por indice usando operador []
	cout << "Libro en posicion 0: " << biblioteca[0]->toString() << endl;
	string result = biblioteca.toString();
	cout << result << endl;
	if (biblioteca[0]->toString() == "{\"tipo\":\"fisico\",\"codigo\":1,\"titulo\":\"Cien Anios de Soledad\",\"autor\":\"Garcia Marquez\",\"ejemplares\":3}" &&
		result == "{\"libros\":[{\"tipo\":\"fisico\",\"codigo\":1,\"titulo\":\"Cien Anios de Soledad\",\"autor\":\"Garcia Marquez\",\"ejemplares\":3},{\"tipo\":\"digital\",\"codigo\":2,\"titulo\":\"El Principito\",\"autor\":\"Saint-Exupery\",\"tamanioMB\":5},{\"tipo\":\"fisico\",\"codigo\":3,\"titulo\":\"Don Quijote\",\"autor\":\"Cervantes\",\"ejemplares\":2},{\"tipo\":\"digital\",\"codigo\":4,\"titulo\":\"1984\",\"autor\":\"Orwell\",\"tamanioMB\":8}],\"prestamos\":[]}")
	{
		cout << "Resultado: correcto" << endl;
		return 25;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta3()
{
	cout << "----Pregunta 3----" << endl;
	cout<< "{\"libros\":[{\"tipo\":\"fisico\",\"codigo\":1,\"titulo\":\"Cien Anios de Soledad\",\"autor\":\"Garcia Marquez\",\"ejemplares\":3},{\"tipo\":\"digital\",\"codigo\":2,\"titulo\":\"El Principito\",\"autor\":\"Saint-Exupery\",\"tamanioMB\":5},{\"tipo\":\"fisico\",\"codigo\":3,\"titulo\":\"Don Quijote\",\"autor\":\"Cervantes\",\"ejemplares\":2},{\"tipo\":\"digital\",\"codigo\":4,\"titulo\":\"1984\",\"autor\":\"Orwell\",\"tamanioMB\":8}],\"prestamos\":[{\"PrestamoRenovado\":{\"id\":3,\"socio\":{\"ci\":3002,\"nombre\":\"Leonardo Castro\",\"email\":\"leonardo@mail.com\"},\"libro\":{\"tipo\":\"fisico\",\"codigo\":3,\"titulo\":\"Don Quijote\",\"autor\":\"Cervantes\",\"ejemplares\":2},\"fechaInicio\":20240201,\"fechaDevolucion\":20240301},\"nuevaFecha\":20240315,\"motivo\":\"viaje\"},{\"PrestamoSimple\":{\"id\":2,\"socio\":{\"ci\":3003,\"nombre\":\"Elena Castro\",\"email\":\"elena@mail.com\"},\"libro\":{\"tipo\":\"digital\",\"codigo\":2,\"titulo\":\"El Principito\",\"autor\":\"Saint-Exupery\",\"tamanioMB\":5},\"fechaInicio\":20240301,\"fechaDevolucion\":20240305}},{\"PrestamoSimple\":{\"id\":1,\"socio\":{\"ci\":3001,\"nombre\":\"Alvaro Castro\",\"email\":\"alvaro@mail.com\"},\"libro\":{\"tipo\":\"fisico\",\"codigo\":1,\"titulo\":\"Cien Anios de Soledad\",\"autor\":\"Garcia Marquez\",\"ejemplares\":3},\"fechaInicio\":20240301,\"fechaDevolucion\":20240310}}]}" <<endl;
	// Registramos prestamo simple (idPrestamo, codigoLibro, ciSocio, fechaInicio, fechaDevolucion)
	biblioteca.registrarPrestamoSimple(1, 1, 3001, 20240301, 20240310);
	biblioteca.registrarPrestamoSimple(2, 2, 3003, 20240301, 20240305);
	// Registramos prestamo renovado (idPrestamo, codigoLibro, ciSocio, fechaInicio, fechaDevolucion, nuevaFecha, motivo)
	biblioteca.registrarPrestamoRenovado(3, 3, 3002, 20240201, 20240301, 20240315, "viaje");
	string result = biblioteca.toString();
	cout << result << endl;
	if (result == "{\"libros\":[{\"tipo\":\"fisico\",\"codigo\":1,\"titulo\":\"Cien Anios de Soledad\",\"autor\":\"Garcia Marquez\",\"ejemplares\":3},{\"tipo\":\"digital\",\"codigo\":2,\"titulo\":\"El Principito\",\"autor\":\"Saint-Exupery\",\"tamanioMB\":5},{\"tipo\":\"fisico\",\"codigo\":3,\"titulo\":\"Don Quijote\",\"autor\":\"Cervantes\",\"ejemplares\":2},{\"tipo\":\"digital\",\"codigo\":4,\"titulo\":\"1984\",\"autor\":\"Orwell\",\"tamanioMB\":8}],\"prestamos\":[{\"PrestamoRenovado\":{\"id\":3,\"socio\":{\"ci\":3002,\"nombre\":\"Leonardo Castro\",\"email\":\"leonardo@mail.com\"},\"libro\":{\"tipo\":\"fisico\",\"codigo\":3,\"titulo\":\"Don Quijote\",\"autor\":\"Cervantes\",\"ejemplares\":2},\"fechaInicio\":20240201,\"fechaDevolucion\":20240301},\"nuevaFecha\":20240315,\"motivo\":\"viaje\"},{\"PrestamoSimple\":{\"id\":2,\"socio\":{\"ci\":3003,\"nombre\":\"Elena Castro\",\"email\":\"elena@mail.com\"},\"libro\":{\"tipo\":\"digital\",\"codigo\":2,\"titulo\":\"El Principito\",\"autor\":\"Saint-Exupery\",\"tamanioMB\":5},\"fechaInicio\":20240301,\"fechaDevolucion\":20240305}},{\"PrestamoSimple\":{\"id\":1,\"socio\":{\"ci\":3001,\"nombre\":\"Alvaro Castro\",\"email\":\"alvaro@mail.com\"},\"libro\":{\"tipo\":\"fisico\",\"codigo\":1,\"titulo\":\"Cien Anios de Soledad\",\"autor\":\"Garcia Marquez\",\"ejemplares\":3},\"fechaInicio\":20240301,\"fechaDevolucion\":20240310}}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 30;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}
int pregunta4()
{
	cout << "----Pregunta 4----" << endl;
	// Registramos prestamos con fecha de inicio y devolucion
	// registrarPrestamoSimple(id, codigoLibro, ciSocio, fechaInicio, fechaDevolucion)
	biblioteca.registrarPrestamoSimple(4, 1, 3001, 20240101, 20240120); // 19 dias
	biblioteca.registrarPrestamoSimple(5, 1, 3002, 20240201, 20240210); // 9 dias
	biblioteca.registrarPrestamoSimple(6, 2, 3003, 20240301, 20240414); // 43 dias
	biblioteca.registrarPrestamoRenovado(7, 3, 3001, 20240101, 20240115, 20240201, "enfermedad"); // 14 dias

	// Libro con mayor numero de prestamos
	string libroMasPrestado = biblioteca.libroMasPrestado();
	cout << "Libro mas prestado: " << libroMasPrestado << endl;

	// Prestamo con periodo mas largo (fechaDevolucion - fechaInicio en dias)
	int periodoMaximo = biblioteca.periodoMaximo();
	cout << "Periodo maximo (dias): " << periodoMaximo << endl;

	if (libroMasPrestado == "{\"tipo\":\"fisico\",\"codigo\":1,\"titulo\":\"Cien Anios de Soledad\",\"autor\":\"Garcia Marquez\",\"ejemplares\":3}" &&
		periodoMaximo == 43)
	{
		cout << "Resultado: correcto" << endl;
		return 25;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}
int main()
{
	int nota = pregunta1()+pregunta2()+ pregunta3() + pregunta4();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}