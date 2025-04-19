#ifndef NODO_H
#define NODO_H

#include <vector>
#include <utility>

using namespace std;


class Nodo {

    private:
        int frecuencia;
        int valor;
        bool esHoja;
        Nodo* nodoIzquierda;
        Nodo* nodoDerecha;

    public:

        //Constructor
        Nodo();

        //Destructor
        ~Nodo();

        //Getters y Setters
        int getFrecuencia();
        void setFreciencia(int frec);
        void setEsHoja(bool estado);
        void getEsHoja();
        int getValor();
        void setValor(int valor);
        Nodo* getNodoIzquierda();
        void setNodoIzquierda(Nodo* nodoIzq);
        Nodo* getNodoDerecha();
        void setNodoDerecha(Nodo* nodoDer);

        //Metodos propios
        void establecerArbol(Nodo *raiz, int nivelesNecesarios, int nivelActual);

};


#endif //NODO_H