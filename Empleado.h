#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Trabajador.h"

class Empleado : public Trabajador{
private:
	int *llegadas_tarde;
	int *ausencias;
public:

	Empleado();

	//Descripcion:Constructor con parametros
	//Pre:Los parametros de tipo entero deben ser mayores o iguales a cero
	//Post:Se crea un objeto Empleado
	Empleado(char nuevo_tipo,int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int nueva_llegadas_tarde, int nueva_ausencias);

	//Pre:El objeto debe estar creado
	//Post:Devuelve la cantidad de llegadas tarde que tiene el Empleado
	int obtener_llegadas_tarde();

	//Pre:El objeto debe estar creado
	//Post:devuelve la cantidad de ausencias quetiene el Empleado
	int obtener_ausencias();

	//Pre:El objeto debe estar creado
	//Post:Devuelve el sueldo liquidado del Empleado
	void liquidar_sueldo();

	//Descripcion:Destrcutor
	//Pre:El objeto debe estar creado
	//Post:El objeto es destruido
	~Empleado();

};

#endif
