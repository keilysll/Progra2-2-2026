

#include <iostream>
using namespace std;

//------------------PARTE 1 -------------------------------


//DATOS
class Libro {
public:
	int id;
	string titulo;
	string autor;
	bool disponible;
};
//contine informacion de cada libro de la biblioteca

class Usuario {
public:
	int id;
	string nombre;
	string carnet;
};
// contiene datos de la persona registrada e la biblioteca
class Prestamo {
public:
	int id;
	int idLibro;
	int idUsuario;
	string fechaPrestamo;
	string fechaDevolucion;
};
// registra que usuario tiene un libro y la informacion del prestamo

//APLICACION
registrarLibro(); // permite introducir un nuevo libro al sistema indicando su id,tiutlo y autor 
registrarUsuario();// permite registrar a un usuarioproporionando su id,nombre y carnet
buscarLibro();//Busca un libro utilizando su id o informacion como su titulo, permite comprobar si el libro esta registrado
prestarLibro();//permite prestar un libro aun usuario antes de realizar el prestamo el sitema debe comprobar que el libro existe y esta disponible
devolverLibro();//permite registrar la devolucion del libro y cambiar su estado nuevamente a disponible
mostrarLibroDispo();// permite unicamente mostrar los libros diponibles 

//USUARIO

// ===================================================
//                    BIBLIOTECA
// ===================================================
// 1. Registrar libro
// 2. Registrar usuario
// 3. Buscar libro
// 4. Prestar libro
// 5. Devolver libro
// 6. Mostrar libros disponibles
// 7. Salir
// ====================================================


// RED 

// CLIENTE : Es la computadora o aplicacion desde donde el usuario utiliza el sistema debiblioteca
// SERVIDOR: Es la computadora que recibe las solicitudes, procesa las operaciones y accede a los datos de la biblioteca
// INFO QUE SE PUEDE ENVIAR: Ejemplo cuando un usuario quieres prestarse un libro

// ID del usuario : 8
// ID del libro : 15
// Operacion: PRESTAR

//------------------PARTE 2-----------------------

//REPOSITORY
class LibroRepository
{
private:
	vector<Libro>libros;
public:
	void guardar(Libro libro);
	Libro buscarporId(int id);
	void mostrarTodos();
	void ActualizarLibro(Libro libro);


};

class UsuarioRepository
{
private:
	vector<Usuario>usuarios;
public:
	void guardar(Usuario usuario);
	Usuario buscarporId(int id);
	void mostrarTodos();
	void ActualizarUsuario(Usuario usuario);


};

//SERVICE 

class BibliotecaService
{
private:
	LibroRepository& libroRepository;
	UsuarioRepository& usuariRepository;

public:
	void registrarLibro(Libro libro);// verificar Id no este repetido, comprobar que el titulo no este vacio y comprobar que el autor no este vacio
	void registrarUsuario(Usuario usuario);// verificar Id no este repetido, comprobar que el nombre no este vacio y comprobar que tenga carnet
	void prestarLibro(int idLibro, int idUusario);//comprobar que el libro exista, comprobar que el usuario exista, comprobar que el libro este disponible 
	void devolverLibro(int idLibro);// comprobar que el libro exista, comprobar que actuaalmente este prestado cambiar dispobible a true
};

//CONTROLLER

class BibliotecaController {
private:
	BibliotecaService& service;

public:
	void registrarLibro(Libro libro) {
		service.registrarLibro(libro);
	}

	void registrarUsuario(Usuario usuario) {
		service.registrarUsuario(usuario);
	}

	void prestarLibro(int idLibro, int idUsuario) {
		service.prestarLibro(idLibro, idUsuario);
	}

	void devolverLibro(int idLibro) {
		service.devolverLibro(idLibro);
	}
};

//VIEW 

class BibliotecaView {
public:

	void mostrarMenu() {
		cout << "===== BIBLIOTECA =====" << endl;
		cout << "1. Registrar libro" << endl;
		cout << "2. Registrar usuario" << endl;
		cout << "3. Buscar libro" << endl;
		cout << "4. Prestar libro" << endl;
		cout << "5. Devolver libro" << endl;
		cout << "6. Mostrar libros disponibles" << endl;
		cout << "7. Salir" << endl;
	}

	void mostrarMensaje(string mensaje) {
		cout << mensaje << endl;
	}
};


int main()
{
   


}
