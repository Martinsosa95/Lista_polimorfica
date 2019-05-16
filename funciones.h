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

char leer_tipo_trabajador(ifstream &archivo);

void cargar_lista(ifstream &archivo, char tipo_trabajador, Lista lista);




#endif // FUNCIONES_H