#include "Grafo.h"

using namespace std;

Grafo::Grafo(){

}

Grafo::~Grafo(){

}

// Getters y Setters
Imagen Grafo::getImagen()
{
    return imagen;
}

vector<vector<pair<int, int>>> Grafo::getGrafo()
{
    return grafo;
}

Imagen Grafo::getImagenSegmentada()
{
    return imagenSegmentada;
}

void Grafo::setImagen(Imagen nuevaImagen)
{
    imagen = nuevaImagen;
}

void Grafo::setGrafo(vector<vector<pair<int, int>>> nuevoGrafo)
{
    grafo = nuevoGrafo;
}

void Grafo::setImagenSegmentada(Imagen nuevaImagenSegmentada)
{
    imagenSegmentada = nuevaImagenSegmentada;
}

// Operaciones propias del grafo
void Grafo::inicializarGrafo()
{
    vector<vector<pair<int, int>>> nuevoGrafo((imagen.getDimensionX() * imagen.getDimensionY()));
    grafo = nuevoGrafo;
    vector<vector<int>> valores = imagen.getVecImagen();
    for (int y = 0; y < imagen.getDimensionY(); ++y)
    {
        for (int x = 0; x < imagen.getDimensionX(); ++x)
        {
            int actual_id = y * imagen.getDimensionX() + x;
            int valor_actual = valores[y][x];

            // Vecinos en 4 direcciones: arriba, abajo, izquierda, derecha
            if (y > 0)
            { // arriba
                int vecino_id = (y - 1) * imagen.getDimensionX() + x;
                int peso = abs(valor_actual - valores[y - 1][x]);
                cout<<"el peso es: "<<peso<<endl;
                grafo[actual_id].push_back({vecino_id, peso});
            }
            if (y < imagen.getDimensionY() - 1)
            { // abajo
                int vecino_id = (y + 1) * imagen.getDimensionX() + x;
                int peso = abs(valor_actual - valores[y + 1][x]);
                grafo[actual_id].push_back({vecino_id, peso});
            }
            if (x > 0)
            { // izquierda
                int vecino_id = y * imagen.getDimensionX() + (x - 1);
                int peso = abs(valor_actual - valores[y][x - 1]);
                grafo[actual_id].push_back({vecino_id, peso});
            }
            if (x < imagen.getDimensionX() - 1)
            { // derecha
                int vecino_id = y * imagen.getDimensionX() + (x + 1);
                int peso = abs(valor_actual - valores[y][x + 1]);
                grafo[actual_id].push_back({vecino_id, peso});
            }
        }
    }
}

void Grafo::inicializarDistancias()
{
    pair<int, int> valorPorDefecto = {-1, -1};
    for (int i = 0; i < imagen.getDimensionY(); i++)
    {
        distancias.push_back(vector<pair<int, int>>());
        for (int j = 0; j < imagen.getDimensionX(); j++)
        {
            distancias[i].push_back(valorPorDefecto);
        }
    }
}

void Grafo::imprimirGrafo()
{   fstream archivo;
    archivo.open("revision.txt");
    for (int i = 0; i < grafo.size(); i++)
    {
        archivo << i << ": \n";
        for (int j = 0; j < grafo[i].size(); j++)
        {
            archivo << "\t" << i << "->" << grafo[i][j].first << " (costo: " << grafo[i][j].second << ")\n";
        }
    }
    archivo.close();
}