#include "Empleado.h"

Empleado::Empleado(){
}

Empleado::Empleado(int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int nueva_llegadas_tarde, int nueva_ausencias) : Trabajador(nuevo_legajo, nuevo_nombre, nueva_paga, nueva_alta){
	llegadas_tarde = nueva_llegadas_tarde;
	ausencias = nueva_ausencias;
}

int obtener_llegadas_tarde(){
	return llegadas_tarde;
}

int obtener_ausencias(){
	return ausencias;
}

void liquidar_sueldo(){
	if(llegadas_tarde < 3 && !ausencias)
		sueldo_liquidado = paga + (paga*0.1);
	else if (llegadas_tarde > 3 && !ausencias)
		sueldo_liquidado = paga;
	else
		sueldo_liquidado = paga - ((1/30)*paga*ausencias);
}


~Empleado(){
}


#endif