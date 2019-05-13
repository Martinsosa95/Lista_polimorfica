#include "Trabajador.h"

Trabajador::Trabajador(int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta){
	legajo = nuevo_legajo;
	nombre = nuevo_nombre;
	paga = nueva_paga;
	alta = nueva_alta;
}

bool Trabajador::obtener_alta(){
	return alta;
}

int Trabajador::obtener_legajo(){
	return legajo;
}

int Trabajador::obtener_sueldo_liquidado(){
	return sueldo_liquidado;
}

string Trabajador::obtener_nombre(){
 	return nombre;
 }

int Trabajador::obtener_paga(){
	return paga;
}

void Trabajador::asignar_alta(bool nueva_alta){
	alta = nueva_alta;
}