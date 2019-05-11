#include "Consultor.h"

Consultor::Consultor(){

}

Consultor::Consultor(int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int nueva_horas_catedra, int nueva_horas_descontadas) : Trabajador(nuevo_legajo, nuevo_nombre, nueva_paga, nueva_alta){
	horas_catedra = nueva_horas_catedra;
	horas_descontadas = nueva_horas_descontadas;
}

int obtener_horas_catedra(){
	return horas_catedra;
}

int obtener_horas_descontadas(){
	return horas_descontadas;
}

void liquidar_sueldo(){
	
}
}

~Consultor::Consultor();