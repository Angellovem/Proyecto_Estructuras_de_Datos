/*********************************************************************************
-Nombres: Gabriel Jaramillo, Salomon Avila, Tomas Silva, Juan Pabon, Angel Morales
-Pontificia Universidad Javeriana
-Proyecto de Estructuras de Datos; Entrega 3
-Temas: TADs, Compilacion Modular, Contenedores, Estructuras Lineales, Estructuras no lineales
*********************************************************************************/

#include "Grafo.h"

using namespace std;

Grafo::Grafo(){}

Grafo::~Grafo(){}

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
/**
 * @brief Inicializa el grafo teniendo en cuenta
 * el tamaño de la imagen
 * 
 */
void Grafo::inicializarGrafo()
{
    vector<vector<pair<int, int>>> nuevoGrafo((imagen.getDimensionX() * imagen.getDimensionY()) + 1);
    grafo = nuevoGrafo;
    vector<vector<int>> valores = imagen.getVecImagen();
        cout << "Dimensiones esperadas: " << imagen.getDimensionY() << " x " << imagen.getDimensionX() << endl;
    cout << "Dimensiones reales: " << valores.size();
    if (!valores.empty())
        cout << " x " << valores[0].size() << endl;
    for (int y = 0; y < imagen.getDimensionY(); y++)
    {
        for (int x = 0; x < imagen.getDimensionX(); x++)
        {
            int actual_id = (y * imagen.getDimensionX()) + x;
            int valor_actual = valores[y][x];

            if (y > 0)
            {
                int vecino_id = (y - 1) * imagen.getDimensionX() + x;
                int peso = abs(valor_actual - valores[y - 1][x]);
                //cout << "el peso es: " << peso << "y revisar el id " << actual_id << " con su vecino " << vecino_id << " este es el 1" << endl;
                grafo[actual_id].push_back({vecino_id, peso});
            }
            if (y < imagen.getDimensionY() - 1)
            {
                int vecino_id = (y + 1) * imagen.getDimensionX() + x;
                int peso = abs(valor_actual - valores[y + 1][x]);
                //cout << "el peso es: " << peso << "y revisar el id " << actual_id << " con su vecino " << vecino_id << " este es el 2" << endl;
                grafo[actual_id].push_back({vecino_id, peso});
            }
            if (x > 0)
            {
                int vecino_id = y * imagen.getDimensionX() + (x - 1);
                int peso = abs(valor_actual - valores[y][x - 1]);
                //cout << "el peso es: " << peso << "y revisar el id " << actual_id << " con su vecino " << vecino_id << " este es el 3" << endl;
                grafo[actual_id].push_back({vecino_id, peso});
            }
            if (x < imagen.getDimensionX() - 1)
            {
                int vecino_id = y * imagen.getDimensionX() + (x + 1);
                //cout << "se calcula el id vecino" << endl;
                int peso = abs(valor_actual - valores[y][x + 1]);
                //cout << "se calcula el peso" << endl;
                //cout << "el peso es: " << peso << "y revisar el id " << actual_id << " con su vecino " << vecino_id << " este es el 4" << endl;
                grafo[actual_id].push_back({vecino_id, peso});
            }
        }
    }
    cout<<"terminado"<<endl;
}

/**
 * @brief Se inicializa la matriz de distancias necesarias para nuestro Dijkstra
 * 
 */
void Grafo::inicializarDistancias()
{
    int max = INT_MAX;
    pair<int, int> valorPorDefecto = {max, 0};
    for (int i = 0; i < imagen.getDimensionY(); i++)
    {
        distancias.push_back(vector<pair<int, int>>());
        for (int j = 0; j < imagen.getDimensionX(); j++)
        {
            distancias[i].push_back(valorPorDefecto);
        }
    }
}

/**
 * @brief Funcion auxiliar que en caso de ser necesaria
 * imprime la lista de adyacencia de cada uno de los nodos
 * 
 */
