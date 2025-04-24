/*********************************************************************************
-Nombres: Gabriel Jaramillo, Salomon Avila, Tomas Silva, Juan Pabon, Angel Morales
-Pontificia Universidad Javeriana
-Proyecto de Estructuras de Datos; Entrega 2
-Temas: TADs, Compilacion Modular, Contenedores, Estructuras Lineales
*********************************************************************************/
#ifndef ARBOL_H
#define ARBOL_H

#include <vector>
#include <utility>
#include <map>
#include <iostream>
#include "Nodo.h"

class Arbol
{

private:
    //Direccion de memoria que apunta a una instancia de la clase nodo. Esta equivale a la raiz del arbol
    Nodo *raiz;
    //Estructura de mapa donde se almacena el equivalente de un valor en binario
    map<int, vector<bool>> valor;

public:
    // Constructor
    Arbol();

    // Getters y setters
    vector<bool> getCodificacion();
    void setCodificacion(vector<bool> codificacion);

    Nodo *getRaiz();
    void setRaiz(Nodo *ra);

    map<int, vector<bool>> getValores();
    void setValores(map<int, vector<bool>> val);

    //Metodo recursiva para liberar memoria ocupada
    void eliminar(Nodo *raiz);
    //Metodo para crear un arbol usando las frecuencias de los valores
    void crearArbol(vector<pair<int, int>> frecuencias);
    //Rellena de valores el mapa de equivalencias
    void completarValores(vector<bool> codigo, Nodo *raiz);
};

// #include "Arbol.cpp"

#endif // ARBOL_H