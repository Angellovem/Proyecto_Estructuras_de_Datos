#ifndef ARBOL_H
#define ARBOL_H

#include <vector>
#include <utility>
#include <map>
#include <iostream>
#include "Nodo.h"

class Arbol{

    private:
        vector<bool> codificacion;
        Nodo* raiz;
        map<int,vector<bool>> valor;

    public:

        //Constructor
        Arbol();


        //Getters y setters
        vector<bool> getCodificacion();
        void setCodificacion(vector<bool> codificacion);

        Nodo* getRaiz();
        void setRaiz(Nodo *ra);

        map<int,vector<bool>> getValores();
        void setValores(map<int,vector<bool>> val);

        void eliminar(Nodo* raiz);
        void crearArbol(vector<pair<int,int>> frecuencias);

        void completarValores(vector<bool> codigo, Nodo *raiz);
        
};

//#include "Arbol.cpp"

#endif // ARBOL_H