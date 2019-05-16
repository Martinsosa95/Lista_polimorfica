#include "Consultor.h"

Consultor::Consultor(char nuevo_tipo,int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int nueva_horas_catedra, int nueva_horas_descontadas) : Trabajador(nuevo_tipo,nuevo_legajo, nuevo_nombre, nueva_paga, nueva_alta){
	horas_catedra = nueva_horas_catedra;
	horas_descontadas = nueva_horas_descontadas;
	liquidar_sueldo();
}

int Consultor::obtener_horas_catedra(){
	return horas_catedra;
}

int Consultor::obtener_horas_descontadas(){
	return horas_descontadas;
}

void Consultor::liquidar_sueldo(){
	
	asignar_sueldo_liquidado(obtener_paga() * horas_catedra);
	
	if(horas_descontadas > 0){
		int descuento_total,descuento_p_hora;
		descuento_p_hora = obtener_sueldo_liquidado()/(4 * horas_catedra);
		descuento_total = descuento_p_hora * horas_descontadas;
		asignar_sueldo_liquidado(obtener_sueldo_liquidado() - descuento_total);
	}
}

//completar destructor
Consultor::~Consultor(){

}