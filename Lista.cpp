#include "Lista.h"

Lista::Lista(){
	primero = NULL;
	tamanio = 0;
}

int Lista::obtener_tamanio(){
	return tamanio;
}

bool Lista::es_vacia(){
	return !tamanio;
}

Nodo* Lista::obtener_nodo(int pos){
	Nodo* aux = primero;
	for(int i = 1; i<pos ; i++)
		aux = aux->obtener_siguiente();
	return aux;
}

void Lista::agregar(Trabajador* d, int pos){
	Nodo* nuevo = new Nodo(d);
	
	if(es_vacia())
		primero = nuevo;
	else if(pos == 1){
		nuevo->asignar_siguiente(primero);
		primero = nuevo;
	}
	else{
		Nodo* aux = obtener_nodo(pos-1);
		nuevo->asignar_siguiente(aux->obtener_siguiente());
		aux->asignar_siguiente(nuevo);
	}
	tamanio ++;
}

void Lista::eliminar(int pos){
	Nodo* aux;
	if(pos == 1){
		aux = primero;
		primero = aux->obtener_siguiente();
	}
	else{
		Nodo* anterior = obtener_nodo(pos-1);
		aux = anterior->obtener_siguiente();
		anterior->asignar_siguiente(aux->obtener_siguiente());
	}
	tamanio--;
	delete aux;
}

Nodo* Lista::retirar(int pos){
	Nodo* aux;
	if(pos == 1){
		aux = primero;
		primero = aux->obtener_siguiente();
	}
	else{
		Nodo* anterior = obtener_nodo(pos-1);
		aux = anterior->obtener_siguiente();
		anterior->asignar_siguiente(aux->obtener_siguiente());
	}
	tamanio--;
	return aux;
}

void Lista::cambiar_nodo(Nodo* nodo,int pos){
	if(es_vacia())
		primero = nodo;
	else if(pos == 1){
		nodo->asignar_siguiente(primero);
		primero = nodo;
	}
	else{
		Nodo* aux = obtener_nodo(pos-1);
		nodo->asignar_siguiente(aux->obtener_siguiente());
		aux->asignar_siguiente(nodo);
	}
	tamanio ++;
}


Trabajador* Lista::consultar(int pos){
	Nodo* aux = obtener_nodo(pos);
	return aux->obtener_elemento();
}

//Suponiendo que pos1<pos2
void Lista::swap(int pos1, int pos2){
	if((pos1 < obtener_tamanio())&&(pos2 <= obtener_tamanio() )){
	Nodo* aux = retirar(pos1);
	Nodo* aux2 = retirar(pos2-1);
	cambiar_nodo(aux2,pos1);
	cambiar_nodo(aux,pos2);
	}
}

Lista::~Lista(){
	
	while(!es_vacia())
		eliminar(1);
}
