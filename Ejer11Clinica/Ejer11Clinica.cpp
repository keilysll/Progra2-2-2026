/*
* Una clinica desea una aplicacion para administrar los consultorios, los medicos
* que atienden en ellos y las consultas que realizan.
* La aplicacion debe permitir:
* - Registrar consultorios.
* - Registrar medicos (generales y especialistas).
* - Registrar consultas (presenciales y virtuales).
* - Calcular los ingresos de la clinica.
*/
using namespace std;
#include<iostream>

#include "Clinica.h"
#include"Consultorio.h"

int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout << "Resultado esperado:" << endl;
	cout << "{\"numero\":101,\"medicos\":[{\"nombre\":\"Ana\",\"turno\":\"Manana\",\"consultas\":[]},{\"nombre\":\"Luis\",\"especialidad\":\"Cardiologia\",\"consultas\":[]},{\"nombre\":\"Rosa\",\"especialidad\":\"Pediatria\",\"consultas\":[]}]}" << endl;
	
	// crear consultorio(numero de consultorio)
	Consultorio consultorio(101);
	// registrar medico general(nombre, turno)
	consultorio.registrar(new MedicoGeneral("Ana", "Manana"));
	// registrar medico especialista(nombre, especialidad)
	consultorio.registrar(new MedicoEspecialista("Luis", "Cardiologia"));
	consultorio.registrar(new MedicoEspecialista("Rosa", "Pediatria"));

	cout << "Resultado obtenido:" << endl;
	cout << consultorio.toJson() << endl;

	if (consultorio.toJson() == "{\"numero\":101,\"medicos\":[{\"nombre\":\"Ana\",\"turno\":\"Manana\",\"consultas\":[]},{\"nombre\":\"Luis\",\"especialidad\":\"Cardiologia\",\"consultas\":[]},{\"nombre\":\"Rosa\",\"especialidad\":\"Pediatria\",\"consultas\":[]}]}")
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
	cout << "Resultado esperado:" << endl;
	cout << "{\"numero\":101,\"medicos\":[{\"nombre\":\"Ana\",\"turno\":\"Manana\",\"consultas\":[{\"paciente\":\"Carlos\",\"costo\":150,\"duracion\":30,\"tipo\":\"presencial\"},{\"paciente\":\"Elena\",\"costo\":100,\"plataforma\":\"Zoom\",\"tipo\":\"virtual\"}]},{\"nombre\":\"Luis\",\"especialidad\":\"Cardiologia\",\"consultas\":[{\"paciente\":\"Pedro\",\"costo\":300,\"duracion\":45,\"tipo\":\"presencial\"},{\"paciente\":\"Sofia\",\"costo\":250,\"plataforma\":\"Meet\",\"tipo\":\"virtual\"}]}]}" << endl;
	
	// crear consultorio(numero de consultorio)
	Consultorio consultorio(101);

	// crear medico general(nombre, turno)
	Medico* m1 = new MedicoGeneral("Ana", "Manana");
	// registrar consulta presencial(paciente, costo, duracion en minutos)
	m1->registrar(new ConsultaPresencial("Carlos", 150, 30));
	// registrar consulta virtual(paciente, costo, plataforma)
	m1->registrar(new ConsultaVirtual("Elena", 100, "Zoom"));
	consultorio.registrar(m1);

	// crear medico especialista(nombre, especialidad)
	Medico* m2 = new MedicoEspecialista("Luis", "Cardiologia");
	m2->registrar(new ConsultaPresencial("Pedro", 300, 45));
	m2->registrar(new ConsultaVirtual("Sofia", 250, "Meet"));
	consultorio.registrar(m2);

	cout << "Resultado obtenido:" << endl;
	cout << consultorio.toJson() << endl;

	if (consultorio.toJson() == "{\"numero\":101,\"medicos\":[{\"nombre\":\"Ana\",\"turno\":\"Manana\",\"consultas\":[{\"paciente\":\"Carlos\",\"costo\":150,\"duracion\":30,\"tipo\":\"presencial\"},{\"paciente\":\"Elena\",\"costo\":100,\"plataforma\":\"Zoom\",\"tipo\":\"virtual\"}]},{\"nombre\":\"Luis\",\"especialidad\":\"Cardiologia\",\"consultas\":[{\"paciente\":\"Pedro\",\"costo\":300,\"duracion\":45,\"tipo\":\"presencial\"},{\"paciente\":\"Sofia\",\"costo\":250,\"plataforma\":\"Meet\",\"tipo\":\"virtual\"}]}]}")
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
	cout << "Resultado esperado:" << endl;
	cout << "{\"nombre\":\"Vida\",\"direccion\":\"Av. Arce\",\"consultorios\":[{\"numero\":101,\"medicos\":[{\"nombre\":\"Ana\",\"turno\":\"Manana\",\"consultas\":[{\"paciente\":\"Carlos\",\"costo\":150,\"duracion\":30,\"tipo\":\"presencial\"},{\"paciente\":\"Elena\",\"costo\":100,\"plataforma\":\"Zoom\",\"tipo\":\"virtual\"}]}]},{\"numero\":202,\"medicos\":[{\"nombre\":\"Luis\",\"especialidad\":\"Cardiologia\",\"consultas\":[{\"paciente\":\"Pedro\",\"costo\":300,\"duracion\":45,\"tipo\":\"presencial\"}]},{\"nombre\":\"Rosa\",\"especialidad\":\"Pediatria\",\"consultas\":[{\"paciente\":\"Lucia\",\"costo\":200,\"plataforma\":\"Zoom\",\"tipo\":\"virtual\"},{\"paciente\":\"Diego\",\"costo\":200,\"duracion\":30,\"tipo\":\"presencial\"}]}]}]}" << endl;

	// crear clinica(nombre, direccion)
	Clinica clinica("Vida", "Av. Arce");

	// registrar consultorio(numero de consultorio)
	clinica.registrarConsultorio(101);
	clinica.registrarConsultorio(202);

	// registrar medico en consultorio(numero de consultorio, medico)
	clinica.registrarMedicoEnConsultorio(101, new MedicoGeneral("Ana", "Manana"));
	clinica.registrarMedicoEnConsultorio(202, new MedicoEspecialista("Luis", "Cardiologia"));
	clinica.registrarMedicoEnConsultorio(202, new MedicoEspecialista("Rosa", "Pediatria"));

	// registrar consulta en medico(numero de consultorio, nombre del medico, consulta)
	clinica.registrarConsultaEnMedico(202, "Rosa", new ConsultaVirtual("Lucia", 200, "Zoom"));
	clinica.registrarConsultaEnMedico(101, "Ana", new ConsultaPresencial("Carlos", 150, 30));
	clinica.registrarConsultaEnMedico(202, "Luis", new ConsultaPresencial("Pedro", 300, 45));
	clinica.registrarConsultaEnMedico(101, "Ana", new ConsultaVirtual("Elena", 100, "Zoom"));
	clinica.registrarConsultaEnMedico(202, "Rosa", new ConsultaPresencial("Diego", 200, 30));

	cout << "Resultado obtenido:" << endl;
	cout << clinica.toJson() << endl;

	if (clinica.toJson() == "{\"nombre\":\"Vida\",\"direccion\":\"Av. Arce\",\"consultorios\":[{\"numero\":101,\"medicos\":[{\"nombre\":\"Ana\",\"turno\":\"Manana\",\"consultas\":[{\"paciente\":\"Carlos\",\"costo\":150,\"duracion\":30,\"tipo\":\"presencial\"},{\"paciente\":\"Elena\",\"costo\":100,\"plataforma\":\"Zoom\",\"tipo\":\"virtual\"}]}]},{\"numero\":202,\"medicos\":[{\"nombre\":\"Luis\",\"especialidad\":\"Cardiologia\",\"consultas\":[{\"paciente\":\"Pedro\",\"costo\":300,\"duracion\":45,\"tipo\":\"presencial\"}]},{\"nombre\":\"Rosa\",\"especialidad\":\"Pediatria\",\"consultas\":[{\"paciente\":\"Lucia\",\"costo\":200,\"plataforma\":\"Zoom\",\"tipo\":\"virtual\"},{\"paciente\":\"Diego\",\"costo\":200,\"duracion\":30,\"tipo\":\"presencial\"}]}]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 40;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta4()
{
	cout << "----Pregunta 4----" << endl;

	// ingreso de una consulta presencial = costo
	// ingreso de una consulta virtual = costo con 20% de descuento (costo * 80 / 100)
	// ingresos de un medico = suma de los ingresos de sus consultas
	//
	// Ana : Carlos(150) + Elena(100 -> 80) + Mario(150) = 380
	// Luis : Pedro(300) + Jorge(260) = 560
	// Rosa : Lucia(200 -> 160) + Diego(200) + Ines(180) = 540
	// totalIngresos = 1480, medicoConMasIngresos = Luis

	Clinica clinica("Vida", "Av. Arce");
	clinica.registrarConsultorio(101);
	clinica.registrarConsultorio(202);

	clinica.registrarMedicoEnConsultorio(101, new MedicoGeneral("Ana", "Manana"));
	clinica.registrarMedicoEnConsultorio(202, new MedicoEspecialista("Luis", "Cardiologia"));
	clinica.registrarMedicoEnConsultorio(202, new MedicoEspecialista("Rosa", "Pediatria"));

	clinica.registrarConsultaEnMedico(101, "Ana", new ConsultaPresencial("Carlos", 150, 30));
	clinica.registrarConsultaEnMedico(101, "Ana", new ConsultaVirtual("Elena", 100, "Zoom"));
	clinica.registrarConsultaEnMedico(101, "Ana", new ConsultaPresencial("Mario", 150, 20));
	clinica.registrarConsultaEnMedico(202, "Luis", new ConsultaPresencial("Pedro", 300, 45));
	clinica.registrarConsultaEnMedico(202, "Luis", new ConsultaPresencial("Jorge", 260, 40));
	clinica.registrarConsultaEnMedico(202, "Rosa", new ConsultaVirtual("Lucia", 200, "Zoom"));
	clinica.registrarConsultaEnMedico(202, "Rosa", new ConsultaPresencial("Diego", 200, 30));
	clinica.registrarConsultaEnMedico(202, "Rosa", new ConsultaPresencial("Ines", 180, 25));

	cout << "Resultado esperado totalIngresos: 1480" << endl;
	cout << "Resultado obtenido totalIngresos: " << clinica.totalIngresos() << endl;

	cout << "Resultado esperado medicoConMasIngresos: Luis" << endl;
	cout << "Resultado obtenido medicoConMasIngresos: " << clinica.medicoConMasIngresos() << endl;

	if (clinica.totalIngresos() == 1480 && clinica.medicoConMasIngresos() == "Luis")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int main()
{
	int nota = pregunta1() + pregunta2() + pregunta3()+pregunta4();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/120" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}