#ifndef NODO_H
#define NODO_H

#include <vector>
#include <utility>

using namespace std;


class Nodo {

    public:

        int valor;
        Nodo* nodoIzquierda;
        Nodo* nodoDerecha;

    private:

        //Constructor
        Nodo();

        //Destructor
        ~Nodo();

        //Getters y Setters
        int getValor();
        void setValor(int valor);
        Nodo* getNodoIzquierda();
        void setNodoIzquierda(Nodo* nodoIzq);
        Nodo* getNodoDerecha();
        void setNodoDerecha(Nodo* nodoDer);

};


#endif //NODO_H