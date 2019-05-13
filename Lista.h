#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

class Lista{
private:
	Nodo* primero;
	int tamanio;
public:
	Lista();

	int obtener_tamanio();

	void agregar(Trabajador* d, int pos);

	void eliminar(int pos);

	bool es_vacia();

	//POS: Devuelve el elemento de la lista en esa posicion.
	Trabajador* consultar(int pos);

	Nodo* obtener_nodo(int pos);

	void swap(int pos1, int pos2);

	void ordenar();

	~Lista();


};
#endif