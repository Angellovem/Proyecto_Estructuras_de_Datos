/*********************************************************************************
-Nombres: Gabriel Jaramillo, Salomon Avila, Tomas Silva, Juan Pabon, Angel Morales
-Pontificia Universidad Javeriana
-Proyecto de Estructuras de Datos; Entrega 2
-Temas: TADs, Compilacion Modular, Contenedores, Estructuras Lineales
*********************************************************************************/
#ifndef NODO_H
#define NODO_H

#include <vector>
#include <utility>

using namespace std;


class Nodo {

    private:
        //Frecuencia de aparicion de determinado valor en la imagen
        int frecuencia;
        //Un valor de la imagen
        int valor;
        //Indica si el nodo actual es una hoja del arbol.
        bool esHoja;
        //Apuntador de tipo Nodo al hijo izquierdo
        Nodo* nodoIzquierda;
        //Apuntador de tipo Nodo al hijo derecho
        Nodo* nodoDerecha;

    public:

        //Constructor
        Nodo();

        //Destructor
        ~Nodo();

        //Getters y Setters
        int getFrecuencia();
        void setFrecuencia(int frec);
        void setEsHoja(bool estado);
        bool getEsHoja();
        int getValor();
        void setValor(int valor);
        Nodo* getNodoIzquierda();
        void setNodoIzquierda(Nodo* nodoIzq);
        Nodo* getNodoDerecha();
        void setNodoDerecha(Nodo* nodoDer);

    

};


#endif //NODO_H