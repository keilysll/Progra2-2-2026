/*
Una red de estaciones de carga para vehiculos electricos (EcoCharge) desea un sistema
para gestionar los vehiculos de sus clientes, los cargadores de cada estacion y las
sesiones de carga que se realizan.

Existen dos tipos de vehiculos:
• Electrico, del cual se registra: placa, propietario y capacidad de bateria en kWh.
• Hibrido enchufable, del cual se registra: placa, propietario, capacidad de bateria en kWh
y capacidad del tanque de combustible en litros.

Existen dos tipos de cargadores:
• Rapido (DC), del cual se registra: codigo y potencia en kW. Cobra 3 Bs por kWh.
• Lento (AC), del cual se registra: codigo y potencia en kW. Cobra 2 Bs por kWh.

Una sesion de carga registra: id, cargador, vehiculo y kWh cargados.
costo de la sesion = kWh * tarifa del cargador.

Reglas para registrar una sesion de carga:
• Si el cargador o el vehiculo no existen, la sesion no se registra.
• Los cargadores rapidos solo admiten vehiculos electricos: un hibrido no puede usarlos.
• No se puede cargar mas kWh que la capacidad de la bateria del vehiculo.

El sistema debe permitir:
• Registrar vehiculos en un registro unico (singleton) usando << y mostrarlos ordenados por placa.
Buscar un vehiculo por placa usando [] y comparar dos vehiculos por placa usando ==.
• Registrar cargadores en una estacion usando += y mostrarlos ordenados por codigo.
Acceder a un cargador por indice usando [].
• Registrar sesiones de carga y mostrarlas ordenadas por costo.
• Calcular lo recaudado por la estacion, la energia entregada por cargadores rapidos
y el vehiculo que mas energia cargo.

Requisitos de diseno:
• Vehiculo y Cargador son clases abstractas (con metodos virtuales puros).
• Todas las colecciones se guardan en una lista generica implementada sobre un array (ListaGen<T>).
• Estacion::cargar y Estacion::energiaRapida deben usar dynamic_cast.
*/

#include "SingletonVehiculos.h"
#include "Estacion.h"
#include<iostream>
using namespace std;
#include<sstream>

