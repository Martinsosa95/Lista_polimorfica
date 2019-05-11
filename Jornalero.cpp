#include "Jornalero.h"

Jornalero::Jornalero(){
}

Jornalero::Jornalero(int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int nueva_dias_trabajados) : Trabajador(nuevo_legajo, nuevo_nombre, nueva_paga, nueva_alta){
	dias_trabajados = nueva_dias_trabajados;
}

int obtener_dias_trabajados(){
	return dias_trabajados;
}

void liquidar_sueldo(){
	return paga * dias_trabajados;
}

~Jornalero::Jornalero();

