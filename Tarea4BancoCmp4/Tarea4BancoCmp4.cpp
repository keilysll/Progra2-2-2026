#include<iostream>
using namespace std;
//CUOTA FIJA ES DE 10
// CUOTA VARIABLE SEGUN LO QUE SE PONGA

#include "Banco.h"
//Crear banco(nombre, direccion)
Banco banco("bisa", "calle x");
#include"Cliente.h"
int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout<< "{\"nombre\":\"juan\",\"fono\":7070000,\"creditos\":[{\"tipo\":\"CreditoCuotaFija\",\"deuda cuota fija\":80},{\"tipo\":\"CreditoCuotaVariable\",\"deuda cuota variable\":190}],\"pagos\":[{\"id\":1,\"fecha\":20220101,\"monto\":5,\"tipo\":\"amortizacion\"},{\"id\":2,\"fecha\":20220101,\"monto\":5,\"tipo\":\"amortizacion\"},{\"id\":1,\"fecha\":20220101,\"tipo\":\"cuota\"},{\"id\":2,\"fecha\":20220101,\"tipo\":\"cuota\"}]}" <<endl;
	string error;
	// Crear cliente(nombre, fono)
	Cliente cliente("juan", 7070000);
	try {
		// Registrar creditos
		cliente.getCreditos().registrar(new CreditoCuotaFija(100));
		cliente.getCreditos().registrar(new CreditoCuotaVariable(200));
		// Realizar pago(id, fecha, monto)
		cliente.pagar(new Amortizacion(1, 20220101, 5));
		cliente.pagar(new Amortizacion(2, 20220101, 5));
		// Enviar pago(id, fecha)
		cliente.pagar(new CuotaFija(1, 20220101));
		cliente.pagar(new CuotaFija(2, 20220101));
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = cliente.toJson();
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"nombre\":\"juan\",\"fono\":7070000,\"creditos\":[{\"tipo\":\"CreditoCuotaFija\",\"deuda cuota fija\":80},{\"tipo\":\"CreditoCuotaVariable\",\"deuda cuota variable\":190}],\"pagos\":[{\"id\":1,\"fecha\":20220101,\"monto\":5,\"tipo\":\"amortizacion\"},{\"id\":2,\"fecha\":20220101,\"monto\":5,\"tipo\":\"amortizacion\"},{\"id\":1,\"fecha\":20220101,\"tipo\":\"cuota\"},{\"id\":2,\"fecha\":20220101,\"tipo\":\"cuota\"}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 30;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta2()
{
	cout << "----Pregunta 2----" << endl;
	string error;
	// Crear cliente(nombre, fono)
	Cliente cliente("pedro", 10);
	try {
		// Registrar creditos
		cliente.getCreditos().registrar(new CreditoCuotaVariable(20));
		// Realizar pago(id, fecha, monto)
		cliente.pagar(new Amortizacion(1, 20220101, 10));
		cliente.pagar(new Amortizacion(2, 20220101, 10));
		cliente.pagar(new Amortizacion(3, 20220101, 5));
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = cliente.toJson();
	cout << result << endl;
	cout << error << endl;
	if (error == "El monto que desea pagar pedro es mayor a la deuda" && result == "{\"nombre\":\"pedro\",\"fono\":10,\"creditos\":[{\"tipo\":\"CreditoCuotaVariable\",\"deuda cuota variable\":0}],\"pagos\":[{\"id\":1,\"fecha\":20220101,\"monto\":10,\"tipo\":\"amortizacion\"},{\"id\":2,\"fecha\":20220101,\"monto\":10,\"tipo\":\"amortizacion\"}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 30;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta3()
{
	cout << "----Pregunta 3----" << endl;
	string error;
	try {
		// Registrar cliente
		banco.registrarCliente("juan", 70700001);
		banco.registrarCliente("jose", 70700002);
		// Registrar creditos
		banco.registrarCredito("juan", new CreditoCuotaFija(1000));
		banco.registrarCredito("juan", new CreditoCuotaVariable(2000));
		banco.registrarCredito("jose", new CreditoCuotaFija(3000));
		banco.registrarCredito("jose", new CreditoCuotaVariable(4000));
		// Registrar amortizaciones(cliente, id, fecha, monto)
		banco.registrarPago("juan", 1, 20220101, 5);
		banco.registrarPago("jose", 2, 20220101, 5);
		// Realizar cuotas(cliente, id, fecha)
		banco.registrarPago("juan", 3, 20220101);
		banco.registrarPago("juan", 4, 20220101);
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = banco.toJson();
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"nombre\":\"bisa\",\"dirreccion\":\"calle x\",\"clientes\":[{\"nombre\":\"juan\",\"fono\":70700001,\"creditos\":[{\"tipo\":\"CreditoCuotaFija\",\"deuda cuota fija\":980},{\"tipo\":\"CreditoCuotaVariable\",\"deuda cuota variable\":1995}],\"pagos\":[{\"id\":1,\"fecha\":20220101,\"monto\":5,\"tipo\":\"amortizacion\"},{\"id\":3,\"fecha\":20220101,\"tipo\":\"cuota\"},{\"id\":4,\"fecha\":20220101,\"tipo\":\"cuota\"}]},{\"nombre\":\"jose\",\"fono\":70700002,\"creditos\":[{\"tipo\":\"CreditoCuotaFija\",\"deuda cuota fija\":3000},{\"tipo\":\"CreditoCuotaVariable\",\"deuda cuota variable\":3995}],\"pagos\":[{\"id\":2,\"fecha\":20220101,\"monto\":5,\"tipo\":\"amortizacion\"}]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 40;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}
int main()
{
	int nota = pregunta1()+pregunta2() + pregunta3();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}