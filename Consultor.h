#ifndef CONSULTOR_H
#define CONSULTOR_H

#include "Trabajador.h"

class Consultor : public Trabajador{
private:
	int *horas_catedra;
	int *horas_descontadas;
public:

	//Descripcion:Constructor
	//Pre:---
	//Post:Se crea el objeto Consultor
	Consultor();

	//Descripcion:Constructor con parametros
	//Pre:Los parametros de tipo entero deben ser mayores o iguales a cero
	//Post:Se crea el objeto Consultor
	Consultor(char nuevo_tipo,int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int nueva_horas_catedra, int nueva_horas_descontadas);

	//Pre:El objeto debe estar creado
	//Post:Devuelve la cantidad de horas catedra trabajadas
	int obtener_horas_catedra();

	//Pre:El objeto debe estar creado
	//Post:Devuelve la cantidad de horas a descontar
	int obtener_horas_descontadas();

	//Pre:El objeto debe estar creado
	//Post:Devuelve el sueldo liquidado
	void liquidar_sueldo();

	//Descripcion:Destructor
	//Pre:El objeto debe estar creado
	//Post:El objeto es destruido
	~Consultor();

};

#endif
