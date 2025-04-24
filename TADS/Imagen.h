/*********************************************************************************
-Nombres: Gabriel Jaramillo, Salomon Avila, Tomas Silva, Juan Pabon, Angel Morales
-Pontificia Universidad Javeriana
-Proyecto de Estructuras de Datos; Entrega 2
-Temas: TADs, Compilacion Modular, Contenedores, Estructuras Lineales
*********************************************************************************/
#ifndef IMAGEN_H
#define IMAGEN_H

#include <bits/stdc++.h>

using namespace std;

// Declaración del TAD "Imagen":
class Imagen
{
private:
    // Matriz que almacena los valores de los píxeles de la imagen en escala de grises
    vector<vector<int>> vecImagen;

    // Valor máximo de claridad en la imagen (escala de grises 0-255)
    int maxClaro;

    // Dimensiones de la imagen en píxeles
    int dimensionX; // Ancho de la imagen
    int dimensionY; // Alto de la imagen

    // Formato de la imagen (por ejemplo, "P2" para PGM ASCII)
    string formato;

    // Nombre de la imagen (nombre del archivo)
    string nombre;

public:
    // Constructor: inicializa la imagen con valores por defecto
    Imagen();

    // Retorna un vector de pares con las frecuencias
    vector<pair<int, int>> codificacion();

    // Retorna un vector de pares con las frecuencias
    vector<pair<int, int>> frecueciasDeValores();

    // Retorna la matriz de píxeles de la imagen
    vector<vector<int>> getVecImagen();

    // Asigna una nueva matriz de píxeles a la imagen
    void setVecImagen(vector<vector<int>> vecImg);

    // Retorna el valor máximo de claridad (brillo) permitido en la imagen
    int getMaxClaro();

    // Asigna el valor máximo de claridad de la imagen
    void setMaxClaro(int maxClar);

    // Retorna el ancho de la imagen en píxeles
    int getDimensionX();

    // Asigna el ancho de la imagen en píxeles
    void setDimensionX(int dimX);

    // Retorna el alto de la imagen en píxeles
    int getDimensionY();

    // Asigna el alto de la imagen en píxeles
    void setDimensionY(int dimY);

    // Retorna el formato de la imagen (por ejemplo, "P2" para PGM)
    string getFormato();

    // Asigna el formato de la imagen
    void setFormato(string &form);

    // Retorna el nombre del archivo de la imagen
    string getNombre();

    // Asigna el nombre del archivo de la imagen
    void setNombre(string &nombre);

    // Carga una imagen en formato PGM desde una ruta específica
    void cargarDesdePGM(string &ruta);

    // Guarda la imagen en formato PGM en una ruta específica
    void guardarComoPGM(string &ruta);

    // Muestra información relevante sobre la imagen (dimensiones, formato, nombre, etc.)
    void mostrarInfo();
};

#endif // IMAGEN_H