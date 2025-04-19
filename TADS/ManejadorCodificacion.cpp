#include "ManejadorCodificacion.h"
#include "Arbol.h"
#include <vector>
#include <utility>
#include <fstream>



using namespace std;


Manejador::Manejador(){
    imagen = Imagen();
    arbol = Arbol();
    codificacion.resize(0);
}


/**
 * @brief Getters y setters
 * 
 * @return Imagen 
 */


Imagen Manejador::getImagen(){
    return imagen;
}

void Manejador::setImagen(Imagen img){
    imagen = img;
}

vector<bool> Manejador::getCodificacion(){
    return codificacion;
}

void Manejador::setCodificacion(vector<bool> cod){
    codificacion = cod;
}

Arbol Manejador::getArbol(){
    return arbol;
}

void Manejador::setArbol(Arbol arb){
     arbol = arb;
}

void Manejador::imprimirDatos(){
    vector<pair<int,int>> prueba = imagen.codificacion();
    for(auto p: prueba){
        cout<<"Para el "<<p.first<<" hay "<<p.second<<endl;
    }
    arbol = Arbol(calcularNiveles(prueba));
    
}

int Manejador::calcularNiveles(vector<pair<int,int>> frecuencias){
    vector<int> potencias(10);
    potencias[0] = 1;
    potencias[1] = 2;
    for(int i = 2; i<10; i++){
        potencias[i] = potencias[i-1]*2;
    }
    int tamano = frecuencias.size();
    for(int i = 0; i<potencias.size(); i++){
        if(tamano <= potencias[i]){
            return potencias[i];
        }
    }
    return -1;
}

void Manejador::cargarDesdeHUF(string ruta){
    fstream archivo(ruta, ios::binary);
    string datos;
    getline(archivo,datos);
    


}

void Manejador::cargarDesdePGM(string ruta){
    imprimirDatos();
    ofstream archivo(ruta, ios::binary | ios::out);
    archivo.write(imagen.getFormato().c_str(),imagen.getFormato().size());
}