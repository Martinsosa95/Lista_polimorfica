#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include "Trabajador.h"
#include "Consultor.h"
#include "Empleado.h"
#include "Jornalero.h"
#include "Lista.h"

void menu();

char leer_tipo_trabajador(ifstream &archivo);

void cargar_lista(ifstream &archivo,Lista*);

void ordenar_lista(Lista lista);

int buscar_legajo(int legajo_a_buscar, Lista* lista);

void dar_de_baja(int pos_legajo, Lista* lista);

void dar_de_alta(int pos_legajo, Lista* lista);
//A si busca maximo, B si busca minimo 
int buscar_sueldo(char modo, Lista* lista);


#endif // FUNCIONES_H