/********************************************************************************* 
-Nombres: Gabriel Jaramillo, Salomon Avila, Tomas Silva, Juan Pabon, Angel Morales
-Pontificia Universidad Javeriana
-Proyecto de Estructuras de Datos; Entrega 1
-Temas: TADs, Compilacion Modular, Contenedores, Estructuras Lineales
*********************************************************************************/

#ifndef VOLUMENIMAGENES_H
#define VOLUMENIMAGENES_H

#include <bits/stdc++.h>
#include "Imagen.h"

using namespace std;

// Declaración del TAD "VolumenImagenes":
class VolumenImagenes {
private:
    // Cantidad de imágenes almacenadas en el volumen
    int cantidadImagenes;
    
    // Nombre base de la colección de imágenes
    string nombreBase;
    
    // Vector que almacena las imágenes del volumen
    vector<Imagen> imagenes;

public:
    // Constructor: inicializa un volumen de imágenes vacío
    VolumenImagenes();
    
    // Retorna la cantidad de imágenes almacenadas
    int getCantidadImagenes();
    
    // Retorna el vector de imágenes
    vector<Imagen> getImagenes();
    
    // Asigna un valor a la cantidad de imágenes en el volumen
    void setCantidadImagenes(int cantidad);
    
    // Asigna un nuevo conjunto de imágenes al volumen
    void setImagenes(vector<Imagen> &imagen);
    
    // Asigna un nombre a la colección de imágenes
    void setNombre(string nom_base);
    
    // Retorna el nombre de la colección de imágenes
    string getNombre();
    
    // Carga múltiples imágenes desde archivos, dada una ruta base y una cantidad
    void cargarDesdeArchivos(string &base, int numImagenes);
    
    // Muestra información sobre el volumen de imágenes (nombre, cantidad, etc.)
    void mostrarInfo();
    
    // Genera una proyección 2D del conjunto de imágenes basado en la dirección de vista y un criterio
    void generarProyeccion2D(string &direccion, string &criterio, string &rutaFinal);
};

#endif // VOLUMENIMAGENES_H