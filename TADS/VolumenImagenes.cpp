/*********************************************************************************
-Nombres: Gabriel Jaramillo, Salomon Avila, Tomas Silva, Juan Pabon, Angel Morales
-Pontificia Universidad Javeriana
-Proyecto de Estructuras de Datos; Entrega 1
-Temas: TADs, Compilacion Modular, Contenedores, Estructuras Lineales
*********************************************************************************/
#include <bits/stdc++.h>
#include "VolumenImagenes.h"

using namespace std;

VolumenImagenes::VolumenImagenes()
{
    cantidadImagenes = 0;
}

int VolumenImagenes::getCantidadImagenes()
{
    return cantidadImagenes;
}

vector<Imagen> VolumenImagenes::getImagenes()
{
    return imagenes;
}
void VolumenImagenes::setCantidadImagenes(int cantidad)
{
    cantidadImagenes = cantidad;
}
void VolumenImagenes::setImagenes(vector<Imagen> &imagen)
{
    imagenes = imagen;
}

void VolumenImagenes::setNombre(string nom_base)
{
    nombreBase = nom_base;
}

string VolumenImagenes::getNombre()
{
    return nombreBase;
}
/************
 * @brief carga un volumen desde archivos
 * @param base Nombre base del archivo
 * @param numImagenes numero de imagenes en el volumen
 * Carga los elementos del volumen, siendo estos
 * imagenes en formato .pgm
 ************/
void VolumenImagenes::cargarDesdeArchivos(string &base, int numImagenes)
{
    Imagen temp;
    setNombre(base);
    setCantidadImagenes(numImagenes);
    // Recorre por todas las imagenes del volumen
    for (int i = 0; i < numImagenes; i++)
    {
        string ruta = base + "/" + base;
        string auxDos;
        if (i < 9)
        {
            ruta += "0";
        }
        auxDos += to_string(i + 1);
        auxDos += ".pgm";
        ruta += auxDos;
        cout << ruta << endl;
        temp.cargarDesdePGM(ruta);
        imagenes.push_back(temp);
    }
}
/************
 * @brief Muestra datos del volumen
 * Muestra el nombre, el tamaño y las
 * dimensiones de las imagenes del
 * volumen
 ************/
void VolumenImagenes::mostrarInfo()
{
    if (imagenes.size() < 1)
    {
        cout << "No hay un volumen cargado en memoria" << endl;
    }
    else
    {
        // Usa la primera imagen para el tamaño de las imagenes en general
        cout << "Volumen cargado en memoria: " << getNombre() << ", tamaño: " << getCantidadImagenes() << ", ancho: " << getImagenes()[0].getDimensionX() << ", alto: " << getImagenes()[0].getDimensionY();
    }
    return;
}

/************
 * @brief Genera una imagen de proyeccion del volumen
 * @param direccion Valor ya sea x, y o z, que anuncian la direccion a proyectar
 * @param criterio Criterio que puede ser minimo, maximo, promedio o mediana, hecho para el valor a imprimir en el resultado
 * @param rutaFinal Ruta donde se guarda la imagen resultado
 * Tomando en cuenta el criterio y la direccion, torna un conjunto de imagenes en una proyeccion 2D
 ************/
