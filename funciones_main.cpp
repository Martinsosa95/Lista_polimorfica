#include "funciones.h"

int main(){

    Lista lista;
    ifstream archivo ;


    archivo.open("trabajadores.txt");

    if(archivo.fail()){
        cout<< "No se pudo abrir el archivo"<< endl;
        return 0; //CORTO EL PROGRAMA YA QUE NO SE PUDO ABRIR EL ARCHIVO//
    }
    cargar_lista(archivo, lista);
    ordenar_lista(lista);
    char comando;
    char continuar_operando = 's';

    while(continuar_operando == 's'){


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
        cout<<"Ingrese un comando"<< endl;
        cin>> comando;

        while(comando != 'a' && comando != 'b' && comando != 'c' && comando != 'd' && comando != 'e' && comando != 'f' && comando != 'g'  && comando != 'h'){

            cout<<"Comando invalido"<<endl;
            cout<<"Ingrese un comando"<< endl;
            cin>> comando;

        }

        switch(comando){

            case'a':{

            int legajo_a_buscar;

            cout<<"Ingrese el legajo del trabajador que desea buscar"<<endl;
            cin>>legajo_a_buscar;
            buscar_legajo(legajo_a_buscar, lista);

            }
            break;

            case 'b':{
            int legajo_a_buscar;

            cout<<"Ingrese el legajo del trabajador a dar de baja"<<endl;
            cin>>legajo_a_buscar;

            }
            case 'c':{

            }
            case 'd':{

            }
            case 'e':{
                int legajo;
                legajo = buscar_sueldo('A', lista);
                cout<<lista.obtener_nodo(legajo)->obtener_elemento()->obtener_nombre()<<endl;
            }
            case 'f':{
                int legajo;
                legajo = buscar_sueldo('B', lista);
                cout<<lista.obtener_nodo(legajo)->obtener_elemento()->obtener_nombre()<<endl;
            }
            case 'g':{

            }



            case 'h':

            return 0;
        }

    }


}