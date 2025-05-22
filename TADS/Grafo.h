#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "Imagen.h"

class Grafo{
    private: 
        Imagen imagen;
        vector<vector<pair<int,int>>> grafo;
        vector<vector<pair<int,int>>> distancias;
        Imagen imagenSegmentada;
    public:
        //Constructor por defecto
        Grafo();
        //Destructor por defecto
        ~Grafo();
        //Getters y Setters
        Imagen getImagen();
        vector<vector<pair<int,int>>> getGrafo();
        Imagen getImagenSegmentada();
        void setImagen(Imagen nuevaImagen);
        void setGrafo(vector<vector<pair<int,int>>> nuevoGrafo);
        void setImagenSegmentada(Imagen nuevaImagenSegmentada);
        //Operaciones propias
        void inicializarGrafo();
        void inicializarDistancias();
        void imprimirGrafo();
        int calcularId(int x, int y);
        pair<int,int> calcularCordenadas(int id);
        void segmentarImagen(string nombre,vector<tuple<int,int,int>> semillas);
        
};



#endif //GRAFO_H