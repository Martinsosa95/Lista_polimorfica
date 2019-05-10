#ifndef "TRABAJADOR_H"
#define "TRABAJADOR_H"


class Trabajador{
private:
	int legajo;
	string nombre;
	int paga;//Despues vemos, dependiendo del tipo de trabajador lo calculamos distinto NUMERO LEIDO DEL ARCHIVO
	bool alta;
	int sueldo_liquidado;// Despues de usar el metodo
public:

	Trabajador();

	Trabajador(int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta);

	bool obtener_alta();

	int obtener_legajo();

	int obtener_sueldo_liquidado();

	string obtener_nombre();

	int obtener_paga();

	void asignar_alta(bool nueva_alta); //No agregamos los otros asignar porque suponemos que solo se ingresan datos por la lectura del archivo

	virtual void liquidar_sueldo();

	virtual ~Trabajador();

};
#endif