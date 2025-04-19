#include <vector>
#include <utility>
#include <queue>
#include <map>
#include "Arbol.h"
#include "Nodo.h"
#include "Imagen.h"

using namespace std;

auto comparador = [](Nodo* a, Nodo* b) {
    return a->getFrecuencia() > b->getFrecuencia();
};


Arbol::Arbol(){
    raiz = nullptr;
}

Arbol::~Arbol(){
    eliminar(raiz);
} 
void Arbol::setRaiz(Nodo *ra){
    raiz = ra;
}

map<int,vector<bool>> Arbol::getValores(){
    return valor;
}

void Arbol::eliminar(Nodo* nodo){
    if(nodo != nullptr){
        eliminar(nodo->getNodoIzquierda());
        eliminar(nodo->getNodoDerecha());
        delete nodo;
    }
}

void Arbol::crearArbol(vector<pair<int,int>> frecuencias){
    priority_queue<Nodo*, std::vector<Nodo*>, decltype(comparador)> arbol(comparador);
    for(int i = 0; i<frecuencias.size(); i++){
        if(frecuencias[i].second > 0){
            Nodo *nuevo = new Nodo;
            nuevo->setEsHoja(true);
            nuevo->setFrecuencia(frecuencias[i].second);
            nuevo->setNodoDerecha(nullptr);
            nuevo->setNodoIzquierda(nullptr);
            nuevo->setValor(frecuencias[i].first);
            arbol.push(nuevo);
        }
    }
    while(arbol.size()>1){
        Nodo *auxiliarDerecha, *auxiliarIzquierda;
        auxiliarIzquierda = arbol.top();
        arbol.pop();
        auxiliarDerecha = arbol.top();
        arbol.pop();
        Nodo *nuevo = new Nodo;
        nuevo->setNodoDerecha(auxiliarDerecha);
        nuevo->setNodoIzquierda(auxiliarIzquierda);
        nuevo->setEsHoja(false);
        nuevo->setFrecuencia( (auxiliarDerecha->getFrecuencia()) + (auxiliarIzquierda->getFrecuencia()));
        arbol.push(nuevo);
    }
    Nodo *raizArbol = arbol.top();
    setRaiz(raizArbol);
}

void Arbol::completarValores(vector<bool> codigo, Nodo *raiz){
    if(raiz->getEsHoja() == true){
        valor.emplace(raiz->getValor(),codigo);
    }
    codigo.push_back(0);
    completarValores(codigo,raiz->getNodoDerecha());
    codigo.pop_back();
    codigo.push_back(1);
    completarValores(codigo,raiz->getNodoDerecha());
    
}

