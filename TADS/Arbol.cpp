#include <vector>
#include <utility>
#include "Arbol.h"

using namespace std;

Arbol::Arbol(int niv){
    raiz = new Nodo;
    niveles = niv;
}

Arbol::Arbol(){
    raiz = new Nodo;
    niveles = -1;
}

Arbol::~Arbol(){
    
}

void Arbol::setNiveles(int niv){
    niveles = niv;
}