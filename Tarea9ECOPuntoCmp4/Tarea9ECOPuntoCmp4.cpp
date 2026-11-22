/*
Un municipio instala puntos de reciclaje (EcoPunto) donde vecinos y empresas entregan
materiales reciclables y acumulan puntos que luego pueden canjear. Se debe considerar:

- Implementar una clase plantilla Registro<T> (un solo tipo parametrizado) que almacena
punteros T* en orden de llegada y es dueno de sus elementos (los libera al destruirse).
El tipo T debe proveer: string getClave() const y string toJson() const.
* void agregar(T* valor): si ya existe un elemento con la misma clave libera valor y lanza
"clave duplicada: <clave>".
* T* buscar(string clave): si no existe lanza "clave no encontrada: <clave>".
* int size(); T* obtener(int posicion).
* string toJson(): "[" + valor->toJson() de cada elemento separados por "," + "]".
- Un Tarifario unico (Singleton) de materiales, guardados en un Registro por nombre:
* MaterialPeso(nombre, puntos): puntos por cada kilo COMPLETO entregado
(division entera: 2500 gramos = 2 kilos; 800 gramos = 0 puntos).
* MaterialUnidad(nombre, puntos): puntos por unidad entregada.
* int puntos(cantidad): puntos que da el material por esa cantidad.
* Tarifario::getInst(), registrar(material), buscar(nombre), limpiar(), toJson().
- Participantes (clase abstracta Participante), todos inician con 0 puntos:
* Vecino(nombre): recibe los puntos del material. Entre todas sus entregas por peso no
puede superar 20 kg (20000 gramos); las entregas por unidad no cuentan para ese limite.



* Empresa(nombre): recibe el DOBLE de puntos, no tiene limite de peso y no puede
entregar materiales por unidad.
- Entregas (clase abstracta Entrega):
* EntregaPeso(id, material, gramos) y EntregaUnidad(id, material, unidades).
- entregar(entrega) en el participante valida en este orden:
1. cantidad > 0: "cantidad invalida en la entrega <id>"

2. el material existe en el tarifario (excepcion del Registro)
3. el material es del tipo de la entrega (peso con peso, unidad con unidad):
"el material <m> no es compatible con la entrega <id>"
4. reglas del participante:
"<nombre> supero el limite de 20 kg en la entrega <id>"
"una empresa no puede entregar por unidad (entrega <id>)"
Si la entrega es valida se calculan sus puntos, se suman al participante y se agrega a
sus entregas. Si falla no se modifica nada y la entrega se libera.
- canjear(puntos) en el participante: "puntos insuficientes de <nombre> para canjear <p>".
- Un EcoPunto(nombre) con participantes en un Registro por nombre (operator+=), que recibe
entregas y canjes: entregar(nombre, entrega) y canjear(nombre, puntos).
- Reportes: puntosOtorgados() (suma de los puntos de todas las entregas, sin descontar
canjes), gramosReciclados() (suma de gramos de las entregas por peso) y conteo de
participantes por tipo con una funcion miembro plantilla contar<T>().
Los tipos de material, entrega y participante se distinguen con dynamic_cast<> (no con tipo()).
*/
#include "EcoPunto.h"
#include<iostream>
using namespace std;
#include"Tarifario.h"
// Tarifario base usado en varias preguntas
void cargarTarifario()
{
	Tarifario::getInst().limpiar();
	// MaterialPeso(nombre, puntos por kilo completo)
	Tarifario::getInst().registrar(new MaterialPeso("plastico", 10));
	Tarifario::getInst().registrar(new MaterialPeso("papel", 4));
	// MaterialUnidad(nombre, puntos por unidad)
	Tarifario::getInst().registrar(new MaterialUnidad("pilas", 3));
}

