#ifndef JORNALERO_H
#define JORNALERO_H

#include "Trabajador.h"

class Jornalero : public Trabajador{
private:
	int dias_trabajados;
public:

	Jornalero();

	//Descripcion:Constructor con parametros
	//Pre:Los parametros de tipo entero deben ser mayores o iguales a cero
	//Post:Se crea el objeto Jornalero
	Jornalero(char nuevo_tipo,int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int nueva_dias_trabajados);

	//Pre:El objeto debe estar creado
	//Post:Devuelve la cantidad de dias trabajados
	int obtener_dias_trabajados();

	//Pre:El objeto debe estar creado
	//Post:Devuelve el sueldo liquidado
	void liquidar_sueldo();

	//Descripcion:Desctructor
	//Pre:El objeto debe estar creado
	//Post:Destruye el objeto Jornalero
	~Jornalero();
};

#endif
