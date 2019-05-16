#include "funciones.h"

int main(){


    ifstream archivo ;


    archivo.open("trabajadores.txt");

    if(archivo.fail()){
        cout<< "No se pudo abrir el archivo"<< endl;
        return 0; //CORTO EL PROGRAMA YA QUE NO SE PUDO ABRIR EL ARCHIVO//
}



char comando;
    char continuar_operando = 's';

    while(continuar_operando == 's'){


        cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;

        cout<<"MENU DE COMANDOS"<< endl;

        cout<<"a. buscar trabajador indicando su numero de legajo"<< endl;
        cout<<"b. dar de baja trabajador indicando su numero de legajo"<< endl;
        cout<<"c. dar de alta a un trabajador"<< endl;
        cout<<"d. listar todos los trabajadores con sus respectivas liquidaciones de sueldo"<< endl;
        cout<<"e. indicar sueldo maximo y a quién pertenece"<< endl;
        cout<<"f. indicar sueldo minimo y a quién pertenece"<< endl;
        cout<<"g. indicar la sumatoria de todos los sueldos"<< endl;
        cout<<"h. salir de la aplicacion"<< endl;    

        cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;
        cout<<"ingrese un comando"<< endl;
        cin>> comando;

        while(comando != 'a' && comando != 'b' && comando != 'c' && comando != 'd' && comando != 'e' && comando != 'f' && comando != 'g'  && comando != 'h'){

            cout<<"comando invalido"<<endl;
            cout<<"ingrese un comando"<< endl;
            cin>> comando;

        }

        switch(comando){

            case'a':

            int legajo_a_buscar;

            cout<<"ingrese el codigo del producto que desea buscar"<<endl;
            cin>>legajo_a_buscar;

            case 'h':

            return 0;





{