int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	string error1, error2;
	// Registro local (no es el del tarifario)
	Registro<Material> r;
	try {
		r.agregar(new MaterialPeso("plastico", 10));
		r.agregar(new MaterialUnidad("pilas", 3));
		r.agregar(new MaterialPeso("papel", 4));
		r.agregar(new MaterialUnidad("papel", 9));
	}
	catch (exception& e) {
		error1 = e.what();
	}
	try {
		r.buscar("vidrio");
	}
	catch (exception& e) {
		error2 = e.what();
	}
	// obtener(2) es papel: 2500 gramos = 2 kilos * 4 = 8
	string result = r.toJson() + " " + r.buscar("pilas")->getNombre() + " " + to_string(r.obtener(2)->puntos(2500)) + " " + to_string(r.size());
	cout << result << endl;
	cout << error1 << endl;
	cout << error2 << endl;
	if (error1 == "clave duplicada: papel" && error2 == "clave no encontrada: vidrio"
		&& result == "[{\"nombre\":\"plastico\",\"tipo\":\"peso\",\"puntos\":10},{\"nombre\":\"pilas\",\"tipo\":\"unidad\",\"puntos\":3},{\"nombre\":\"papel\",\"tipo\":\"peso\",\"puntos\":4}] pilas 8 3")
	{
		cout << "Resultado: correcto" << endl;
		return 25;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}
