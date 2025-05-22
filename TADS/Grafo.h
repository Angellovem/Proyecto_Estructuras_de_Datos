#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "Imagen.h"

class Grafo{
    private: 
        //Imagen inicial 
        Imagen imagen;
        //Grafo generado de la imagen inicial
        vector<vector<pair<int,int>>> grafo;
        //Matriz de distancias y etiquetas
        vector<vector<pair<int,int>>> distancias;
        //Imagen segmentada a partir de la
        Imagen imagenSegmentada;
    public:
        //Constructor por defecto
        Grafo();
        //Destructor por defecto
        ~Grafo();
        //Getters y Setters
        Imagen getImagen();
        vector<vector<pair<int,int>>> getGrafo();
        vector<vector<pair<int,int>>> getDistancias();
        Imagen getImagenSegmentada();
        void setImagen(Imagen nuevaImagen);
        void setGrafo(vector<vector<pair<int,int>>> nuevoGrafo);
        void setDistancias(vector<vector<pair<int,int>>> nuevasDistancias);
        void setImagenSegmentada(Imagen nuevaImagenSegmentada);
        //Operaciones propias
        //Inicializa la lista de adyacencia en el tamaño de la imagen
        void inicializarGrafo();
        //Inicializa la matriz de las distancias
        void inicializarDistancias();
        void imprimirGrafo();
        int calcularId(int x, int y);
        pair<int,int> calcularCordenadas(int id);
        void segmentarImagen(string nombre,vector<tuple<int,int,int>> semillas);
        
};



#endif //GRAFO_H