/*********************************************************************************
-Nombres: Gabriel Jaramillo, Salomon Avila, Tomas Silva, Juan Pabon, Angel Morales
-Pontificia Universidad Javeriana
-Proyecto de Estructuras de Datos; Entrega 2
-Temas: TADs, Compilacion Modular, Contenedores, Estructuras Lineales
*********************************************************************************/

#include "Menu.h"

using namespace std;

void bienvenida()
{
    cout<<"Bienvenido al sistema de manejo de imágenes de la Pontificia Universidad Javeriana\n";
    cout<<"Integrantes:\n";
    cout<<" - Salomon Avila\n";
    cout<<" - Gabriel Jaramillo\n";
    cout<<" - Tomas Silva\n";
    cout<<" - Juan Pabon\n";
    cout<<" - Angel Morales\n";
}

void menu()
{
    cout << endl
         << endl;
    cout << "┌---------------------------------------------------------------┐" << endl;
    cout << "| MENU PRINCIPAL DE COMANDOS                                    |" << endl;
    cout << "| cargar_imagen [nombre.pgm]                                    |" << endl;
    cout << "| cargar_volumen [nombre_base] [numero_imagenes]                |" << endl;
    cout << "| info_imagen                                                   |" << endl;
    cout << "| info_volumen                                                  |" << endl;
    cout << "| proyeccion2D [direccion] [criterio] [nombre_archivo.pgm]      |" << endl;
    cout << "| codificar_imagen [nombre_archivo.huf]                         |" << endl;
    cout << "| decodificar_archivo [nombre_archivo.huf] [nombre_imagen.pgm]  |" << endl;
    cout << "| segmentar [nombre_salida.pgm] x1 y1 l1 x2 y2 l2 ...           |" << endl;
    cout << "| salir                                                         |" << endl;
    cout << "└---------------------------------------------------------------┘" << endl;
    cout << "$ ";
}

void ayuda()
{
}