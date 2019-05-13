#include "Consultor.h"

//completar constructor//
Consultor::Consultor(){

}

int Consultor::obtener_horas_catedra(){
	return horas_catedra;
}

int Consultor::obtener_horas_descontadas(){
	return horas_descontadas;
}

void Consultor::liquidar_sueldo(){
	
	sueldo_liquidado = paga * horas_catedra;
	
	if(horas_descontadas > 0){
		int descuento_total,descuento_p_hora;
		descuento_p_hora = sueldo_liquidado/(4 * horas_catedra);
		descuento_total = descuento_p_hora * horas_descontadas;
		sueldo_liquidado -= descuento_total;
	}
}

//completar destructor
Consultor::~Consultor(){

}