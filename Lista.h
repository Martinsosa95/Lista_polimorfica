#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista{
private:
	Nodo* primero;
	int tamanio;

	//Pre:Debe existir un nodo en la posicion pasada por parametro
	//Post:Cambia el nodo pasado por parametro por el nodo de la posicion pasada por parametro
	void cambiar_nodo(Nodo* nodo,int pos);
	//Pre:Debe existir el nodo en esa posicion
	//Post:Se va a retirar el nodo de esa posicion
	Nodo* retirar(int pos);
public:
	//Descripcion:Constructor
	//Pre:---
	//Post:Se crea el objeto Lista
	Lista();
	
	//Pre:El objeto debe existir
	//Post:Devuelve el valor de tamanio
	int obtener_tamanio();
	
	//Pre:El objeto debe existir,pos debe ser mayor a cero y menor o igual a tamanio
	//Post:Se agrego el objeto d a la lista en la posicion pos
	void agregar(Trabajador* d, int pos);
	
	//Pre:El objeto debe existir,pos debe ser mayor a cero y menor o igual a tamanio
	//Post:Se eleimino de la lista el objeto en la posicion pos
	void eliminar(int pos);
	
	//Pre:El objeto debe existir
	//Post:Devuelve true si la lista esta vacia y false en caso contrario
	bool es_vacia();
	
	//Pre:El objeto debe existir,pos debe ser mayor a cero y menor o igual a tamanio
	//Post:Devuelve el elemento de la lista en esa posicion.
	Trabajador* consultar(int pos);
	
	//Pre:El objeto debe existir,pos debe ser mayor a cero y menor o igual a tamanio
	//Post:devuelve el nodo enn la posicion pos de la lista
	Nodo* obtener_nodo(int pos);
	
	//Pre:El objeto debe existir,pos1 y pos 2 deben ser mayores a cero y menores o iguales a tamanio
	//Post:intercambio los nodos en  pos1 y pos 2
	void swap(int pos1, int pos2);
	
	//Pre:El objeto debe existir
	//Post:La lista se encuentra ordenada por numero de legajo de los trabajadores
	void ordenar();
	
	//Descripcion:Destructor
	//Pre:El objeto debe existir
	//Post:EL objeto es destruido
	~Lista();


};
#endif