void Grafo::imprimirGrafo()
{
    fstream archivo;
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

/**
 * @brief Se calcula la posicion en la lista de adyacencia de determinadas coordenadas
 * Nunca se repiten los valores por la forma que este se calcula
 * se multiplica Y por la cantidad de columnas de la imagen y se le adiciona X
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int Grafo::calcularId(int x, int y)
{
    return ((y * imagen.getDimensionX()) + x);
}

/**
 * @brief Proceso inverso a la funcion de calcularID, usando dos cordenaadas genera
 * la posicion en la lista de adyacencia
 * 
 * @param id 
 * @return pair<int, int> 
 */
pair<int, int> Grafo::calcularCordenadas(int id)
{
    pair<int, int> res;
    int y = id / imagen.getDimensionX();
    int x = id % imagen.getDimensionX();
    res = {x, y};
    return res;
}

/**
 * @brief FUncion principal donde se segmenta una imagen en regiones usando las semillas
 * 
 * @param nombre 
 * @param semillas 
 */
void Grafo::segmentarImagen(string nombre, vector<tuple<int, int, int>> semillas)
{   
    //Valor maximo de intensidad
    int etiquetaMaxima = 0;
    //Por cada una de las semillas se hace una operacion definida
    for (int i = 0; i < semillas.size(); i++)
    {
        //Se extraen los datos de la semilla
        cout<<"La semilla "<<i<<" es: ";
        tuple<int, int, int> tupla = semillas[i];
        int corX = get<0>(tupla);
        cout<<"X: "<<corX;
        int corY = get<1>(tupla);
        cout<<" Y: "<<corY;
        int etiqueta = get<2>(tupla);
        if(etiqueta > etiquetaMaxima){
            etiquetaMaxima = etiqueta;
        }
        cout<<" L: "<<etiqueta<<endl;
        //Se calcula la posicion de la semilla
        int posicion = calcularId(corX, corY);
        distancias[corY][corX] = {0, etiqueta};
        //Para tener un Dijkstra eficiente, usamos una cola de prioridad
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        //Para poder implementarlo debemos tener un arreglo de visitados, esto con el fin
        //de no repetir el nodo
        vector<bool> visitado((imagen.getDimensionX() * imagen.getDimensionY()), false);
        int id = calcularId(corX, corY);
        q.push({0, id});
        //Mientras la cola no esté vacia (Mientras no se hayan recorrido todos los nodos)
        while (!q.empty())
        {
            //Lo marcamos como visitado si no lo está
            int a = q.top().second;
            q.pop();
            if (visitado[a])
                continue;
            visitado[a] = true;
            //Por cada uno de los elementos de la lista de adyacencia de ese nodo
            for (auto u : grafo[a])
            {
                //calculamos la distancia que existe y en caso de ser necesario la actualizamos
                int b = u.first, w = u.second;
                pair<int, int> auxiliar = calcularCordenadas(a);
                int temX, temY;
                temX = auxiliar.first;
                temY = auxiliar.second;
                pair<int, int> auxiliar2 = calcularCordenadas(b);
                int temX2, temY2;
                temX2 = auxiliar2.first;
                temY2 = auxiliar2.second;
                if (distancias[temY][temX].first + w < distancias[temY2][temX2].first)
                {
                    distancias[temY2][temX2].first = distancias[temY][temX].first + w;
                    distancias[temY2][temX2].second = etiqueta;
                    q.push({distancias[temY2][temX2].first, b});
                }
            }
        }
    }
    //Cada imagen tiene un vector de frecuencias
    //Lo que haremos es usar las etiquetas para generar una nueva imagen
    vector<vector<int>> nuevasFrecuencias(imagen.getDimensionY(), vector<int>(imagen.getDimensionX()));
    for (int i = 0; i < imagen.getDimensionY(); i++)
    {
        for (int j = 0; j < imagen.getDimensionX(); j++)
        {
            nuevasFrecuencias[i][j] = distancias[i][j].second;
        }
    }
    //Asignamos los valores correspondientes de una imagen en formato PGM
    imagenSegmentada.setDimensionX(imagen.getDimensionX());
    imagenSegmentada.setDimensionY(imagen.getDimensionY());
    string formato = "P2";
    imagenSegmentada.setFormato(formato);
    imagenSegmentada.setNombre(nombre);
    imagenSegmentada.setMaxClaro(etiquetaMaxima);
    imagenSegmentada.setVecImagen(nuevasFrecuencias);
    imagenSegmentada.guardarComoPGM(nombre);
}