#include "funciones.h"

void menu(){

        cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;

        cout<<"MENU DE COMANDOS"<< endl;

        cout<<"a. Buscar trabajador indicando su numero de legajo"<< endl;
        cout<<"b. Dar de baja trabajador indicando su numero de legajo"<< endl;
        cout<<"c. Dar de alta a un trabajador"<< endl;
        cout<<"d. Listar todos los trabajadores con sus respectivas liquidaciones de sueldo"<< endl;
        cout<<"e. Indicar sueldo maximo y a quién pertenece"<< endl;
        cout<<"f. Indicar sueldo minimo y a quién pertenece"<< endl;
        cout<<"g. Indicar la sumatoria de todos los sueldos"<< endl;
        cout<<"h. Salir de la aplicacion"<< endl;    

        cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;
}



char leer_tipo_trabajador(ifstream &archivo){
    string tipo_trabajador;
    if(!archivo.eof()){
        archivo >> tipo_trabajador;
        return tipo_trabajador[0];   
    }
    return 'F';
}

void cargar_lista(ifstream &archivo,Lista* lista){
    int pos_lista = 1;
    
    string legajo;
    string nombre;
    string paga;
    char tipo_trabajador = leer_tipo_trabajador(archivo);
    while (tipo_trabajador != 'F'){ // Cond de corte para cuando llegue al final
        switch (tipo_trabajador){

            case'E':
        {
            string llegadas_tarde;
            string ausencias;

            archivo >> legajo >> nombre >> paga >> llegadas_tarde >> ausencias;
            Empleado* N_Empleado = new Empleado(tipo_trabajador,atoi(legajo.c_str()), nombre, atoi(paga.c_str()),true,atoi(llegadas_tarde.c_str()),atoi(ausencias.c_str()));
            //Trabajador *nuevo_trabajador = N_Empleado;
            lista -> agregar(N_Empleado, pos_lista);
            break;
        }
            case'J':
        {

            string cant_dias;
        
            archivo >> legajo >> nombre >> paga >> cant_dias;
            //Jornalero nuevo_jornalero();
            Jornalero* N_Jornalero = new Jornalero(tipo_trabajador,atoi(legajo.c_str()), nombre, atoi(paga.c_str()),true,atoi(cant_dias.c_str()));
            //Trabajador* nuevo_jornalero = N_Jornalero;
            lista -> agregar(N_Jornalero, pos_lista);
            break;
        }
            case'C':
        {
            string horas_catedras;
            string horas_a_descontar;

            archivo >> legajo >> nombre >> paga >> horas_catedras >> horas_a_descontar;
            //Consultor nuevo_consultor();
            Consultor* N_Consultor = new Consultor(tipo_trabajador,atoi(legajo.c_str()),nombre, atoi(paga.c_str()),true,atoi(horas_catedras.c_str()),atoi(horas_a_descontar.c_str()));
            //Trabajador* nuevo_consultor = N_Consultor;
            lista -> agregar(N_Consultor, pos_lista);
            break;
        }

        }
    pos_lista++;
    tipo_trabajador = leer_tipo_trabajador(archivo);
    }  
}

int buscar_legajo(int legajo_a_buscar, Lista* lista){
    bool esta = false;
    int pos_legajo;

    for(int i = 1; i<=lista->obtener_tamanio() ; i++){
        if (lista->obtener_nodo(i)->obtener_elemento()->obtener_legajo() == legajo_a_buscar){
            esta = true;
            pos_legajo = i;
        }
    }

    if(esta){
        lista->obtener_nodo(pos_legajo)->obtener_elemento()->a_cadena();
        return pos_legajo;
    }
    return -1;
}

void ordenar_lista(Lista lista){
    int n = lista.obtener_tamanio();
    for (int i = 1; i <= n-1; i++)        
        for (int j = 1; j <= n-i-1; j++)  
            if (lista.obtener_nodo(j)->obtener_elemento()->obtener_legajo()> lista.obtener_nodo(j+1)->obtener_elemento()->obtener_legajo()) 
                lista.swap(j, j+1); 
}
int buscar_sueldo(char modo, Lista* lista){
    int pos_legajo;
    int sueldo;
    int sueldo_lista;
    bool alta;
    if(modo=='A')
        sueldo=0;
    else
        sueldo=1000000;

    for(int i = 1;i<=lista->obtener_tamanio();i++){
        sueldo_lista=lista->obtener_nodo(i)->obtener_elemento()->obtener_sueldo_liquidado();
        alta=lista->obtener_nodo(i)->obtener_elemento()->obtener_alta();
        cout<<sueldo_lista<<endl;
        if ((sueldo_lista< sueldo)&&(modo == 'B')&& alta){
            sueldo=sueldo_lista;
            pos_legajo = i;
        }
        if((sueldo_lista > sueldo)&&(modo == 'A')&& alta){
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

void dar_de_baja(int pos_legajo,Lista* lista){
    lista->obtener_nodo(pos_legajo) -> obtener_elemento() -> asignar_alta(false);
}
void dar_de_alta(int pos_legajo, Lista* lista){
    if(!(lista->obtener_nodo(pos_legajo) -> obtener_elemento() ->obtener_alta()))
        lista->obtener_nodo(pos_legajo) -> obtener_elemento() -> asignar_alta(true);
}