#include"Vecino.h"
int pregunta2()
{
	cout << "----Pregunta 2----" << endl;
	string error1, error2, error3;
	Vecino v("ana");
	try {
		cargarTarifario();
		Tarifario::getInst().registrar(new MaterialUnidad("plastico", 1));
	}
	catch (exception& e) {
		error1 = e.what();
	}
	try {
		// 2500 g = 2 kilos * 10 = 20 puntos
		v.entregar(new EntregaPeso(1, "plastico", 2500));
		// por unidad: no cuenta para el limite de peso; 4 * 3 = 12 puntos
		v.entregar(new EntregaUnidad(2, "pilas", 4));
		// 2500 + 17500 = 20000 g, justo el limite (las pilas no cuentan); 17 kilos * 4 = 68 puntos
		v.entregar(new EntregaPeso(3, "papel", 17500));
		// 20000 + 600 = 20600 g supera el limite
		v.entregar(new EntregaPeso(4, "plastico", 600));
	}
	catch (exception& e) {
		error2 = e.what();
	}
	try {
		v.canjear(150);
	}
	catch (exception& e) {
		error3 = e.what();
	}
	string result;
	try {
		v.canjear(30);
		result = Tarifario::getInst().toJson() + v.toJson();
	}
	catch (exception& e) {
		result = e.what();
	}
	cout << result << endl;
	cout << error1 << endl;
	cout << error2 << endl;
	cout << error3 << endl;
	if (error1 == "clave duplicada: plastico"
		&& error2 == "ana supero el limite de 20 kg en la entrega 4"
		&& error3 == "puntos insuficientes de ana para canjear 150"
		&& result == "{\"materiales\":[{\"nombre\":\"plastico\",\"tipo\":\"peso\",\"puntos\":10},{\"nombre\":\"papel\",\"tipo\":\"peso\",\"puntos\":4},{\"nombre\":\"pilas\",\"tipo\":\"unidad\",\"puntos\":3}]}"
		"{\"nombre\":\"ana\",\"tipo\":\"vecino\",\"puntos\":70,\"entregas\":[{\"id\":1,\"material\":\"plastico\",\"tipo\":\"peso\",\"cantidad\":2500,\"puntos\":20},{\"id\":2,\"material\":\"pilas\",\"tipo\":\"unidad\",\"cantidad\":4,\"puntos\":12},{\"id\":3,\"material\":\"papel\",\"tipo\":\"peso\",\"cantidad\":17500,\"puntos\":68}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 25;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}
#include"Empresa.h"

int pregunta3()
{
	cout << "----Pregunta 3----" << endl;
	string error1, error2, error3, error4;
	Empresa emp("recicla-sa");
	try {
		cargarTarifario();
		// 3999 g = 3 kilos * 10 = 30, doble para empresa = 60
		emp.entregar(new EntregaPeso(1, "plastico", 3999));
		// sin limite de peso: 25 kilos * 4 = 100, doble = 200
		emp.entregar(new EntregaPeso(2, "papel", 25000));
		// menos de un kilo: 0 puntos
		emp.entregar(new EntregaPeso(7, "papel", 800));
		emp.canjear(60);
		emp.entregar(new EntregaPeso(3, "pilas", 500));
	}
	catch (exception& e) {
		error1 = e.what();
	}
	try {
		emp.entregar(new EntregaUnidad(4, "bateria", 1));
	}
	catch (exception& e) {
		error2 = e.what();
	}
	try {
		emp.entregar(new EntregaUnidad(5, "pilas", 10));
	}
	catch (exception& e) {
		error3 = e.what();
	}
	try {
		emp.entregar(new EntregaPeso(6, "plastico", 0));
	}
	catch (exception& e) {
		error4 = e.what();
	}
	string result = emp.toJson();
	cout << result << endl;
	cout << error1 << endl;
	cout << error2 << endl;
	cout << error3 << endl;
	cout << error4 << endl;
	if (error1 == "el material pilas no es compatible con la entrega 3"
		&& error2 == "clave no encontrada: bateria"
		&& error3 == "una empresa no puede entregar por unidad (entrega 5)"
		&& error4 == "cantidad invalida en la entrega 6"
		&& result == "{\"nombre\":\"recicla-sa\",\"tipo\":\"empresa\",\"puntos\":200,\"entregas\":[{\"id\":1,\"material\":\"plastico\",\"tipo\":\"peso\",\"cantidad\":3999,\"puntos\":60},{\"id\":2,\"material\":\"papel\",\"tipo\":\"peso\",\"cantidad\":25000,\"puntos\":200},{\"id\":7,\"material\":\"papel\",\"tipo\":\"peso\",\"cantidad\":800,\"puntos\":0}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 25;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta4()
{
	cout << "----Pregunta 4----" << endl;
	string error1, error2, error3, error4;
	// Crear EcoPunto(nombre)
	EcoPunto p("EcoPunto Sur");
	int otorgados = -1, gramos = -1, vecinos = -1, empresas = -1, participantes = -1;
	string result;
	try {
		cargarTarifario();
		p += new Vecino("luis");
		p += new Empresa("verde");
		p += new Vecino("rosa");
		p += new Empresa("luis");
	}
	catch (exception& e) {
		error1 = e.what();
	}
	try {
		p.entregar("luis", new EntregaPeso(1, "plastico", 5000));
		p.entregar("luis", new EntregaUnidad(2, "pilas", 3));
		// 10 kilos * 4 = 40, doble = 80
		p.entregar("verde", new EntregaPeso(3, "papel", 10500));
		p.entregar("rosa", new EntregaPeso(4, "plastico", 1200));
		p.entregar("maria", new EntregaPeso(5, "papel", 1000));
	}
	catch (exception& e) {
		error2 = e.what();
	}
	try {
		p.canjear("luis", 100);
	}
	catch (exception& e) {
		error3 = e.what();
	}
	try {
		p.canjear("verde", 30);
		// los canjes no descuentan de los puntos otorgados
		otorgados = p.puntosOtorgados();
		gramos = p.gramosReciclados();
		vecinos = p.contar<Vecino>();
		empresas = p.contar<Empresa>();
		participantes = p.contar<Participantes>();
		result = p.toJson();
	}
	catch (exception& e) {
		error4 = e.what();
	}
	cout << result << endl;
	cout << "puntosOtorgados: " << otorgados << " gramosReciclados: " << gramos << endl;
	cout << "vecinos: " << vecinos << " empresas: " << empresas << " participantes: " << participantes << endl;
	cout << error1 << endl;
	cout << error2 << endl;
	cout << error3 << endl;
	cout << error4 << endl;
	if (error1 == "clave duplicada: luis" && error2 == "clave no encontrada: maria"
		&& error3 == "puntos insuficientes de luis para canjear 100" && error4 == ""
		&& otorgados == 149 && gramos == 16700 && vecinos == 2 && empresas == 1 && participantes == 3
		&& result == "{\"nombre\":\"EcoPunto Sur\",\"participantes\":["
		"{\"nombre\":\"luis\",\"tipo\":\"vecino\",\"puntos\":59,\"entregas\":[{\"id\":1,\"material\":\"plastico\",\"tipo\":\"peso\",\"cantidad\":5000,\"puntos\":50},{\"id\":2,\"material\":\"pilas\",\"tipo\":\"unidad\",\"cantidad\":3,\"puntos\":9}]},"
		"{\"nombre\":\"verde\",\"tipo\":\"empresa\",\"puntos\":50,\"entregas\":[{\"id\":3,\"material\":\"papel\",\"tipo\":\"peso\",\"cantidad\":10500,\"puntos\":80}]},"
		"{\"nombre\":\"rosa\",\"tipo\":\"vecino\",\"puntos\":10,\"entregas\":[{\"id\":4,\"material\":\"plastico\",\"tipo\":\"peso\",\"cantidad\":1200,\"puntos\":10}]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 25;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int main()
{
	int nota = pregunta1() +pregunta2() + pregunta3() + pregunta4();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}