#include "Jornalero.h"

//completar constructor con parametros
Jornalero::Jornalero(/*parametros*/){
	//codigo
}

int Jornalero::obtener_dias_trabajados(){
	return dias_trabajados;
}

void Jornalero::liquidar_sueldo(){
	sueldo_liquidado = paga * dias_trabajados;
}

//Completar destructor
Jornalero::~Jornalero(){
	//codigo
}