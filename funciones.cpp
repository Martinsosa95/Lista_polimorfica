#include "funciones.h"


char leer_tipo_trabajador(ifstream &archivo){
    string tipo_trabajador;
    if(!archivo.eof()){
        archivo >> tipo_trabajador;
    }

    return tipo_trabajador[0];    

}


void cargar_lista(ifstream &archivo, Lista lista){

    int pos_lista = 1;
    
    string legajo;
    string nombre;
    string paga;
    char tipo_trabajador = leer_tipo_trabajador(archivo);
    while (!archivo.eof()){
        cout<<pos_lista<<endl;
        switch (tipo_trabajador){

            case'E':
        {
            string llegadas_tarde;
            string ausencias;

            archivo >> legajo >> nombre >> paga >> llegadas_tarde >> ausencias;
            Empleado nuevo_empleado(tipo_trabajador,atoi(legajo.c_str()), nombre, atoi(paga.c_str()),true,atoi(llegadas_tarde.c_str()),atoi(ausencias.c_str()));
            Trabajador *nuevo_trabajador = &nuevo_empleado;
            lista.agregar(nuevo_trabajador, pos_lista);
            break;
        }
            case'J':
        {

            string cant_dias;
        
            archivo >> legajo >> nombre >> paga >> cant_dias;
            Jornalero nuevo_jornalero(tipo_trabajador,atoi(legajo.c_str()), nombre, atoi(paga.c_str()),true,atoi(cant_dias.c_str()));
            Trabajador *nuevo_trabajador = &nuevo_jornalero;
            lista.agregar(nuevo_trabajador, pos_lista);
            break;
        }
            case'C':
        {
            string horas_catedras;
            string horas_a_descontar;

            archivo >> legajo >> nombre >> paga >> horas_catedras >> horas_a_descontar;
            Consultor nuevo_consultor(tipo_trabajador,atoi(legajo.c_str()),nombre, atoi(paga.c_str()),true,atoi(horas_catedras.c_str()),atoi(horas_a_descontar.c_str()));
            Trabajador *nuevo_trabajador = &nuevo_consultor;
            lista.agregar(nuevo_trabajador, pos_lista);
            break;
        }

        }

    pos_lista++;
    tipo_trabajador = leer_tipo_trabajador(archivo);
    }
}

int buscar_legajo(int legajo_a_buscar, Lista lista){
    bool esta = false;
    int pos_legajo;

    for(int i = 1; i<=lista.obtener_tamanio() ; i++){
        if (lista.obtener_nodo(i)->obtener_elemento()->obtener_legajo()== legajo_a_buscar){
            esta = true;
            pos_legajo = i;
        }
    }

    if(esta){
        lista.obtener_nodo(pos_legajo)->obtener_elemento()->a_cadena();
    }

    return pos_legajo;


}

void ordenar_lista(Lista lista){
    int n = lista.obtener_tamanio();
    for (int i = 1; i <= n-1; i++)        
        for (int j = 1; j <= n-i-1; j++)  
            if (lista.obtener_nodo(j)->obtener_elemento()->obtener_legajo()> lista.obtener_nodo(j+1)->obtener_elemento()->obtener_legajo()) 
                lista.swap(j, j+1); 
}
int buscar_sueldo(char modo, Lista lista){
    int pos_legajo;
    int sueldo;
    int sueldo_lista;
    if(modo=='A')
        sueldo=0;
    else
        sueldo=100000;

    for(int i = 1;i<lista.obtener_tamanio();i++){
        sueldo_lista=lista.obtener_nodo(i)->obtener_elemento()->obtener_sueldo_liquidado();
        if ((sueldo_lista< sueldo)&&(modo == 'B')){
            sueldo=sueldo_lista;
            pos_legajo = i;
        }
        if((sueldo_lista > sueldo)&&(modo == 'A')){
            sueldo=sueldo_lista;
            pos_legajo = i;
        }
    }
    if(modo=='A')
        cout<<"El sueldo máximo es de "<<sueldo<<endl;
    else
        cout<<"El sueldo minimo es de "<<sueldo<<endl;
    

    return pos_legajo;



}