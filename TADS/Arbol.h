#ifndef ARBOL_H
#define ARBOL_H

#include <vector>
#include <utility>
#include <iostream>
#include "Nodo.h"

class Arbol{

    private:
        vector<bool> codificacion;
        Nodo* raiz;
        int niveles;
    public:

        //Constructor
        Arbol();
        Arbol(int niv);
        //Destructor
        ~Arbol();

        //Getters y setters
        void asignarHojas(vector<pair<int,int>> frecuencias);
        vector<bool> getCodificacion();
        void setCodificacion(vector<bool> codificacion);
        int getNiveles();
        void setNiveles(int niv);

};

//#include "Arbol.cpp"

#endif // ARBOL_H