#include "Empleado.h"

Empleado::Empleado(char nuevo_tipo,int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int nueva_llegadas_tarde, int nueva_ausencias) : Trabajador(nuevo_tipo,nuevo_legajo, nuevo_nombre, nueva_paga, nueva_alta){
	llegadas_tarde= new int;
	ausencias = new int;
	*llegadas_tarde = nueva_llegadas_tarde;
	*ausencias = nueva_ausencias;
	liquidar_sueldo();
}

int Empleado::obtener_llegadas_tarde(){
	return *llegadas_tarde;
}

int Empleado::obtener_ausencias(){
	return *ausencias;
}

void Empleado::liquidar_sueldo(){
	if((*llegadas_tarde) <= 3 && (*ausencias) == 0){
		asignar_sueldo_liquidado(int(1.10 * obtener_paga()));
	}
	else{
		if((*llegadas_tarde) > 3){
			asignar_sueldo_liquidado(obtener_paga());
		}
		if((*ausencias) > 0){
			int paga_diaria = obtener_paga() / 30;
			asignar_sueldo_liquidado(obtener_paga() - ((*ausencias) * paga_diaria));
		}
	}
}
/*
//COMPLETAR DESTRUCTOR//*/
Empleado::~Empleado(){
	cout<<"Empleado destruido"<<endl;
	delete llegadas_tarde;
	delete ausencias;
}
