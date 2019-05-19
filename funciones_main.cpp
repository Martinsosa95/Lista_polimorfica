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
    //lista.obtener_nodo(4) -> obtener_elemento() -> a_cadena();
    //ordenar_lista(lista);
    cout<< lista.obtener_tamanio()<<endl;
    char comando;
    //char continuar_operando = 's';
    //lista.obtener_nodo(3) -> obtener_elemento() -> a_cadena();
    /*
    for(int i=1; i<=lista.obtener_tamanio() ; i++)
        lista.obtener_nodo(i) -> obtener_elemento() -> a_cadena();
    */
    while(true){ 

        menu();

        cout<<"Ingrese un comando"<< endl;
        cin>> comando;

        while(comando != 'a' && comando != 'b' && comando != 'c' && comando != 'd' && comando != 'e' && comando != 'f' && comando != 'g'  && comando != 'h'){

            cout<<"Comando invalido"<<endl;
            cout<<"Ingrese un comando"<< endl;
            cin>> comando;
            //comando = 'a';

        }

        switch(comando){

            case'a':{

                int legajo_a_buscar;

                cout<<"Ingrese el legajo del trabajador que desea buscar"<<endl;
                cin>>legajo_a_buscar;
                //legajo_a_buscar = 321;
                buscar_legajo(legajo_a_buscar, lista);
                break;
            }
            

            case 'b':{

                int legajo_a_buscar,pos_legajo;
                do{
                cout<<"ingrese el legajo del trabajador: "<<endl;
                cin>>legajo_a_buscar;
                pos_legajo = buscar_legajo(legajo_a_buscar,lista);
                }
                while(pos_legajo == -1);
                dar_de_baja(pos_legajo,lista);
                break;

            }
            case 'c':{

            }
            case 'd':{

            }
            case 'e':{
                int legajo;
                legajo = buscar_sueldo('A', lista);
                cout<<lista.obtener_nodo(legajo)->obtener_elemento()->obtener_nombre()<<endl;
                break;
            }
            case 'f':{
                int legajo;
                legajo = buscar_sueldo('B', lista);
                cout<<lista.obtener_nodo(legajo)->obtener_elemento()->obtener_nombre()<<endl;
                break;
            }
            case 'g':{

            }
             case 'h':
                return 0;
                break;
        }

    }
    return 0;


}