int pregunta1()
{
	
	cout << "----Pregunta 1----" << endl;
	cout << "Resultado esperado:" << endl;
	cout << "{\"tipo\":\"hibrido\",\"placa\":\"JKL-345\",\"propietario\":\"Marta Soto\",\"bateriaKwh\":12,\"tanqueLitros\":40}" << endl;
	cout << "1 0" << endl;
	cout << "[{\"tipo\":\"electrico\",\"placa\":\"ABC-101\",\"propietario\":\"Ana Rojas\",\"bateriaKwh\":60},{\"tipo\":\"hibrido\",\"placa\":\"DEF-222\",\"propietario\":\"Pedro Vaca\",\"bateriaKwh\":8,\"tanqueLitros\":35},{\"tipo\":\"hibrido\",\"placa\":\"JKL-345\",\"propietario\":\"Marta Soto\",\"bateriaKwh\":12,\"tanqueLitros\":40},{\"tipo\":\"electrico\",\"placa\":\"XYZ-900\",\"propietario\":\"Luis Paz\",\"bateriaKwh\":75}]" << endl;
	
	// Registramos vehiculos usando operador <<
	// Electrico(placa, propietario, bateriaKwh)
	SingletonVehiculos::getInst() << new Electrico("XYZ-900", "Luis Paz", 75);
	// Hibrido(placa, propietario, bateriaKwh, tanqueLitros)
	SingletonVehiculos::getInst() << new Hibrido("JKL-345", "Marta Soto", 12, 40);
	SingletonVehiculos::getInst() << new Electrico("ABC-101", "Ana Rojas", 60);
	SingletonVehiculos::getInst() << new Hibrido("DEF-222", "Pedro Vaca", 8, 35);
	// Buscamos vehiculos por placa usando operador []
	Vehiculo* v1 = SingletonVehiculos::getInst()["JKL-345"];
	Vehiculo* v2 = SingletonVehiculos::getInst()["ABC-101"];
	// Comparamos vehiculos por placa usando operador ==
	bool iguales = *v1 == *SingletonVehiculos::getInst()["JKL-345"];
	bool distintos = *v1 == *v2;
	string result = SingletonVehiculos::getInst().toString();
	cout << "Resultado esperado:" << endl;
	cout << "{\"tipo\":\"hibrido\",\"placa\":\"JKL-345\",\"propietario\":\"Marta Soto\",\"bateriaKwh\":12,\"tanqueLitros\":40}" << endl;
	cout << "1 0" << endl;
	cout << "[{\"tipo\":\"electrico\",\"placa\":\"ABC-101\",\"propietario\":\"Ana Rojas\",\"bateriaKwh\":60},{\"tipo\":\"hibrido\",\"placa\":\"DEF-222\",\"propietario\":\"Pedro Vaca\",\"bateriaKwh\":8,\"tanqueLitros\":35},{\"tipo\":\"hibrido\",\"placa\":\"JKL-345\",\"propietario\":\"Marta Soto\",\"bateriaKwh\":12,\"tanqueLitros\":40},{\"tipo\":\"electrico\",\"placa\":\"XYZ-900\",\"propietario\":\"Luis Paz\",\"bateriaKwh\":75}]" << endl;
	cout << "Resultado obtenido:" << endl;
	cout << v1->toString() << endl;
	cout << iguales << " " << distintos << endl;
	cout << result << endl;
	if (v1->toString() == "{\"tipo\":\"hibrido\",\"placa\":\"JKL-345\",\"propietario\":\"Marta Soto\",\"bateriaKwh\":12,\"tanqueLitros\":40}" &&
		iguales && !distintos &&
		result == "[{\"tipo\":\"electrico\",\"placa\":\"ABC-101\",\"propietario\":\"Ana Rojas\",\"bateriaKwh\":60},{\"tipo\":\"hibrido\",\"placa\":\"DEF-222\",\"propietario\":\"Pedro Vaca\",\"bateriaKwh\":8,\"tanqueLitros\":35},{\"tipo\":\"hibrido\",\"placa\":\"JKL-345\",\"propietario\":\"Marta Soto\",\"bateriaKwh\":12,\"tanqueLitros\":40},{\"tipo\":\"electrico\",\"placa\":\"XYZ-900\",\"propietario\":\"Luis Paz\",\"bateriaKwh\":75}]")
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
	cout << "{\"tipo\":\"lento\",\"codigo\":\"L1\",\"potenciaKw\":11,\"tarifaKwh\":2}" << endl;
	cout << "{\"nombre\":\"Volta Centro\",\"zona\":\"Cochabamba\",\"cargadores\":[{\"tipo\":\"lento\",\"codigo\":\"L1\",\"potenciaKw\":11,\"tarifaKwh\":2},{\"tipo\":\"lento\",\"codigo\":\"L2\",\"potenciaKw\":22,\"tarifaKwh\":2},{\"tipo\":\"rapido\",\"codigo\":\"R1\",\"potenciaKw\":150,\"tarifaKwh\":3}],\"sesiones\":[]}" << endl;
	// crear estacion(nombre, zona)
	Estacion estacion("Volta Centro", "Cochabamba");
	// Registramos cargadores usando operador +=
	// CargadorLento(codigo, potenciaKw)
	estacion += new CargadorLento("L2", 22);
	// CargadorRapido(codigo, potenciaKw)
	estacion += new CargadorRapido("R1", 150);
	estacion += new CargadorLento("L1", 11);
	// Accedemos a un cargador por indice usando operador []
	string primero = estacion[0]->toString();
	string result = estacion.toString();
	cout << "Resultado esperado:" << endl;
	cout << "{\"tipo\":\"lento\",\"codigo\":\"L1\",\"potenciaKw\":11,\"tarifaKwh\":2}" << endl;
	cout << "{\"nombre\":\"Volta Centro\",\"zona\":\"Cochabamba\",\"cargadores\":[{\"tipo\":\"lento\",\"codigo\":\"L1\",\"potenciaKw\":11,\"tarifaKwh\":2},{\"tipo\":\"lento\",\"codigo\":\"L2\",\"potenciaKw\":22,\"tarifaKwh\":2},{\"tipo\":\"rapido\",\"codigo\":\"R1\",\"potenciaKw\":150,\"tarifaKwh\":3}],\"sesiones\":[]}" << endl;
	cout << "Resultado obtenido:" << endl;
	cout << primero << endl;
	cout << result << endl;
	if (primero == "{\"tipo\":\"lento\",\"codigo\":\"L1\",\"potenciaKw\":11,\"tarifaKwh\":2}" &&
		result == "{\"nombre\":\"Volta Centro\",\"zona\":\"Cochabamba\",\"cargadores\":[{\"tipo\":\"lento\",\"codigo\":\"L1\",\"potenciaKw\":11,\"tarifaKwh\":2},{\"tipo\":\"lento\",\"codigo\":\"L2\",\"potenciaKw\":22,\"tarifaKwh\":2},{\"tipo\":\"rapido\",\"codigo\":\"R1\",\"potenciaKw\":150,\"tarifaKwh\":3}],\"sesiones\":[]}")
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
	Estacion estacion("Volta Centro", "Cochabamba");
	estacion += new CargadorLento("L2", 22);
	estacion += new CargadorRapido("R1", 150);
	estacion += new CargadorLento("L1", 11);
	// Registramos sesiones de carga(id, codigo cargador, placa vehiculo, kWh)
	bool r1 = estacion.cargar(1, "R1", "ABC-101", 40);
	// JKL-345 es hibrido: no puede usar un cargador rapido
	bool r2 = estacion.cargar(2, "R1", "JKL-345", 10);
	bool r3 = estacion.cargar(3, "L1", "JKL-345", 10);
	// XYZ-900 tiene bateria de 75 kWh: no puede cargar 80
	bool r4 = estacion.cargar(4, "L2", "XYZ-900", 80);
	bool r5 = estacion.cargar(5, "L2", "XYZ-900", 50);
	// el cargador R9 no existe
	bool r6 = estacion.cargar(6, "R9", "ABC-101", 5);
	string result = estacion.toString();
	cout << "Resultado esperado:" << endl;
	cout << "1 0 1 0 1 0" << endl;
	cout << "{\"nombre\":\"Volta Centro\",\"zona\":\"Cochabamba\",\"cargadores\":[{\"tipo\":\"lento\",\"codigo\":\"L1\",\"potenciaKw\":11,\"tarifaKwh\":2},{\"tipo\":\"lento\",\"codigo\":\"L2\",\"potenciaKw\":22,\"tarifaKwh\":2},{\"tipo\":\"rapido\",\"codigo\":\"R1\",\"potenciaKw\":150,\"tarifaKwh\":3}],\"sesiones\":[{\"id\":3,\"cargador\":\"L1\",\"placa\":\"JKL-345\",\"kwh\":10,\"costo\":20},{\"id\":5,\"cargador\":\"L2\",\"placa\":\"XYZ-900\",\"kwh\":50,\"costo\":100},{\"id\":1,\"cargador\":\"R1\",\"placa\":\"ABC-101\",\"kwh\":40,\"costo\":120}]}" << endl;
	cout << "Resultado obtenido:" << endl;
	cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << " " << r6 << endl;
	cout << result << endl;
	if (r1 && !r2 && r3 && !r4 && r5 && !r6 &&
		result == "{\"nombre\":\"Volta Centro\",\"zona\":\"Cochabamba\",\"cargadores\":[{\"tipo\":\"lento\",\"codigo\":\"L1\",\"potenciaKw\":11,\"tarifaKwh\":2},{\"tipo\":\"lento\",\"codigo\":\"L2\",\"potenciaKw\":22,\"tarifaKwh\":2},{\"tipo\":\"rapido\",\"codigo\":\"R1\",\"potenciaKw\":150,\"tarifaKwh\":3}],\"sesiones\":[{\"id\":3,\"cargador\":\"L1\",\"placa\":\"JKL-345\",\"kwh\":10,\"costo\":20},{\"id\":5,\"cargador\":\"L2\",\"placa\":\"XYZ-900\",\"kwh\":50,\"costo\":100},{\"id\":1,\"cargador\":\"R1\",\"placa\":\"ABC-101\",\"kwh\":40,\"costo\":120}]}")
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
	Estacion estacion("Volta Norte", "Cochabamba");
	estacion += new CargadorRapido("R1", 150);
	estacion += new CargadorLento("L1", 11);
	estacion += new CargadorLento("L2", 22);

	// R1 = 3 Bs/kWh, L1 y L2 = 2 Bs/kWh
	estacion.cargar(1, "R1", "ABC-101", 30); // 90
	estacion.cargar(2, "L1", "DEF-222", 8);  // 16
	estacion.cargar(3, "R1", "XYZ-900", 60); // 180
	estacion.cargar(4, "L2", "ABC-101", 20); // 40
	estacion.cargar(5, "L1", "JKL-345", 12); // 24
	estacion.cargar(6, "R1", "DEF-222", 5);  // rechazada (hibrido en rapido)
	// recaudacionTotal = 90 + 16 + 180 + 40 + 24 = 350
	// energiaRapida = 30 + 60 = 90 kWh
	// vehiculoQueMasCargo: ABC-101 = 50 kWh, XYZ-900 = 60 kWh -> XYZ-900

	int recaudado = estacion.recaudacionTotal();
	int energia = estacion.energiaRapida();
	string masCargo = estacion.vehiculoQueMasCargo();
	cout << "Resultado esperado recaudacionTotal: 350" << endl;
	cout << "Resultado obtenido recaudacionTotal: " << recaudado << endl;
	cout << "Resultado esperado energiaRapida: 90" << endl;
	cout << "Resultado obtenido energiaRapida: " << energia << endl;
	cout << "Resultado esperado vehiculoQueMasCargo: {\"tipo\":\"electrico\",\"placa\":\"XYZ-900\",\"propietario\":\"Luis Paz\",\"bateriaKwh\":75}" << endl;
	cout << "Resultado obtenido vehiculoQueMasCargo: " << masCargo << endl;
	if (recaudado == 350 && energia == 90 &&
		masCargo == "{\"tipo\":\"electrico\",\"placa\":\"XYZ-900\",\"propietario\":\"Luis Paz\",\"bateriaKwh\":75}")
	{
		cout << "Resultado: correcto" << endl;
		return 25;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}
int main()
{
	int nota = pregunta1() + pregunta2() + pregunta3() +pregunta4();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}