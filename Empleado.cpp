#include "Empleado.h"

//COMPLETAR CONSTRCUTOR CON PARAMETROS//
Empleado::Empleado(/*parametros*/){
	//codigo//
}

int Empleado::obtener_llegadas_tarde(){
	return llegadas_tarde;
}

int Empleado::obtener_ausencias(){
	return ausencias;
}

void Empleado::liquidar_sueldo(){
	if(llegadas_tarde <= 3 && ausencias == 0){
		sueldo_liquidado = 1.10 * paga;
	}
	else{
		if(llegadas_tarde > 3){
			sueldo_liquidado = paga;
		}
		if(ausencias > 0){
			int paga_diaria = paga / 30;
			sueldo_liquidado = paga - (ausencias * paga_diaria);
		}
	}
}

//COMPLETAR DESTRUCTOR//
Empleado::~Empleado(){

}