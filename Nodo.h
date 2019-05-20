#ifndef NODO_H
#define NODO_H
#include "Trabajador.h"

using namespace std;


class Nodo{

private:
	Trabajador* elemento;
	Nodo* psig;
public:
	//Descripcion:Constructor conu un parametro
	//Pre:---
	//Post:El objeto es creado con los el valor d para elemento y le asigna a psig el valor por defecto
	Nodo(Trabajador* d);
	
	//Descripcion:Constructor con parametros
	//Pre:---
	//Post:Crea un objeto Nodo
	Nodo(Trabajador* d, Nodo* psig);
	
	//Pre:El objeto debe existir
	//Post:Se modifico el valor de elemento
	void asignar_elemento(Trabajador* d);
	
	//Pre:El objeto debe existir
	//Post:Se modifico el valor de psig
	void asignar_siguiente(Nodo* psig);
	
	//Pre:El objeto debe existir
	//Post:Devuelve el valor de elemento
	Trabajador* obtener_elemento();
	
	//Pre:El objeto debe existir
	//Post:Devuelve el valor de siguiente
	Nodo* obtener_siguiente();
	
	//Descripcion:Destructor
	//Pre:El objeto debe existir
	//Post:El objeto es destruido
	~Nodo();

};
#endif