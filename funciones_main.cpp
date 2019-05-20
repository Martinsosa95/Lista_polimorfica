#include "funciones.h"

int main(){

    Lista* lista = new Lista;
    ifstream archivo ;

    archivo.open("trabajadores.txt");

    if(archivo.fail()){
        cout<< "No se pudo abrir el archivo"<< endl;
        return 0; //CORTO EL PROGRAMA YA QUE NO SE PUDO ABRIR EL ARCHIVO//
    }
    cargar_lista(archivo,lista);
    ordenar_lista(lista);

    
    char comando;
    bool continuar_operando = true;
    while(continuar_operando){ 
        menu();

        cout<<"Ingrese un comando"<< endl;
        cin>> comando;

        while(comando != 'a' && comando != 'b' && comando != 'c' && comando != 'd' && comando != 'e' && comando != 'f' && comando != 'g'  && comando != 'h'){

            cout<<"Comando invalido"<<endl;
            cout<<"Ingrese un comando"<< endl;
            cin>> comando;
            system("clear");

        }

        continuar_operando = operaciones(lista,comando);        
    }
}