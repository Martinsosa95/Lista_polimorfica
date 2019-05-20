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
            lista -> agregar(N_Empleado, pos_lista);
            break;
        }
            case'J':
        {

            string cant_dias;
        
            archivo >> legajo >> nombre >> paga >> cant_dias;
            
            Jornalero* N_Jornalero = new Jornalero(tipo_trabajador,atoi(legajo.c_str()), nombre, atoi(paga.c_str()),true,atoi(cant_dias.c_str()));
            lista -> agregar(N_Jornalero, pos_lista);
            break;
        }
            case'C':
        {
            string horas_catedras;
            string horas_a_descontar;

            archivo >> legajo >> nombre >> paga >> horas_catedras >> horas_a_descontar;
            
            Consultor* N_Consultor = new Consultor(tipo_trabajador,atoi(legajo.c_str()),nombre, atoi(paga.c_str()),true,atoi(horas_catedras.c_str()),atoi(horas_a_descontar.c_str()));
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
    cout<<"No se encontro un trabajador con el legajo ingresado"<<endl;
    return -1;
}

void ordenar_lista(Lista* lista){
    int n = lista->obtener_tamanio();
    for (int i = 1; i <= n-1; i++)        
        for (int j = 1; j <= n-i; j++)  
            if (lista->obtener_nodo(j)->obtener_elemento()->obtener_legajo()> lista->obtener_nodo(j+1)->obtener_elemento()->obtener_legajo()) 
                lista->swap(j, j+1); 
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

void cambiar_alta(int pos_legajo,Lista* lista,bool cond){
    lista->obtener_nodo(pos_legajo) -> obtener_elemento() -> asignar_alta(cond);
}

bool operaciones(Lista* lista,char comando){

    switch(comando){

            case'a':{       
                int legajo_a_buscar;
                cout<<"Ingrese el legajo del trabajador que desea buscar"<<endl;     //BUSCA POR LEGAJO//
                cin>>legajo_a_buscar;
                buscar_legajo(legajo_a_buscar, lista);
                break;
            }
            

            case 'b':
            {
                int legajo_a_buscar,pos_legajo;
                do{
                cout<<"ingrese el legajo del trabajador a dar de baja: "<<endl;     //DA DE BAJA UN TRABAJADOR//
                cin>>legajo_a_buscar;
                pos_legajo = buscar_legajo(legajo_a_buscar,lista);
                }
                while(pos_legajo == -1);
                cambiar_alta(pos_legajo,lista,false);
                cout<<"El trabajador indicado ha sido dado de baja"<<endl;
                break;

            }
            case 'c':
            {
                int legajo_a_buscar,pos_legajo;
                do{
                cout<<"ingrese el legajo del trabajador a dar de alta: "<<endl;
                cin>>legajo_a_buscar;                                               //DA DEL ALTA UN TRABAJADOR//
                pos_legajo = buscar_legajo(legajo_a_buscar,lista);
                }
                while(pos_legajo == -1);
                cambiar_alta(pos_legajo,lista,true);
                cout<<"El trabajador indicado ha sido dado de alta"<<endl;
                break;

            }

            case 'd':{
                for(int i=1; i<=lista->obtener_tamanio() ; i++)
                    lista->obtener_nodo(i) -> obtener_elemento() -> a_cadena();   //IMPRIME TODOS LOS TRABAJADORES DE ALTA CON//
                break;                                                            //SUS RESPECTIVOS SUELDOS LIQUIDADOS//
            }

            case 'e':{
                int legajo;
                legajo = buscar_sueldo('A', lista);
                cout<<lista->obtener_nodo(legajo)->obtener_elemento()->obtener_nombre()<<endl; //INDICA EL SUELDO MAXIMO Y A QUIEN PERTENECE//
                break;
            }

            case 'f':{
                int legajo;
                legajo = buscar_sueldo('B', lista);                                            //INDICA EL SUELDO MINIMO Y A QUIEN PERTENCE//
                cout<<lista->obtener_nodo(legajo)->obtener_elemento()->obtener_nombre()<<endl;
                break;
            }

            case 'g':{
                int suma_sueldos=0;
                    for(int i=1; i<=lista->obtener_tamanio() ; i++)
                        if(lista->obtener_nodo(i) -> obtener_elemento() ->obtener_alta())     //INDICA LA SUMATORIA DE TODOS LOS SUELDOS//
                            suma_sueldos+=lista->obtener_nodo(i) -> obtener_elemento() -> obtener_sueldo_liquidado();
                cout<<"La sumatoria de los sueldos da "<< suma_sueldos<< endl;
                break;
            }

             case 'h':{
                delete lista;
                return false;
            }
    }
    return true;
}