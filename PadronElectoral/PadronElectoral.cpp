

#include <iostream>
#include"TSE.h"
#include"Elector.h"

int main()
{
	TSE tse("Tribunal electoral",10,10,10,10);
	tse.getElector().registrar(new Elector(1313,"Juan",7758));
	tse.getElector().registrar(new Elector(1314, "Julian", 7766));
	tse.getElector().registrar(new Elector(1315, "Karen", 7658));
	tse.getElector().registrar(new Elector(1316, "Tatiana", 7548));
	tse.getElector().registrar(new Elector(1317, "Pedro", 7254));

	tse.getMesa().registrar(new Mesa(1));
	tse.getMesa().registrar(new Mesa(2));

	tse.getRecinto().registrar(new Recinto(1, "San Agustin", "Av.America"));
	tse.getRecinto().registrar(new Recinto(2, "Pedro Poveda", "Av.America"));

	tse.getEleccion().registrar(new Eleccion(1, "Revocatorio", "01/02/2027"));

	tse.agregarElectorAeleccion(1313, 1);
	tse.agregarElectorAeleccion(1314, 1);
	tse.agregarElectorAeleccion(1316, 1);

	tse.agregarRecintoAeleccion(1, 1);
	tse.agregarRecintoAeleccion(2, 1);

	tse.agregarMesaArecintoAsignado(1,1,1,1);
	tse.agregarMesaArecintoAsignado(2, 2, 2, 1);


	tse.agregarElectorAmesa(1313, 1, 1, 1);  
	tse.asignarJuradoMesa(1316, 1, 1, 1);
	tse.asignarJuradoMesa(1314, 2, 1, 1);


	tse.agregarElectorAmesa(1317, 2, 2, 1);  
	tse.asignarJuradoMesa(1315, 2, 2, 1);   
	cout<<tse.toJson()<<endl;


   
}

