#ifndef "EMPLEADO_H"
#define "EMPLEADO_H"


class Empleado : public Trabajador{
private:
	int llegadas_tarde;
	int ausencias;
public:

	Empleado();

	Empleado(int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta, int llegadas_tarde, int ausencias) : Trabajador(nuevo_legajo, nuevo_nombre, nueva_paga, nueva_alta);

	int obtener_llegadas_tarde();

	int obtener_ausencias();

	void liquidar_sueldo();

	~Empleado();

};

#endif