void VolumenImagenes::generarProyeccion2D(string &direccion, string &criterio, string &rutaFinal)
{
    cout << "Todo bien aca" << endl;
    // Inicia revisando si la direccion es x
    if (direccion == "x")
    {
        // Usa una imagen de referencia para obtener datos de la misma, como dimensiones
        Imagen &referencia = imagenes[0];
        vector<vector<int>> valores;
        int maximo = -1;
        // Obtiene el total de imagenes del volumen
        int numeroTotalImagenes = getImagenes().size();
        int dimX = referencia.getDimensionX();
        cout << dimX << endl;
        int dimY = referencia.getDimensionY();
        cout << dimY << endl;

        // Crea una imagen vacia para guardar los valores
        vector<vector<int>> imagen_nueva(numeroTotalImagenes, vector<int>(dimX, 0));
        // Crea vectores temporales para guardar valores calculados
        vector<int> temporal(dimX, 0);
        vector<int> temporal2(dimY, 0);
        cout << "Entra a la direccion" << endl;
        // Si el criterio para la proyeccion tiene el promedio
        if (criterio == "promedio")
        {

            int contador = 4;
            // Viaja por cada imagen, y su respectivas coordenadas
            for (int k = 0; k < numeroTotalImagenes; k++)
            {
                Imagen &referenciaDos = imagenes[k];
                valores = referenciaDos.getVecImagen();

                for (int i = 0; i < dimY; i++)
                {
                    for (int j = 0; j < dimX; j++)
                    {
                        // Agrega valores al temporal que se suman para posteriormente  sacar el promedio
                        temporal[j] += valores[i][j];
                        if (j == 0 && k == 0)
                        {
                            cout << contador << " " << temporal[j] << endl;
                            contador++;
                        }
                    }
                }

                // Divide los valores para encontrar el valor promedio de cada pixel
                for (int j = 0; j < dimX; j++)
                {
                    temporal[j] /= dimY;
                    if (j == 0 && k == 0)
                    {
                        cout << contador << " " << temporal[j] << endl;
                        contador++;
                    }
                }

                // Guarda valores en la imagen resultado
                for (int j = 0; j < dimX; j++)
                {
                    imagen_nueva[k][j] = temporal[j];
                }
            }
        }
        // Si el criterio para la proyeccion tiene el minimo
        else if (criterio == "minimo")
        {

            // Viaja por cada imagen, y su respectivas coordenadas
            for (int k = 0; k < numeroTotalImagenes; k++)
            {
                Imagen &referenciaDos = imagenes[k];
                valores = referenciaDos.getVecImagen();

                for (int i = 0; i < dimY; i++)
                {
                    for (int j = 0; j < dimX; j++)
                    {
                        // Verifica por el valor del pixel, cambiandolo si el valor es menor al anterior
                        if (valores[i][j] < temporal[j])
                        {
                            temporal[j] = valores[i][j];
                        }
                    }
                }

                // Guarda valores en la imagen resultado
                for (int j = 0; j < dimX; j++)
                {
                    imagen_nueva[k][j] = temporal[j];
                }
            }
        }
        // Si el criterio para la proyeccion tiene el maximo
        else if (criterio == "maximo")
        {

            // Viaja por cada imagen, y su respectivas coordenadas
            for (int k = 0; k < numeroTotalImagenes; k++)
            {
                Imagen &referenciaDos = imagenes[k];
                valores = referenciaDos.getVecImagen();

                for (int i = 0; i < dimY; i++)
                {
                    for (int j = 0; j < dimX; j++)
                    {
                        // Verifica por el valor del pixel, cambiandolo si el valor es mayor al anterior
                        if (valores[i][j] > temporal[j])
                        {
                            temporal[j] = valores[i][j];
                        }
                    }
                }
                // Guarda valores en la imagen resultado
                for (int j = 0; j < dimX; j++)
                {
                    imagen_nueva[k][j] = temporal[j];
                }
            }
        }

        // Si el criterio para la proyeccion tiene la mediana
        else if (criterio == "mediana")
        {

            // Viaja por cada imagen, y su respectivas coordenadas
            for (int k = 0; k < numeroTotalImagenes; k++)
            {
                Imagen &referenciaDos = imagenes[k];
                valores = referenciaDos.getVecImagen();
                for (int i = 0; i < dimX; i++)
                {
                    for (int j = 0; j < dimY; j++)
                    {
                        temporal2[j] = valores[j][i];
                    }
                    // Ordena y busca el mayor valor de los pixeles
                    sort(temporal2.begin(), temporal2.end());
                    cout << temporal2[dimY / 2];
                    temporal[i] = temporal2[dimY / 2];
                }

                // Guarda valores en la imagen resultado
                for (int i = 0; i < dimX; i++)
                {
                    imagen_nueva[k][i] = temporal[i];
                }
            }
        }

        // Guarda en la imagen temporal los datos que le sean importantes para el formato del archivo
        Imagen imagenTemporal;
        imagenTemporal.setVecImagen(imagen_nueva);
        imagenTemporal.setDimensionX(dimX);
        imagenTemporal.setDimensionY(getImagenes().size());
        string aux = "P2";
        imagenTemporal.setFormato(aux);
        imagenTemporal.setNombre(rutaFinal);
        imagenTemporal.setMaxClaro(maximo);
        // Guarda la imagen en formato pgm por medio de la funcion guardarComoPGM
        cout << "Enviando a guardar " << imagen_nueva.size() << " " << imagen_nueva[0].size() << endl;
        imagenTemporal.guardarComoPGM(rutaFinal);
    }
    else if (direccion == "y")
    {
        Imagen &referencia = imagenes[0];
        vector<vector<int>> valores;
        int maximo = -1;
        int numeroTotalImagenes = getImagenes().size();
        int dimX = referencia.getDimensionX();
        cout << dimX << endl;
        int dimY = referencia.getDimensionY();
        cout << dimY << endl;

        vector<vector<int>> imagen_nueva(dimY, vector<int>(numeroTotalImagenes, 0));

        vector<int> temporal(dimY, 0);
        vector<int> temporal2(dimX, 0);
        cout << "Entra a la direccion y" << endl;

        if (criterio == "promedio")
        {

            int contador = 4;
            // Viaja por cada imagen, y su respectivas coordenadas

            for (int k = 0; k < numeroTotalImagenes; k++)
            {
                Imagen &referenciaDos = imagenes[k];
                valores = referenciaDos.getVecImagen();

                for (int i = 0; i < dimY; i++)
                {
                    for (int j = 0; j < dimX; j++)
                    {
                        temporal[i] += valores[i][j];
                    }

                    temporal[i] /= dimX;

                    imagen_nueva[i][k] = temporal[i];
                }
            }
        }
        else if (criterio == "minimo")
        {
            int contador = 4;
            // Viaja por cada imagen, y su respectivas coordenadas

            for (int k = 0; k < numeroTotalImagenes; k++)
            {
                Imagen &referenciaDos = imagenes[k];
                valores = referenciaDos.getVecImagen();
                for (int i = 0; i < dimY; i++)
                {
                    for (int j = 0; j < dimX; j++)
                    {
                        // Verifica por el valor del pixel, cambiandolo si el valor es menor al anterior
                        if (valores[i][j] < temporal[j])
                        {
                            temporal[j] = valores[i][j];
                        }
                    }

                    imagen_nueva[i][k] = temporal[i];
                }
            }
        }
        else if (criterio == "maximo")
        {
            int contador = 4;
            // Viaja por cada imagen, y su respectivas coordenadas

            for (int k = 0; k < numeroTotalImagenes; k++)
            {
                Imagen &referenciaDos = imagenes[k];
                valores = referenciaDos.getVecImagen();
                for (int i = 0; i < dimY; i++)
                {
                    for (int j = 0; j < dimX; j++)
                    {
                        // Verifica por el valor del pixel, cambiandolo si el valor es menor al anterior
                        if (valores[i][j]> temporal[j])
                        {
                            temporal[j] = valores[i][j];
                        }
                    }

                    imagen_nueva[i][k] = temporal[i];
                }
            }
        }
        else if (criterio == "mediana")
        {
            for (int k = 0; k < numeroTotalImagenes; k++)
            {
                Imagen &referenciaDos = imagenes[k];
                valores = referenciaDos.getVecImagen();

                for (int i = 0; i < dimY; i++)
                {
                    vector<int> vi;
                    for (int j = 0; j < dimX; j++)
                    {   

                        
                        vi.push_back(valores[i][j]);
                    }

                    sort(vi.begin(),vi.end());

                    int mid = vi.size()/2;
                    imagen_nueva[i][k] = vi[mid];
                }
            }
        }

        Imagen imagenTemporal;
        imagenTemporal.setVecImagen(imagen_nueva);
        imagenTemporal.setDimensionX(getImagenes().size());
        imagenTemporal.setDimensionY(dimY);
        string aux = "P2";
        imagenTemporal.setFormato(aux);
        imagenTemporal.setNombre(rutaFinal);
        imagenTemporal.setMaxClaro(maximo);
        // Guarda la imagen en formato pgm por medio de la funcion guardarComoPGM
        cout << "Enviando a guardar " << imagen_nueva.size() << " " << imagen_nueva[0].size() << endl;
        imagenTemporal.guardarComoPGM(rutaFinal);
    }
    else if (direccion == "z")
    {
        Imagen &referencia = imagenes[0];
        vector<vector<int>> valores;
        int maximo = -1;
        int numeroTotalImagenes = getImagenes().size();
        int dimX = referencia.getDimensionX();
        cout << dimX << endl;
        int dimY = referencia.getDimensionY();
        cout << dimY << endl;

        vector<vector<int>> imagen_nueva(dimX, vector<int>(dimY, 0));
        vector<vector<int>> imagen_nueva2(dimX, vector<int>(dimY, 256));

        vector<int> temporal(dimY, 0);
        vector<int> temporal2(dimX, 0);
        Imagen imagenTemporal;

        cout << "Entra a la direccion z" << endl;
        if (criterio == "promedio")
        {

            for (int i = 0; i < dimY; i++)
            {
                for (int j = 0; j < dimX; j++)
                {
                    int suma = 0;

                    for (auto &img : imagenes)
                    {
                        valores = img.getVecImagen();
                        suma += valores[i][j];
                    }
                    imagen_nueva[i][j] = suma / numeroTotalImagenes;
                }
            }
        }
        else if (criterio == "maximo")
        {
            for (int i = 0; i < dimY; i++)
            {
                for (int j = 0; j < dimX; j++)
                {
                    int suma = 0;

                    for (auto &img : imagenes)
                    {
                        valores = img.getVecImagen();
                        if (valores[i][j] > temporal[j])
                        {
                            imagen_nueva[i][j] = valores[i][j];
                        }
                    }
                }
            }
        }
        else if (criterio == "minimo")
        {
            for (int k = 0; k < numeroTotalImagenes; k++)
            {
                Imagen &referenciaDos = imagenes[k];
                valores = referenciaDos.getVecImagen();

                for (int i = 0; i < dimY; i++)
                {
                    for (int j = 0; j < dimX; j++)
                    {
                        if (valores[i][j] < imagen_nueva2[i][j])
                        {
                            imagen_nueva2[i][j] = valores[i][j];
                        }
                    }
                }
                imagenTemporal.setVecImagen(imagen_nueva2);
            }
        }
        else if (criterio == "mediana")
        {
            for (int i = 0; i < dimY; i++)
            {
                for (int j = 0; j < dimX; j++)
                {
                    vector<int> vi;

                    for (auto &img : imagenes)
                    {
                        valores = img.getVecImagen();
                        vi.push_back(valores[i][j]);
                    }
                    int mid = vi.size() / 2;
                    imagen_nueva[i][j] = vi[mid];
                }
            }
        }
        imagenTemporal.setVecImagen(imagen_nueva);
        imagenTemporal.setDimensionX(dimX);
        imagenTemporal.setDimensionY(dimY);
        string aux = "P2";
        imagenTemporal.setFormato(aux);
        imagenTemporal.setNombre(rutaFinal);
        imagenTemporal.setMaxClaro(maximo);
        // Guarda la imagen en formato pgm por medio de la funcion guardarComoPGM
        cout << "Enviando a guardar " << imagen_nueva.size() << " " << imagen_nueva[0].size() << endl;
        imagenTemporal.guardarComoPGM(rutaFinal);
    }

    else
    {
        cout << "Mal" << endl;
    }

    return;
}