#include "Jornalero.h"

Jornalero::Jornalero(char nuevo_tipo,int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int nueva_dias_trabajados) : Trabajador(nuevo_tipo,nuevo_legajo, nuevo_nombre, nueva_paga, nueva_alta){
	dias_trabajados = nueva_dias_trabajados;
	liquidar_sueldo();
}

int Jornalero::obtener_dias_trabajados(){
	return dias_trabajados;
}

void Jornalero::liquidar_sueldo(){
	asignar_sueldo_liquidado( obtener_paga() * dias_trabajados);
}
/*
//Completar destructor
Jornalero::~Jornalero(){
	//codigo
}*/
