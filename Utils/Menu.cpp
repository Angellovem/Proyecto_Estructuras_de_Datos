/********************************************************************************* 
-Nombres: Gabriel Jaramillo, Salomon Avila, Tomas Silva, Juan Pabon, Angel Morales
-Pontificia Universidad Javeriana
-Proyecto de Estructuras de Datos; Entrega 1
-Temas: TADs, Compilacion Modular, Contenedores, Estructuras Lineales
*********************************************************************************/

#include "Menu.h"

using namespace std;

void menu(){
    cout<<endl<<endl;
    cout<<"┌---------------------------------------------------------------┐"<<endl;
    cout<<"| MENU PRINCIPAL DE COMANDOS                                    |"<<endl;
    cout<<"| cargar_imagen [nombre.pgm]                                    |"<<endl;
    cout<<"| cargar_volumen [nombre_base] [numero_imagenes]                |"<<endl;
    cout<<"| info_imagen                                                   |"<<endl;
    cout<<"| info_volumen                                                  |"<<endl;
    cout<<"| proyeccion2D [direccion] [criterio] [nombre_archivo.pgm]      |"<<endl;
    cout<<"| codificar_imagen [nombre_archivo.huf]                         |"<<endl;
    cout<<"| decodificar_archivo [nombre_archivo.huf] [nombre_imagen.pgm]  |"<<endl;
    cout<<"| salir                                                         |"<<endl;
    cout<<"└---------------------------------------------------------------┘"<<endl;
    cout<<"$ ";
}