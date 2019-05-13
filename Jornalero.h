#ifndef JORNALERO_H
#define JORNALERO_H

class Jornalero : public Trabajador{
private:
	int dias_trabajados;
public:

	Jornalero();

	//Descripcion:Constructor con parametros
	//Pre:Los parametros de tipo entero deben ser mayores o iguales a cero
	//Post:Se crea el objeto Jornalero
	Jornalero(int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int nueva_dias_trabajados) : Trabajador(nuevo_legajo, nuevo_nombre, nueva_paga, nueva_alta);

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
