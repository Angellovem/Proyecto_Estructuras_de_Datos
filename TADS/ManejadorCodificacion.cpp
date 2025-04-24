/*********************************************************************************
-Nombres: Gabriel Jaramillo, Salomon Avila, Tomas Silva, Juan Pabon, Angel Morales
-Pontificia Universidad Javeriana
-Proyecto de Estructuras de Datos; Entrega 2
-Temas: TADs, Compilacion Modular, Contenedores, Estructuras Lineales
*********************************************************************************/
#include "ManejadorCodificacion.h"
#include "Arbol.h"
#include <vector>
#include <utility>
#include <fstream>

using namespace std;
/**
 * @brief Constructor por defecto del manejador
 * 
 */
Manejador::Manejador()
{
    imagen = Imagen();
    arbol = Arbol();
    codificacion.resize(0);
}

/**
 * @brief Getters y setters de los atributos de la clase
 *
 * @return Imagen
 */
Imagen Manejador::getImagen()
{
    return imagen;
}

void Manejador::setImagen(Imagen img)
{
    imagen = img;
}

vector<bool> Manejador::getCodificacion()
{
    return codificacion;
}

void Manejador::setCodificacion(vector<bool> cod)
{
    codificacion = cod;
}

vector<pair<int, int>> Manejador::getFrecuencias()
{
    return frecuencias;
}

void Manejador::setFrecuencias(vector<pair<int, int>> frec)
{
    frecuencias = frec;
}

Arbol Manejador::getArbol()
{
    return arbol;
}

void Manejador::setArbol(Arbol arb)
{
    arbol = arb;
}

/**
 * @brief Se utilizan metodos de distintas clases con el fin de generar una codificacion
 * completa sobre una imagen
 * 
 */
void Manejador::codificar()
{
    vector<pair<int, int>> prueba = imagen.codificacion();
    /*for(auto p: prueba){
        cout<<"Para el "<<p.first<<" hay "<<p.second<<endl;
    }*/

    setFrecuencias(prueba);
    // cout<<"Se establecieron las frecuencias"<<endl;
    arbol.crearArbol(getFrecuencias());
    // cout<<"Se creo el arbol correctamente"<<endl;
    vector<bool> auxiliar;

    arbol.completarValores(auxiliar, arbol.getRaiz());
    // cout<<"se completan los valores para el mapa"<<endl;
    numeroAbinario();
    // cout<<"se convierte de numero a binario"<<endl;
}

/**
 * @brief Se reciben dos rutas, la primera donde se encuentra ubicado
 * el archivo binario, y la otra donde se creara la imagen
 * Se lee el contenido del archivo binario y se realizan las operaciones necesarias
 * tales como asignar valores de tamaño y tipo a la imagen, las frecuencias, entre otras.
 * @param rutaHUF 
 * @param rutaPGM 
 */
