#include "Trabajador.h"

Trabajador::Trabajador(char nuevo_tipo,int nuevo_legajo, string nuevo_nombre, int nueva_paga, bool nueva_alta){
	tipo = new char;
	legajo = new int;
	nombre = new string;
	paga = new int;
	alta = new bool;
	sueldo_liquidado= new int;
	*tipo = nuevo_tipo;
	*legajo = nuevo_legajo;
	*nombre = nuevo_nombre;
	*paga = nueva_paga;
	*alta = nueva_alta;
	*sueldo_liquidado=0;
}

bool Trabajador::obtener_alta(){
	return *alta;
}

char Trabajador::obtener_tipo(){
	return *tipo;
}

int Trabajador::obtener_legajo(){
	return *legajo;
}

int Trabajador::obtener_sueldo_liquidado(){
	return *sueldo_liquidado;
}

string Trabajador::obtener_nombre(){
 	return *nombre;
 }

int Trabajador::obtener_paga(){
	return *paga;
}

void Trabajador::asignar_alta(bool nueva_alta){
	*alta = nueva_alta;
}
void Trabajador::asignar_sueldo_liquidado(int nuevo_sueldo_liquidado){
	*sueldo_liquidado = nuevo_sueldo_liquidado;
}

void Trabajador::a_cadena(){
	string string_tipo;
	
	switch(*tipo){
		case 'C':
			string_tipo = "Consultor";
			break;
		case 'E':
			string_tipo = "Empleado";
			break;
		case 'J':
			string_tipo = "Jornalero";
			break;
	}

	cout<<"Tipo de trabajador: "<< string_tipo<<endl;
	cout<<"Nombre y apellido: "<< *nombre<<endl;
	cout<<"Legajo: "<<*legajo<<endl;
	cout<<"Sueldo a cobrar: "<<*sueldo_liquidado<<endl;

}

Trabajador::~Trabajador(){
	cout<<"Trabajador destruido"<<endl;
	delete tipo;
	delete legajo;
	delete nombre;
	delete paga;
	delete alta;
	delete sueldo_liquidado;
}

