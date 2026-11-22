/*
Una empresa de electrolineras (estaciones de carga para autos electricos) desea un sistema
para controlar el consumo de energia de sus clientes. Se debe considerar:
- Registrar clientes en la red (ordenados por nombre, sin nombres repetidos).
- Registrar bonos de energia (kWh) para cada cliente.
- Registrar cargas de energia y cobrarlas usando los bonos y el saldo principal.
- Obtener reportes de la red.

Tipos de carga (todos los montos y cantidades son enteros):
- CargaEstandar: tarifa 2 Bs por kWh.
- CargaRapida:   tarifa 3 Bs por kWh.

Tipos de bono:
- BonoEstandar:  solo puede usarse en cargas estandar.
- BonoUniversal: puede usarse en cualquier tipo de carga.

Reglas de cobro de una carga:
1. La cantidad de kWh debe ser mayor a 0; caso contrario se lanza la excepcion
   "kwh invalido en la carga <id>".
2. Se recorren los bonos en orden de registro; cada bono aplicable cubre tantos kWh
   como pueda (un bono puede cubrir una carga solo parcialmente y quedar en 0).
3. Los kWh que no cubran los bonos se cobran del saldo principal segun la tarifa de la carga.
   Ese monto es el "costo" de la carga.
4. Si el saldo no alcanza, se lanza la excepcion
   "saldo insuficiente <cliente> no pudo realizar la carga <id>"
   y NO se modifica nada (ni bonos, ni saldo, ni detalle de cargas).
5. Los bonos agotados (0 kWh) permanecen en la lista del cliente.
*/
#include"Red.h"
//#include "Electrolinera.h"
#include<iostream>
using namespace std;
#include"Cliente.h"
int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout<< "{\"nombre\":\"ana\",\"saldo\":44,\"bonos\":[{\"tipo\":\"estandar\",\"kwh\":0},{\"tipo\":\"universal\",\"kwh\":0}],\"cargas\":[{\"id\":1,\"fecha\":20261101,\"tipo\":\"estandar\",\"kwh\":8,\"costo\":0},{\"id\":2,\"fecha\":20261102,\"tipo\":\"estandar\",\"kwh\":10,\"costo\":6}]}" <<endl;
	string error;
	// Crear cliente(nombre, saldo Bs)
	Cliente cliente("ana", 50);
	try {
		// Registrar bonos(kWh)
		cliente.getBonos().registrar(new BonoEstandar(10));
		cliente.getBonos().registrar(new BonoUniversal(5));
		// Realizar cargas(id, fecha, kWh)
		cliente.cargar(new CargaEstandar(1, 20261101, 8));
		cliente.cargar(new CargaEstandar(2, 20261102, 10));
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = cliente.toJson();
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"nombre\":\"ana\",\"saldo\":44,\"bonos\":[{\"tipo\":\"estandar\",\"kwh\":0},{\"tipo\":\"universal\",\"kwh\":0}],\"cargas\":[{\"id\":1,\"fecha\":20261101,\"tipo\":\"estandar\",\"kwh\":8,\"costo\":0},{\"id\":2,\"fecha\":20261102,\"tipo\":\"estandar\",\"kwh\":10,\"costo\":6}]}")
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
	cout<< "{\"nombre\":\"luis\",\"saldo\":75,\"bonos\":[{\"tipo\":\"estandar\",\"kwh\":0},{\"tipo\":\"universal\",\"kwh\":0}],\"cargas\":[{\"id\":1,\"fecha\":20261101,\"tipo\":\"rapida\",\"kwh\":15,\"costo\":15},{\"id\":2,\"fecha\":20261102,\"tipo\":\"estandar\",\"kwh\":25,\"costo\":10}]}"<<endl;
	string error;
	// Crear cliente(nombre, saldo Bs)
	Cliente cliente("luis", 100);
	try {
		// Registrar bonos(kWh)
		cliente.getBonos().registrar(new BonoEstandar(20));
		cliente.getBonos().registrar(new BonoUniversal(10));
		// La carga rapida NO puede usar el bono estandar
		cliente.cargar(new CargaRapida(1, 20261101, 15));
		cliente.cargar(new CargaEstandar(2, 20261102, 25));
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = cliente.toJson();
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"nombre\":\"luis\",\"saldo\":75,\"bonos\":[{\"tipo\":\"estandar\",\"kwh\":0},{\"tipo\":\"universal\",\"kwh\":0}],\"cargas\":[{\"id\":1,\"fecha\":20261101,\"tipo\":\"rapida\",\"kwh\":15,\"costo\":15},{\"id\":2,\"fecha\":20261102,\"tipo\":\"estandar\",\"kwh\":25,\"costo\":10}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}\

int pregunta3()
{
	cout << "----Pregunta 3----" << endl;
	cout<< "{\"nombre\":\"rosa\",\"saldo\":10,\"bonos\":[{\"tipo\":\"estandar\",\"kwh\":0},{\"tipo\":\"universal\",\"kwh\":2}],\"cargas\":[{\"id\":1,\"fecha\":20261101,\"tipo\":\"estandar\",\"kwh\":5,\"costo\":0}]}" <<endl;
	string error1, error2;
	// Crear cliente(nombre, saldo Bs)
	Cliente cliente("rosa", 10);
	try {
		cliente.getBonos().registrar(new BonoEstandar(3));
		cliente.getBonos().registrar(new BonoUniversal(4));
		cliente.cargar(new CargaEstandar(1, 20261101, 5));
		// Saldo insuficiente: no debe modificarse ningun bono ni el saldo
		cliente.cargar(new CargaRapida(2, 20261102, 6));
	}
	catch (exception& e) {
		error1 = e.what();
	}
	try {
		// Cantidad invalida
		cliente.cargar(new CargaEstandar(3, 20261103, 0));
	}
	catch (exception& e) {
		error2 = e.what();
	}
	string result = cliente.toJson();
	cout << result << endl;
	cout << error1 << endl;
	cout << error2 << endl;
	if (error1 == "saldo insuficiente rosa no pudo realizar la carga 2" && error2 == "kwh invalido en la carga 3" && result == "{\"nombre\":\"rosa\",\"saldo\":10,\"bonos\":[{\"tipo\":\"estandar\",\"kwh\":0},{\"tipo\":\"universal\",\"kwh\":2}],\"cargas\":[{\"id\":1,\"fecha\":20261101,\"tipo\":\"estandar\",\"kwh\":5,\"costo\":0}]}")
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
	cout<< "{\"nombre\":\"VoltBo\",\"clientes\":[{\"nombre\":\"ana\",\"saldo\":50,\"bonos\":[{\"tipo\":\"universal\",\"kwh\":0}],\"cargas\":[{\"id\":1,\"fecha\":20261101,\"tipo\":\"rapida\",\"kwh\":5,\"costo\":0}]},{\"nombre\":\"luis\",\"saldo\":12,\"bonos\":[],\"cargas\":[{\"id\":2,\"fecha\":20261101,\"tipo\":\"estandar\",\"kwh\":4,\"costo\":8}]},{\"nombre\":\"pedro\",\"saldo\":0,\"bonos\":[],\"cargas\":[{\"id\":3,\"fecha\":20261101,\"tipo\":\"rapida\",\"kwh\":10,\"costo\":30}]}]}" <<endl;
	string error1, error2;
	// Crear red(nombre)
	Red red("VoltBo");
	try {
		// Registrar clientes(nombre, saldo) usando operator+=
		red += new Cliente("pedro", 30);
		red += new Cliente("ana", 50);
		red += new Cliente("luis", 20);
		red += new Cliente("ana", 10);
	}
	catch (exception& e) {
		error1 = e.what();
	}
	try {
		// Registrar bono(cliente, bono)
		red.registrarBono("ana", new BonoUniversal(5));
		// Registrar carga(cliente, carga)
		red.registrarCarga("ana", new CargaRapida(1, 20261101, 5));
		red.registrarCarga("luis", new CargaEstandar(2, 20261101, 4));
		red.registrarCarga("pedro", new CargaRapida(3, 20261101, 10));
		red.registrarCarga("maria", new CargaEstandar(4, 20261101, 1));
	}
	catch (exception& e) {
		error2 = e.what();
	}
	string result = red.toJson();
	cout << result << endl;
	cout << error1 << endl;
	cout << error2 << endl;
	if (error1 == "el cliente ana ya esta registrado" && error2 == "cliente maria no encontrado" && result == "{\"nombre\":\"VoltBo\",\"clientes\":[{\"nombre\":\"ana\",\"saldo\":50,\"bonos\":[{\"tipo\":\"universal\",\"kwh\":0}],\"cargas\":[{\"id\":1,\"fecha\":20261101,\"tipo\":\"rapida\",\"kwh\":5,\"costo\":0}]},{\"nombre\":\"luis\",\"saldo\":12,\"bonos\":[],\"cargas\":[{\"id\":2,\"fecha\":20261101,\"tipo\":\"estandar\",\"kwh\":4,\"costo\":8}]},{\"nombre\":\"pedro\",\"saldo\":0,\"bonos\":[],\"cargas\":[{\"id\":3,\"fecha\":20261101,\"tipo\":\"rapida\",\"kwh\":10,\"costo\":30}]}]}")
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
	string error;
	Red red("VoltBo");
	int total = -1, rapidas = -1;
	string mayor;
	try {
		red += new Cliente("ana", 100);
		red += new Cliente("luis", 100);
		red.registrarBono("ana", new BonoEstandar(10));
		red.registrarCarga("ana", new CargaEstandar(1, 20261101, 12));//2  22
		red.registrarCarga("ana", new CargaRapida(2, 20261102, 5));//3
		red.registrarCarga("luis", new CargaRapida(3, 20261101, 20));//3  //62
		red.registrarCarga("luis", new CargaEstandar(4, 20261102, 1));//2
		// Total cobrado del saldo principal de todos los clientes
		total = red.totalFacturado();
		// Nombre del cliente con mas kWh cargados (sumando todas sus cargas)
		mayor = red.clienteMayorConsumo();
		// Cantidad de cargas rapidas en toda la red (dynamic_cast)
		rapidas = red.cantidadCargasRapidas();
	}
	catch (exception& e) {
		error = e.what();
	}
	cout << "totalFacturado: " << total << endl;
	cout << "clienteMayorConsumo: " << mayor << endl;
	cout << "cantidadCargasRapidas: " << rapidas << endl;
	cout << error << endl;
	if (error == "" && total == 81 && mayor == "luis" && rapidas == 2)
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}
int main()
{
	int nota = pregunta1() +pregunta2() + pregunta3() + pregunta4() + pregunta5();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}