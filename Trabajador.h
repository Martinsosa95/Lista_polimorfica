#ifndef TRABAJADOR_H
#define TRABAJADOR_H


class Trabajador{
private:
	int legajo;
	string nombre;
	int paga;//Despues vemos, dependiendo del tipo de trabajador lo calculamos distinto NUMERO LEIDO DEL ARCHIVO
	bool alta;
	int sueldo_liquidado;// Despues de usar el metodo
public:

	Trabajador();

	//Descripcion:Constructor con parametros
	//Pre:Tanto nueva_paga como nuevo_legajo deben ser enteros mayores a cero
	//Post:Crea un objeto trabajador,asignando a sus atributos los parametros pasados
	Trabajador(int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta);

	//Pre:El objeto debe existir
	//Post:Devuelve el valor del tributo alta
	bool obtener_alta();

	//Pre:El objeto debe existir
	//Post:Devuelve el legajo del trabajador
	int obtener_legajo();

	//Pre:El objeto debe existir
	//Post:Devuelve el valor del sueldo liquidado
	int obtener_sueldo_liquidado();

	//Pre:El objeto debe existir
	//Post:Devuelve el nombre del trabajador
	string obtener_nombre();

	//Pre:El objeto debe existir
	//Post:Devuelve la paga del trabajdor,es decir el valor leido del archivo
	int obtener_paga();

	//Pre:El objeto debe existir
	//Post:Se modifica el valor del atributo alta por nueva_alta
	void asignar_alta(bool nueva_alta); //No agregamos los otros asignar porque suponemos que solo se ingresan datos por la lectura del archivo

	//Pre:El objeto debe existir
	//Post:Devuelve el valor del sueldo liquidado del trabajador
	virtual void liquidar_sueldo();

	//Descripcion:Destructor
	//Pre:El objeto debe existir
	//Post:El objeto es destruido
	virtual ~Trabajador();

};
#endif