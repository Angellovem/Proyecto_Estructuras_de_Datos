#ifndef MANEJADORCODIFICACION_H
#define MANEJADORCODIFICACION_H

#include "Imagen.h"
#include "Arbol.h"
class Manejador{
    private:
        Imagen imagen;
        vector<bool> codificacion;
        vector<pair<int,int>> frecuencias;
        Arbol arbol;
    public:
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

        //Metodos propios
        void codificar();
        void cargarDesdePGM(string ruta);
        void cargarDesdeHUF(string ruta);
        void numeroAbinario();

};


//#include "ManejadorCodificacion.cpp"

#endif //MANEJADORCODIFICACION_H