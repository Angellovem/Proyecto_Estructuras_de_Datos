/*********************************************************************************
-Nombres: Gabriel Jaramillo, Salomon Avila, Tomas Silva, Juan Pabon, Angel Morales
-Pontificia Universidad Javeriana
-Proyecto de Estructuras de Datos; Entrega 1
-Temas: TADs, Compilacion Modular, Contenedores, Estructuras Lineales
*********************************************************************************/
#include "Imagen.h"

using namespace std;

// Implementación del constructor de Imagen
/************
 * @brief Constructor de la clase Imagen
 * Inicializa los atributos de la clase con valores por defecto.
 ************/
Imagen::Imagen()
{
    maxClaro = 0;
    dimensionX = 0;
    dimensionY = 0;
    formato = "";
    nombre = "";
    vecImagen = vector<vector<int>>();
}

vector<pair<int, int>> Imagen::codificacion()
{
    //cout << "cargado" << endl;
    vector<pair<int, int>> frec = frecueciasDeValores();
    return frec;
}

vector<pair<int, int>> Imagen::frecueciasDeValores()
{
    vector<pair<int, int>> frecuencias(getMaxClaro(), {0, 0});
    //cout << "creacion" << endl;
    for (int i = 0; i < frecuencias.size(); i++)
    {
        frecuencias[i].first = i;
    }
    //cout << "llenado" << endl;
    for (int i = 0; i < dimensionY; i++)
    {
        //cout << "analizando fila " << i << endl;
        for (int j = 0; j < dimensionX; j++)
        {
            int pos = vecImagen[i][j];
            // cout<<"En la posicion "<<i<<" "<<j<<" está el valor de: "<<pos<<endl;
            int cantidad = frecuencias[pos].second;
            cantidad++;
            frecuencias[pos].second = cantidad;
        }
    }
    //cout << "actualizado" << endl;
    /*for (auto iterador = frecuencias.begin(); iterador != frecuencias.end();)
    {
        if (iterador->second == 0)
        {
            iterador = frecuencias.erase(iterador);
        }
        else
        {
            ++iterador;
        }
    }
    */
   return frecuencias;
}

// Implementación de otros métodos si es necesario
/************
 * @brief Obtiene la matriz de píxeles de la imagen.
 * @return Matriz de píxeles en formato vector de vectores.
 ************/
vector<vector<int>> Imagen::getVecImagen()
{
    return vecImagen;
}

/************
 * @brief Asigna la matriz de píxeles de la imagen.
 * @param vecImg Matriz de píxeles a asignar.
 ************/
void Imagen::setVecImagen(vector<vector<int>> vecImg)
{
    vecImagen = vecImg;
}

/************
 * @brief Asigna el nombre de la imagen.
 * @param nombre2 Nombre de la imagen.
 ************/
void Imagen::setNombre(string &nombre2)
{
    nombre = nombre2;
}

// Métodos para asignar y obtener dimensiones y valores máximos de claridad
void Imagen::setDimensionX(int dimension)
{
    dimensionX = dimension;
}

void Imagen::setDimensionY(int dimension)
{
    dimensionY = dimension;
}

void Imagen::setMaxClaro(int maximo)
{
    maxClaro = maximo;
}

int Imagen::getDimensionY()
{
    return dimensionY;
}

int Imagen::getDimensionX()
{
    return dimensionX;
}

void Imagen::setFormato(string &form)
{
    formato = form;
}

/************
 * @brief Carga una imagen en formato PGM desde un archivo.
 * @param nombre Nombre del archivo PGM a cargar.
 * Lee el contenido del archivo PGM y extrae la información relevante como formato,
 * dimensiones y valores de píxeles, almacenándolos en la estructura de datos.
 ************/
void Imagen::cargarDesdePGM(string &nombre)
{
    string rutaDeArchivo = "src/";
    rutaDeArchivo += nombre;
    setNombre(nombre);
    ifstream archivo;
    archivo.open(rutaDeArchivo);
    if (!archivo.is_open())
    {
        cout << "La imagen " << rutaDeArchivo << " no pudo ser cargada" << endl;
        return;
    }
    if (archivo.is_open())
    {
        // Limpia el vector de imagen para evitar datos residuales
        vecImagen.clear();

        // Guarda elementos para la imagen como el formato y las dimensiones
        string linea;
        archivo >> linea;
        setFormato(linea);
        int dimX, dimY, maxClaro;
        archivo >> dimX >> dimY >> maxClaro;
        setDimensionX(dimX);
        setDimensionY(dimY);
        setMaxClaro(maxClaro);

        // Se leen los píxeles y se almacenan en la matriz de la imagen
        for (int i = 0; i < dimY; i++)
        {
            vector<int> vi(dimX);
            for (int j = 0; j < dimX; j++)
            {
                archivo >> vi[j];
            }
            vecImagen.push_back(vi);
        }

        archivo.close();

        // Revisar si el vector de enteros que componen la imagen fue cargado correctamente
        if (!vecImagen.empty())
        {
            cout << "La imagen " << nombre << " ha sido cargada" << endl;
        }
        else
        {
            cout << "La imagen " << nombre << " no ha podido ser cargada" << endl;
        }
    }
}
string Imagen::getNombre()
{
    return nombre;
}

string Imagen::getFormato()
{
    return formato;
}

int Imagen::getMaxClaro()
{
    return maxClaro;
}

/************
 * @brief Guarda la imagen en formato PGM en una ruta especificada.
 * @param ruta Ruta donde se guardará el archivo.
 * Escribe los datos de la imagen en el archivo de salida en formato PGM.
 ************/
void Imagen::guardarComoPGM(string &ruta)
{
    ofstream archivo;
    archivo.open(ruta);

    if (archivo.is_open())
    {
        // Escribir el encabezado del archivo PGM
        archivo << getFormato() << "\n";
        archivo << getDimensionX() << " " << getDimensionY() << "\n";
        archivo << getMaxClaro() << "\n";

        // Escribir los píxeles, asegurando un salto de línea al final de cada fila
        int dimY = getDimensionY();
        int dimX = getDimensionX();
        for (int i = 0; i < dimY; i++)
        {
            for (int j = 0; j < dimX; j++)
            {
                archivo << vecImagen[i][j];
                if (j < dimX - 1)
                {
                    archivo << " "; // Espacio entre píxeles de la misma fila
                }
            }
            archivo << "\n"; // Salto de línea al final de cada fila
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }
    archivo.close();
}

/************
 * @brief Muestra información sobre la imagen cargada.
 * Si la imagen está en memoria, muestra su nombre y dimensiones.
 ************/
void Imagen::mostrarInfo()
{
    if (vecImagen.empty())
    {
        // Si no se pudo cargar la imagen a memoria
        cout << "No hay una imagen cargada en memoria" << endl;
        return;
    }
    else
    {
        // Muestra datos de la imagen, como el nombre y las dimensiones
        cout << "Imagen cargada en memoria: " << nombre << ", ancho: " << getDimensionX() << ", alto: " << getDimensionY() << endl;
    }
}
