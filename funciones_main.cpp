#include "funciones.h"

int main(){

    Lista* lista = new Lista;
    Lista* aux = new Lista;
    ifstream archivo ;

    archivo.open("trabajadores.txt");

    if(archivo.fail()){
        cout<< "No se pudo abrir el archivo"<< endl;
        return 0; //CORTO EL PROGRAMA YA QUE NO SE PUDO ABRIR EL ARCHIVO//
    }
    cargar_lista(archivo,lista);
    ordenar_lista_2(lista,aux);
    //delete lista; Pierdo referencias de aux, me queda mucha basura
    lista = aux; // Piso memoria de aux 66-60 allocs-frees

    cout<< lista->obtener_tamanio()<<endl;
    char comando;
    //char continuar_operando = 's';
    while(true){ 
        menu();

        cout<<"Ingrese un comando"<< endl;
        cin>> comando;

        while(comando != 'a' && comando != 'b' && comando != 'c' && comando != 'd' && comando != 'e' && comando != 'f' && comando != 'g'  && comando != 'h'){

            cout<<"Comando invalido"<<endl;
            cout<<"Ingrese un comando"<< endl;
            cin>> comando;
            system("clear");

        }

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
                break;														      //SUS RESPECTIVOS SUELDOS LIQUIDADOS//
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
                return 0;
            }
        }
    }
}