void Manejador::cargarDesdeHUF(string rutaHUF, string rutaPGM)
{
    ifstream archivo(rutaHUF, ios::binary | ios::in);

    if (!archivo)
    {
        cout << "El archivo " << rutaHUF << " no ha podido ser decodificado.\n";
        return;
    }

    int x, y, maxClaro;
    archivo.read(reinterpret_cast<char *>(&x), sizeof(x));
    archivo.read(reinterpret_cast<char *>(&y), sizeof(y));
    archivo.read(reinterpret_cast<char *>(&maxClaro), sizeof(maxClaro));

    imagen.setDimensionX(x);
    imagen.setDimensionY(y);
    imagen.setMaxClaro(maxClaro);

    int cantidad;
    archivo.read(reinterpret_cast<char *>(&cantidad), sizeof(cantidad));

    frecuencias.clear();
    for (int i = 0; i < cantidad; i++)
    {
        int valor, frec;
        archivo.read(reinterpret_cast<char *>(&valor), sizeof(valor));
        archivo.read(reinterpret_cast<char *>(&frec), sizeof(frec));
        frecuencias.push_back({valor, frec});
    }

    int totalBits;
    archivo.read(reinterpret_cast<char *>(&totalBits), sizeof(totalBits));

    vector<bool> codificacionLeida;
    int bitsLeidos = 0;

    while (bitsLeidos < totalBits)
    {
        uint8_t byte;
        archivo.read(reinterpret_cast<char *>(&byte), sizeof(byte));
        for (int i = 7; i >= 0 && bitsLeidos < totalBits; --i)
        {
            bool bit = (byte >> i) & 1;
            codificacionLeida.push_back(bit);
            bitsLeidos++;
        }
    }

    codificacion = codificacionLeida;

    archivo.close();
    vector<vector<int>> matriz;
    vector<int> filaActual;
    arbol.crearArbol(frecuencias);
    Nodo *actual = arbol.getRaiz();

    x = imagen.getDimensionX();
    y = imagen.getDimensionY();

    int contador = 0;

    for (bool bit : codificacion)
    {
        if (bit)
        {
            actual = actual->getNodoDerecha();
        }
        else
        {
            actual = actual->getNodoIzquierda();
        }

        if (actual->getEsHoja())
        {
            filaActual.push_back(actual->getValor());
            actual = arbol.getRaiz();
            contador++;

            if (filaActual.size() == x)
            {
                matriz.push_back(filaActual);
                filaActual.clear();
            }

            if (contador == x * y)
            {
                break;
            }
        }
    }
    string formato = "P2";
    imagen.setFormato(formato);
    imagen.setVecImagen(matriz);
    imagen.guardarComoPGM(rutaPGM);
}
/**
 * @brief Rellena el vector de booleanos con la codificacion correspondiente
 * usando el arbol de Huffman
 * 
 */
void Manejador::numeroAbinario()
{
    map<int, vector<bool>> valores = arbol.getValores();
    //cout << "el mapa tiene " << valores.size() << " valores" << endl;
    for (auto filas : imagen.getVecImagen())
    {
        for (auto columna : filas)
        {
            //cout << "El valor binario de " << columna << " es: ";
            /*for (auto b : valores[columna])
            {
                cout << b;
            }
            cout << endl;*/
            vector<bool> resultado = valores[columna];
            for (auto b : resultado)
            {
                codificacion.push_back(b);
            }
        }
    }
}

/**
 * @brief Recibe la ruta del archivo donde se generará el binario
 * Codifica la imagen que se encuentre en memoria y rellena el archivo en cuestion.
 * 
 * @param ruta 
 */
void Manejador::cargarDesdePGM(string ruta)
{
    if (imagen.getMaxClaro() == 0)
    {
        cout << "No hay una imagen cargada en memoria.\n";
        return;
    }
    codificar();
    ofstream archivo(ruta, ios::binary | ios::out);
    int x = imagen.getDimensionX();
    int y = imagen.getDimensionY();
    int maxClaro = imagen.getMaxClaro();
    archivo.write(reinterpret_cast<char *>(&x), sizeof(x));
    archivo.write(reinterpret_cast<char *>(&y), sizeof(y));
    archivo.write(reinterpret_cast<char *>(&maxClaro), sizeof(maxClaro));
    int cantidad = frecuencias.size();
    archivo.write(reinterpret_cast<char *>(&cantidad), sizeof(cantidad));
    for (auto p : frecuencias)
    {
        int valor = p.first;
        int frec = p.second;
        archivo.write(reinterpret_cast<char *>(&valor), sizeof(valor));
        archivo.write(reinterpret_cast<char *>(&frec), sizeof(frec));
    }
    vector<uint8_t> empaquetado;
    uint8_t byteActual = 0;
    int contadorBits = 0;

    for (bool bit : codificacion)
    {
        byteActual = (byteActual << 1) | (bit ? 1 : 0);
        contadorBits++;

        if (contadorBits == 8)
        {
            empaquetado.push_back(byteActual);
            byteActual = 0;
            contadorBits = 0;
        }
    }

    if (contadorBits > 0)
    {
        byteActual <<= (8 - contadorBits);
        empaquetado.push_back(byteActual);
    }

    int totalBits = codificacion.size();
    archivo.write(reinterpret_cast<char *>(&totalBits), sizeof(totalBits));

    for (uint8_t b : empaquetado)
    {
        archivo.write(reinterpret_cast<char *>(&b), sizeof(b));
    }

    archivo.close();
    cout << " La imagen en memoria ha sido codificada exitosamente y almacenada en el archivo " << ruta << ".\n";
}
