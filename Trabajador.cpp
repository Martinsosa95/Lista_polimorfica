#include "Trabajador.h"

//Trabajador();
Trabajador::Trabajador(int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta){
	legajo = nuevo_legajo;
	nombre = nuevo_nombre;
	paga = nueva_paga;
	alta = nueva_alta;
	sueldo_liquidado = liquidar_sueldo();
}

	bool obtener_alta(){
		return alta;
	}

	int obtener_legajo(){
		return legajo;
	}

	int obtener_sueldo_liquidado(){
		return sueldo_liquidado;
	}

	string obtener_nombre(){
		return nombre;
	}

	int obtener_paga(){
		return paga;
	}

	void asignar_alta(bool nueva_alta){
		alta = nueva_alta; //No agregamos los otros asignar porque suponemos que solo se ingresan datos por la lectura del archivo
	} 

	virtual void liquidar_sueldo();

virtual ~Trabajador();