/*********************************************************************************
-Nombres: Gabriel Jaramillo, Salomon Avila, Tomas Silva, Juan Pabon, Angel Morales
-Pontificia Universidad Javeriana
-Proyecto de Estructuras de Datos; Entrega 2
-Temas: TADs, Compilacion Modular, Contenedores, Estructuras Lineales
*********************************************************************************/
#ifndef MANEJADORCODIFICACION_H
#define MANEJADORCODIFICACION_H

#include "Imagen.h"
#include "Arbol.h"
class Manejador{
    private:
        //Instancia de la imagen con la cual se va a trabajar
        Imagen imagen;
        //Vector de booleanos que usa la imagen ¡Revisar las aclaraciones contenidas en el readme.md del repositorio!
        vector<bool> codificacion;
        //Vectores de pares para poder guardar la informacion de manera <valor,frecuencia>
        vector<pair<int,int>> frecuencias;
        //Arbol cuya funcion es contener la codificación mediante Huffman
        Arbol arbol;
    public:
        //Constructor por defecto
        Manejador();

        //getters y setters
        Imagen getImagen();
        void setImagen(Imagen imagen); 
        
        vector<bool> getCodificacion();
        void setCodificacion(vector<bool> codificacion);

        vector<pair<int,int>> getFrecuencias();
        void setFrecuencias(vector<pair<int,int>> frec);

        Arbol getArbol();
        void setArbol(Arbol arbol);

        //Metodo de codificación de imagenes
        void codificar();
        //Metodo que ejecuta el proceso de la codificacion y guardado
        void cargarDesdePGM(string ruta);
        //Metodo que ejecuta el proceso de la decodificación y guardado
        void cargarDesdeHUF(string rutaHUF, string rutaPGM);
        //Metodo auxiliar de la clase para poder generar la codificacion
        void numeroAbinario();

};


//#include "ManejadorCodificacion.cpp"

#endif //MANEJADORCODIFICACION_H