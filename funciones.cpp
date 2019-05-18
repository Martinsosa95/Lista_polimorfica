#include "funciones.h"


char leer_tipo_trabajador(ifstream &archivo){
    string tipo_trabajador;
    if(!archivo.eof()){

        archivo >> tipo_trabajador;
    }
    return tipo_trabajador[0];    

}


void cargar_lista(ifstream &archivo, Lista lista){

    int pos_lista = 0;
    
    string legajo;
    string nombre;
    string paga;
    char tipo_trabajador = leer_tipo_trabajador(archivo);
    while (!archivo.eof()){
        switch (tipo_trabajador){

            case'E':
        {

            string llegadas_tarde;
            string ausencias;

            archivo >> legajo >> nombre >> paga >> llegadas_tarde >> ausencias;
            Empleado nuevo_empleado(tipo_trabajador,atoi(legajo.c_str()), nombre, atoi(paga.c_str()),true,atoi(llegadas_tarde.c_str()),atoi(ausencias.c_str()));
            Trabajador *nuevo_trabajador = &nuevo_empleado;
            Lista.agregar(nuevo_trabajador, pos_lista);
            break;
        }
            case'J':
        {

            string cant_dias;
        
            archivo >> legajo >> nombre >> paga >> cant_dias;
            Jornalero nuevo_jornalero(tipo_trabajador,atoi(legajo.c_str()), nombre, atoi(paga.c_str()),true,atoi(cant_dias.c_str()));
            Trabajador *nuevo_trabajador = &nuevo_jornalero;
            Lista.agregar(nuevo_trabajador, pos_lista);
            break;
        }
            case'C':
        {
            string horas_catedras;
            string horas_a_descontar;

            archivo >> legajo >> nombre >> paga >> horas_catedras >> horas_a_descontar;
            Consultor nuevo_consultor(tipo_trabajador,atoi(legajo.c_str()),nombre, atoi(paga.c_str()),true,atoi(horas_catedras.c_str()),atoi(horas_a_descontar.c_str()));
            Trabajador *nuevo_trabajador = &nuevo_consultor;
            Lista.agregar(nuevo_trabajador, pos_lista);
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

    for(int i = 0;i<obtener_tamanio;i++){
        if (obtener_nodo(i).obtener_legajo()== legajo_a_buscar){
            esta = true;
            pos_legajo = i;
        }
    }

    if(esta){
        // imprimir trabajador//
    }

    return pos_legajo


}
