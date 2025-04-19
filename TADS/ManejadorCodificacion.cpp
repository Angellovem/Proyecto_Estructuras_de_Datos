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

vector<pair<int,int>> Manejador::getFrecuencias(){
    return frecuencias;
}

void Manejador::setFrecuencias(vector<pair<int,int>> frec){
    frecuencias = frec;
}

Arbol Manejador::getArbol(){
    return arbol;
}

void Manejador::setArbol(Arbol arb){
     arbol = arb;
}

void Manejador::codificar(){
    vector<pair<int,int>> prueba = imagen.codificacion();
    /*for(auto p: prueba){
        cout<<"Para el "<<p.first<<" hay "<<p.second<<endl;
    }*/
    
    setFrecuencias(prueba);
    cout<<"Se establecieron las frecuencias"<<endl;
    arbol.crearArbol(getFrecuencias());
    cout<<"Se creo el arbol correctamente"<<endl;
    vector<bool> auxiliar;

    arbol.completarValores(auxiliar, arbol.getRaiz());
    cout<<"se completan los valores para el mapa"<<endl;
    numeroAbinario();
    cout<<"se convierte de numero a binario"<<endl;
}


void Manejador::cargarDesdeHUF(string ruta){
    fstream archivo(ruta, ios::binary);
    string datos;
    getline(archivo,datos);

}

void Manejador::cargarDesdePGM(string ruta){
    codificar();
    cout<<endl;
    string espacio = " ";
    ofstream archivo(ruta, ios::binary | ios::out);
    archivo.write(to_string(imagen.getDimensionX()).c_str(),to_string(imagen.getDimensionX()).size());
    archivo.write(espacio.c_str(),espacio.size());
    archivo.write(to_string(imagen.getDimensionY()).c_str(),to_string(imagen.getDimensionY()).size());
    archivo.write(espacio.c_str(),espacio.size());
        


}


void Manejador::numeroAbinario(){
    map<int,vector<bool>> valores = arbol.getValores();
    cout<<"el mapa tiene "<<valores.size()<<" valores"<<endl;
    for(auto filas : imagen.getVecImagen()){
        for (auto columna : filas){
            cout<<"El valor binario de "<<columna<<" es: ";
            for(auto b : valores[columna]){
                cout<<b;
            }
            cout<<endl;
            vector<bool> resultado = valores[columna];
            for(auto b : resultado){
                codificacion.push_back(b);
            }
        }
    }
}