/*
Una plataforma de e-sports desea un sistema para gestionar sus torneos.

Existen dos tipos de jugadores:
• Amateur, del cual se registra: id, nickname, pais y nivel.
• Pro, del cual se registra: id, nickname, pais, ranking y salario.

Los equipos se componen de jugadores Pro y tienen: nombre y region.

Las partidas pueden ser de dos tipos:
• Individual, en la cual se registra: id, jugador ganador, jugador perdedor
y duracion en minutos.
• Equipo, en la cual se registra: id, equipo ganador, equipo perdedor
y duracion en minutos.

El sistema debe permitir:
• Registrar jugadores (usando +=) y mostrarlos ordenados por nickname.
• Crear equipos, agregar jugadores Pro (usando +=) y acceder por indice (usando []).
• Registrar torneos y agregar partidas (usando <<), mostrarlos con partidas
ordenadas por duracion.
• Calcular el jugador con mas victorias individuales y la partida de mayor duracion.
*/
 //USAR CASTING


#include "SingletonJugadores.h"
#include "Equipo.h"
#include "Torneo.h"

#include<iostream>
using namespace std;


int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout << "{\"tipo\":\"pro\",\"id\":6,\"nickname\":\"Storm\",\"pais\":\"Chile\",\"ranking\":3,\"salario\":4000}" << endl;

	
	// Registramos jugadores usando operador +=
	// Amateur(id, nickname, pais, nivel)
	SingletonJugadores::getInst() += new Amateur(1, "xDragon", "Bolivia", "avanzado");
	SingletonJugadores::getInst() += new Amateur(2, "StarKid", "Peru", "intermedio");
	// Pro(id, nickname, pais, ranking, salario)
	SingletonJugadores::getInst() += new Pro(3, "Ace", "Chile", 5, 3000);
	SingletonJugadores::getInst() += new Pro(4, "Nova", "Bolivia", 12, 2000);
	SingletonJugadores::getInst() += new Pro(5, "Blaze", "Peru", 8, 2500);
	SingletonJugadores::getInst() += new Pro(6, "Storm", "Chile", 3, 4000);
	// Buscamos un jugador por id y verificamos sus datos
	Jugador* j = SingletonJugadores::getInst().buscar(6);

	cout << "Buscado id=6: " << j->toString() << endl;
	if (j->toString() == "{\"tipo\":\"pro\",\"id\":6,\"nickname\":\"Storm\",\"pais\":\"Chile\",\"ranking\":3,\"salario\":4000}")
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
	// Creamos equipos(nombre, region)
	Equipo e1("TeamAlpha", "Sudamerica");
	Equipo e2("TeamBeta", "Sudamerica");
	// Agregamos jugadores Pro al equipo usando operador += (por id)
	e1 += 3; // Ace
	e1 += 5; // Blaze
	e2 += 4; // Nova
	e2 += 6; // Storm
	// Accedemos al primer jugador del equipo usando operador []
	cout << "Primer jugador TeamAlpha: " << e1[0]->toString() << endl;
	cout << e1.toString() << endl;
	cout << e2.toString() << endl;
	if (e1[0]->toString() == "{\"tipo\":\"pro\",\"id\":3,\"nickname\":\"Ace\",\"pais\":\"Chile\",\"ranking\":5,\"salario\":3000}" &&
		e1.toString() == "{\"nombre\":\"TeamAlpha\",\"region\":\"Sudamerica\",\"jugadores\":[{\"tipo\":\"pro\",\"id\":3,\"nickname\":\"Ace\",\"pais\":\"Chile\",\"ranking\":5,\"salario\":3000},{\"tipo\":\"pro\",\"id\":5,\"nickname\":\"Blaze\",\"pais\":\"Peru\",\"ranking\":8,\"salario\":2500}]}" &&
		e2.toString() == "{\"nombre\":\"TeamBeta\",\"region\":\"Sudamerica\",\"jugadores\":[{\"tipo\":\"pro\",\"id\":4,\"nickname\":\"Nova\",\"pais\":\"Bolivia\",\"ranking\":12,\"salario\":2000},{\"tipo\":\"pro\",\"id\":6,\"nickname\":\"Storm\",\"pais\":\"Chile\",\"ranking\":3,\"salario\":4000}]}")
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
	cout<<"{\"id\":1,\"nombre\":\"Copa Andina\",\"partidas\":[{\"PartidaEquipo\":{\"id\":4,\"ganador\":{\"nombre\":\"TeamBeta\",\"region\":\"Sudamerica\",\"jugadores\":[{\"tipo\":\"pro\",\"id\":4,\"nickname\":\"Nova\",\"pais\":\"Bolivia\",\"ranking\":12,\"salario\":2000},{\"tipo\":\"pro\",\"id\":6,\"nickname\":\"Storm\",\"pais\":\"Chile\",\"ranking\":3,\"salario\":4000}]},\"perdedor\":{\"nombre\":\"TeamAlpha\",\"region\":\"Sudamerica\",\"jugadores\":[{\"tipo\":\"pro\",\"id\":3,\"nickname\":\"Ace\",\"pais\":\"Chile\",\"ranking\":5,\"salario\":3000},{\"tipo\":\"pro\",\"id\":5,\"nickname\":\"Blaze\",\"pais\":\"Peru\",\"ranking\":8,\"salario\":2500}]},\"duracion\":25}},{\"PartidaIndividual\":{\"id\":2,\"ganador\":{\"tipo\":\"pro\",\"id\":3,\"nickname\":\"Ace\",\"pais\":\"Chile\",\"ranking\":5,\"salario\":3000},\"perdedor\":{\"tipo\":\"pro\",\"id\":4,\"nickname\":\"Nova\",\"pais\":\"Bolivia\",\"ranking\":12,\"salario\":2000},\"duracion\":30}},{\"PartidaIndividual\":{\"id\":1,\"ganador\":{\"tipo\":\"amateur\",\"id\":1,\"nickname\":\"xDragon\",\"pais\":\"Bolivia\",\"nivel\":\"avanzado\"},\"perdedor\":{\"tipo\":\"amateur\",\"id\":2,\"nickname\":\"StarKid\",\"pais\":\"Peru\",\"nivel\":\"intermedio\"},\"duracion\":45}},{\"PartidaEquipo\":{\"id\":3,\"ganador\":{\"nombre\":\"TeamAlpha\",\"region\":\"Sudamerica\",\"jugadores\":[{\"tipo\":\"pro\",\"id\":3,\"nickname\":\"Ace\",\"pais\":\"Chile\",\"ranking\":5,\"salario\":3000},{\"tipo\":\"pro\",\"id\":5,\"nickname\":\"Blaze\",\"pais\":\"Peru\",\"ranking\":8,\"salario\":2500}]},\"perdedor\":{\"nombre\":\"TeamBeta\",\"region\":\"Sudamerica\",\"jugadores\":[{\"tipo\":\"pro\",\"id\":4,\"nickname\":\"Nova\",\"pais\":\"Bolivia\",\"ranking\":12,\"salario\":2000},{\"tipo\":\"pro\",\"id\":6,\"nickname\":\"Storm\",\"pais\":\"Chile\",\"ranking\":3,\"salario\":4000}]},\"duracion\":60}}]}"<< endl;
	// Recreamos equipos para este test
	Equipo* alpha = new Equipo("TeamAlpha", "Sudamerica");
	Equipo* beta = new Equipo("TeamBeta", "Sudamerica");
	*alpha += 3;
	*alpha += 5;
	*beta += 4;
	*beta += 6;
	// Creamos torneo y agregamos partidas usando <<
	Torneo t1(1, "Copa Andina");
	// PartidaIndividual(id, idGanador, idPerdedor, duracion)
	t1 << new PartidaIndividual(1, 1, 2, 45);
	t1 << new PartidaIndividual(2, 3, 4, 30);
	// PartidaEquipo(id, equipoGanador, equipoPerdedor, duracion)
	t1 << new PartidaEquipo(3, alpha, beta, 60);
	t1 << new PartidaEquipo(4, beta, alpha, 25);
	string result = t1.toString();
	cout << result << endl;
	if (result == "{\"id\":1,\"nombre\":\"Copa Andina\",\"partidas\":[{\"PartidaEquipo\":{\"id\":4,\"ganador\":{\"nombre\":\"TeamBeta\",\"region\":\"Sudamerica\",\"jugadores\":[{\"tipo\":\"pro\",\"id\":4,\"nickname\":\"Nova\",\"pais\":\"Bolivia\",\"ranking\":12,\"salario\":2000},{\"tipo\":\"pro\",\"id\":6,\"nickname\":\"Storm\",\"pais\":\"Chile\",\"ranking\":3,\"salario\":4000}]},\"perdedor\":{\"nombre\":\"TeamAlpha\",\"region\":\"Sudamerica\",\"jugadores\":[{\"tipo\":\"pro\",\"id\":3,\"nickname\":\"Ace\",\"pais\":\"Chile\",\"ranking\":5,\"salario\":3000},{\"tipo\":\"pro\",\"id\":5,\"nickname\":\"Blaze\",\"pais\":\"Peru\",\"ranking\":8,\"salario\":2500}]},\"duracion\":25}},{\"PartidaIndividual\":{\"id\":2,\"ganador\":{\"tipo\":\"pro\",\"id\":3,\"nickname\":\"Ace\",\"pais\":\"Chile\",\"ranking\":5,\"salario\":3000},\"perdedor\":{\"tipo\":\"pro\",\"id\":4,\"nickname\":\"Nova\",\"pais\":\"Bolivia\",\"ranking\":12,\"salario\":2000},\"duracion\":30}},{\"PartidaIndividual\":{\"id\":1,\"ganador\":{\"tipo\":\"amateur\",\"id\":1,\"nickname\":\"xDragon\",\"pais\":\"Bolivia\",\"nivel\":\"avanzado\"},\"perdedor\":{\"tipo\":\"amateur\",\"id\":2,\"nickname\":\"StarKid\",\"pais\":\"Peru\",\"nivel\":\"intermedio\"},\"duracion\":45}},{\"PartidaEquipo\":{\"id\":3,\"ganador\":{\"nombre\":\"TeamAlpha\",\"region\":\"Sudamerica\",\"jugadores\":[{\"tipo\":\"pro\",\"id\":3,\"nickname\":\"Ace\",\"pais\":\"Chile\",\"ranking\":5,\"salario\":3000},{\"tipo\":\"pro\",\"id\":5,\"nickname\":\"Blaze\",\"pais\":\"Peru\",\"ranking\":8,\"salario\":2500}]},\"perdedor\":{\"nombre\":\"TeamBeta\",\"region\":\"Sudamerica\",\"jugadores\":[{\"tipo\":\"pro\",\"id\":4,\"nickname\":\"Nova\",\"pais\":\"Bolivia\",\"ranking\":12,\"salario\":2000},{\"tipo\":\"pro\",\"id\":6,\"nickname\":\"Storm\",\"pais\":\"Chile\",\"ranking\":3,\"salario\":4000}]},\"duracion\":60}}]}")
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
	Torneo t1(1, "Copa Andina");
	t1 << new PartidaIndividual(1, 1, 2, 45);
	t1 << new PartidaIndividual(2, 3, 4, 30);
	t1 << new PartidaIndividual(3, 1, 3, 55);
	t1 << new PartidaIndividual(4, 4, 2, 20);
	t1 << new PartidaIndividual(5, 1, 4, 70);
	// Jugador con mas victorias individuales en el torneo
	string masVictorias = t1.jugadorMasVictorias();
	cout << "Jugador con mas victorias: " << masVictorias << endl;
	// Duracion de la partida mas larga
	int maxDuracion = t1.duracionMaxima();
	cout << "Duracion maxima (min): " << maxDuracion << endl;
	if (masVictorias == "{\"tipo\":\"amateur\",\"id\":1,\"nickname\":\"xDragon\",\"pais\":\"Bolivia\",\"nivel\":\"avanzado\"}" &&
		maxDuracion == 70)
	{
		cout << "Resultado: correcto" << endl;
		return 25;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}
int main()
{
	int nota = pregunta1()+ pregunta2()+ pregunta3()+ pregunta4();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}