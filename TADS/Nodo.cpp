#include <vector>
#include <utility>
#include "Nodo.h"
using namespace std;

Nodo::Nodo(){
    frecuencia = -1;
    valor = -1;
    esHoja = false;
    nodoIzquierda = nullptr;
    nodoDerecha = nullptr;
}

void Nodo::establecerArbol(Nodo *raiz, int nivelesNecesarios, int nivelActual){
    if(nivelActual <= nivelesNecesarios){
        raiz->nodoDerecha = nullptr;
        raiz->nodoIzquierda = nullptr;
        int nuevo = nivelActual+1;
        establecerArbol(raiz->getNodoIzquierda(),nivelesNecesarios,nuevo);
        establecerArbol(raiz->getNodoDerecha(),nivelActual,nuevo);
    }
    if(nivelActual == nivelesNecesarios){
        raiz->getNodoDerecha()->setEsHoja(true);
        raiz->getNodoIzquierda()->setEsHoja(false);
    }
}

Nodo* Nodo::getNodoDerecha(){
    return nodoDerecha;
}

Nodo* Nodo::getNodoIzquierda(){
    return nodoIzquierda;
}

void Nodo::setEsHoja(bool estado){
    esHoja = estado;
}
