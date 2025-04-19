#ifndef MANEJADORCODIFICACION_H
#define MANEJADORCODIFICACION_H

#include "Imagen.h"
#include "Arbol.h"
class Manejador{
    private:
        Imagen imagen;
        vector<bool> codificacion;
        Arbol arbol;
    public:
        Manejador();

        //getters y setters
        Imagen getImagen();
        void setImagen(Imagen imagen); 
        
        vector<bool> getCodificacion();
        void setCodificacion(vector<bool> codificacion);

        Arbol getArbol();
        void setArbol(Arbol arbol);

        //Metodos propios
        int calcularNiveles(vector<pair<int,int>> frecuencias);
        void imprimirDatos();
        void cargarDesdePGM(string ruta);
        void cargarDesdeHUF(string ruta);

};


//#include "ManejadorCodificacion.cpp"

#endif //MANEJADORCODIFICACION_H