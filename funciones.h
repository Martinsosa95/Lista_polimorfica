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

//Pre:---
//Post:Imprime por pantalla el menu de comandos
void menu();

//Pre:El parametro pasado debe ser valido
//Post:
char leer_tipo_trabajador(ifstream &archivo);

//Pre:
//Post:
void cargar_lista(ifstream &archivo,Lista*);

//Pre:La lista debe estar creada
//Post:La lista esta ordenada por numero de legajo
void ordenar_lista(Lista lista);

//Pre:La lista debe existir y el legajo a buscar debe ser un entero positivo
//Post:Devuelve la posicion del legajo buscado en la Lista o -1 si el legajo buscado no se encuentra en esta
int buscar_legajo(int legajo_a_buscar, Lista* lista);

//Pre:La lista debe existir y pos_legajo debe ser un entero mayor a cero y menor o igual al tamnio de la lista
//Post:El atributo alta del trabajdor es modificado
void cambiar_alta(int pos_legajo,Lista* lista ,bool cond);

//Pre:Modo vale A si busca maximo o B si busca minimo.Ademas la lista debe existir
//Post:Devuelve el sueldo maximo o minimo de la lista
int buscar_sueldo(char modo, Lista* lista);

//Pre:
//Post:
void swap2(int*,int*);

//Pre:
//Post:
void ordenar_lista_2(Lista* lista,Lista*);

#endif // FUNCIONES_H