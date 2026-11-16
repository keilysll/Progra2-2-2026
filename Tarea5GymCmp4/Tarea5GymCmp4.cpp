/*
Un gimnasio desea un sistema informático para control y seguimiento de las disciplinas deportivas que ofrece a sus socios. Una misma disciplina puede tener varios grupos en diferentes horarios. Los socios pueden escoger las disciplinas e inscribirse a uno o más grupos.
Existen dos tipos de grupos:
• Libre, tiene un cupo límite de 20 socios.
• Controlado, tiene un cupo límite de 20 socios a los cuales se les controla la asistencia.
Implementar un programa en C++, que permita realizar las siguientes operaciones:
• Registrar socios.
• Registrar disciplinas.
• Registrar grupos en una disciplina.
• Inscribir socios a los grupos.
• Registrar asistencia en los grupos controlados.
*/
#include "SingletonSocios.h"
#include "Disciplina.h"
#include "Controlado.h"
#include"Grupo.h"
#include<iostream>
using namespace std;
int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout<< "{\"socios\":[{\"ci\":3,\"nombre\":\"Elena Castro\"},{\"ci\":1,\"nombre\":\"Leonardo Castro\"},{\"ci\":2,\"nombre\":\"Paola Perez\"}]}" <<endl;
	string error;
	try {
		SingletonSocios::getInst().getSocios()->registrar(new Socio(2, "Paola Perez"));
		SingletonSocios::getInst().getSocios()->registrar(new Socio(3, "Elena Castro"));
		SingletonSocios::getInst().getSocios()->registrar(new Socio(1, "Leonardo Castro"));
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = SingletonSocios::getInst().toString();
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"socios\":[{\"ci\":3,\"nombre\":\"Elena Castro\"},{\"ci\":1,\"nombre\":\"Leonardo Castro\"},{\"ci\":2,\"nombre\":\"Paola Perez\"}]}")
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
	cout<< "{\"nombre\":\"cardio\",\"grupos\":[{\"id\":\"A\",\"inscritos\":[{\"ci\":1,\"nombre\":\"Leonardo Castro\"},{\"ci\":2,\"nombre\":\"Paola Perez\"}]},{\"id\":\"B\",\"inscritos\":[{\"ci\":1,\"nombre\":\"Leonardo Castro\"},{\"ci\":2,\"nombre\":\"Paola Perez\"},{\"ci\":3,\"nombre\":\"Elena Castro\"}]}]}" <<endl;
	string error;
	Disciplina d1("cardio");
	try {
		Grupo* g1 = new Grupo("A");
		d1.getGrupos()->registrar(g1);
		g1->inscribir(1);
		g1->inscribir(2);
		Controlado* g2 = new Controlado("B");
		d1.getGrupos()->registrar(g2);
		g2->inscribir(1);
		g2->inscribir(2);
		g2->inscribir(3);
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = d1.toString();
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"nombre\":\"cardio\",\"grupos\":[{\"id\":\"A\",\"inscritos\":[{\"ci\":1,\"nombre\":\"Leonardo Castro\"},{\"ci\":2,\"nombre\":\"Paola Perez\"}]},{\"id\":\"B\",\"inscritos\":[{\"ci\":1,\"nombre\":\"Leonardo Castro\"},{\"ci\":2,\"nombre\":\"Paola Perez\"},{\"ci\":3,\"nombre\":\"Elena Castro\"}]}]}")
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
	cout<< "{\"nombre\":\"cardio\",\"grupos\":[{\"id\":\"B\",\"inscritos\":[{\"ci\":1,\"nombre\":\"Leonardo Castro\"},{\"ci\":2,\"nombre\":\"Paola Perez\"},{\"ci\":3,\"nombre\":\"Elena Castro\"}],\"sesiones\":[{\"fecha\":20210202,\"asistentes\":[]},{\"fecha\":20210203,\"asistentes\":[]}]}]}" <<endl;
	string error;
	Disciplina d1("cardio");
	try {
		Controlado* g2 = new Controlado("B");
		d1.getGrupos()->registrar(g2);
		g2->inscribir(1);
		g2->inscribir(2);
		g2->inscribir(3);
		g2->registrarSesion(20210202);
		g2->registrarSesion(20210203);
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = d1.toString();
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"nombre\":\"cardio\",\"grupos\":[{\"id\":\"B\",\"inscritos\":[{\"ci\":1,\"nombre\":\"Leonardo Castro\"},{\"ci\":2,\"nombre\":\"Paola Perez\"},{\"ci\":3,\"nombre\":\"Elena Castro\"}],\"sesiones\":[{\"fecha\":20210202,\"asistentes\":[]},{\"fecha\":20210203,\"asistentes\":[]}]}]}")
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
	cout<< "{\"nombre\":\"cardio\",\"grupos\":[{\"id\":\"B\",\"inscritos\":[{\"ci\":1,\"nombre\":\"Leonardo Castro\"},{\"ci\":2,\"nombre\":\"Paola Perez\"},{\"ci\":3,\"nombre\":\"Elena Castro\"}],\"sesiones\":[{\"fecha\":20210202,\"asistentes\":[{\"ci\":2,\"nombre\":\"Paola Perez\"},{\"ci\":3,\"nombre\":\"Elena Castro\"}]}]}]}" <<endl;
	string error;
	Disciplina d1("cardio");
	try {
		Controlado* g2 = new Controlado("B");
		d1.getGrupos()->registrar(g2);
		g2->inscribir(1);
		g2->inscribir(2);
		g2->inscribir(3);
		g2->registrarSesion(20210202);
		g2->registrarAsistente(2, 20210202);
		g2->registrarAsistente(3, 20210202);
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = d1.toString();
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"nombre\":\"cardio\",\"grupos\":[{\"id\":\"B\",\"inscritos\":[{\"ci\":1,\"nombre\":\"Leonardo Castro\"},{\"ci\":2,\"nombre\":\"Paola Perez\"},{\"ci\":3,\"nombre\":\"Elena Castro\"}],\"sesiones\":[{\"fecha\":20210202,\"asistentes\":[{\"ci\":2,\"nombre\":\"Paola Perez\"},{\"ci\":3,\"nombre\":\"Elena Castro\"}]}]}]}")
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
	Disciplina d1("cardio");
	try {
		Controlado* g2 = new Controlado("B");
		d1.getGrupos()->registrar(g2);
		g2->inscribir(3);
		g2->inscribir(2);
		g2->registrarSesion(20210202);
		g2->registrarAsistente(2, 20210202);
		g2->registrarAsistente(1, 20210202);
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = d1.toString();
	cout << result << endl;
	cout << error << endl;

	if (error == "El socio Leonardo Castro no esta inscrito" && result == "{\"nombre\":\"cardio\",\"grupos\":[{\"id\":\"B\",\"inscritos\":[{\"ci\":3,\"nombre\":\"Elena Castro\"},{\"ci\":2,\"nombre\":\"Paola Perez\"}],\"sesiones\":[{\"fecha\":20210202,\"asistentes\":[{\"ci\":2,\"nombre\":\"Paola Perez\"}]}]}]}")
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