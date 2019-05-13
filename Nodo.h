#ifndef NODO_H
#define NODO_H
#include "Trabajador.h"
using namespace std;


class Nodo{

private:
	Trabajador* elemento;
	Nodo* psig;
public:

	Nodo(Trabajador* d);

	Nodo(Trabajador* d, Nodo* psig);

	void asignar_elemento(Trabajador* d);

	void asignar_siguiente(Nodo* psig);

	Trabajador* obtener_elemento();

	Nodo* obtener_siguiente();



};
#endif