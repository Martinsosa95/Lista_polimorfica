#ifndef "JORNALERO_H"
#define "JORNALERO_H"

class Jornalero : public Trabajador{
private:
	int dias_trabajados;
public:

	Jornalero();

	Jornalero(int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int dias_trabajados) : Trabajador(nuevo_legajo, nuevo_nombre, nueva_paga, nueva_alta);

	int obtener_dias_trabajados();

	void liquidar_sueldo();

	~Jornalero();
};

#endif