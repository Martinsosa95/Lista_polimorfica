#ifndef "CONSULTOR_H"
#define "CONSULTOR_H"


class Consultor : public Trabajador{
private:
	int horas_catedra;
	int horas_descontadas;
public:

	Consultor();

	Consultor(int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int nueva_horas_catedra, int nueva_horas_descontadas) : Trabajador(nuevo_legajo, nuevo_nombre, nueva_paga, nueva_alta);

	int obtener_horas_catedra();

	int obtener_horas_descontadas();

	void liquidar_sueldo();

};

#endif
