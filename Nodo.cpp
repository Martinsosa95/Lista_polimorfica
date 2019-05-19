#include "Nodo.h"

Nodo::Nodo(Trabajador* d){
	elemento = d;
	psig=NULL;
}
Nodo::Nodo(Trabajador* d, Nodo* sig){
	elemento = d;
	psig = sig;
}

void Nodo::asignar_elemento(Trabajador* d){
	elemento = d;
}

void Nodo::asignar_siguiente(Nodo* sig){
	psig = sig;
}

Trabajador* Nodo::obtener_elemento(){
	return elemento;
}

Nodo* Nodo::obtener_siguiente(){
	return psig;
}