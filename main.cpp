/********************************************************************************* 
-Nombres: Gabriel Jaramillo, Salomon Avila, Tomas Silva, Juan Pabon, Angel Morales
-Pontificia Universidad Javeriana
-Proyecto de Estructuras de Datos; Entrega 1
-Temas: TADs, Compilacion Modular, Contenedores, Estructuras Lineales
*********************************************************************************/
#include <bits/stdc++.h>
#include "TADS/Imagen.h"
#include "TADS/VolumenImagenes.h"
#include "Utils/Menu.h"

using namespace std;

int main(){
    // Instancia de una imagen individual
    Imagen imagen;
    Imagen codificador;
    
    // Instancia de un volumen de imágenes
    VolumenImagenes volumen;

    // Mensaje de bienvenida
    cout << "Bienvenido al sistema de manejo de imágenes de la Pontificia Universidad Javeriana" << endl;
    
    string opt;
    while (true){
        // Mostrar menú de opciones al usuario
        menu();
        
        // Leer la opción ingresada por el usuario
        getline(cin, opt);
        
        // Convertir la opción en un flujo de cadena para su procesamiento
        stringstream ss;
        ss << opt;
        
        // Vector para almacenar los argumentos ingresados
        vector<string> argumentos;
        while(ss){
            string temp;
            ss >> temp;
            argumentos.push_back(temp);
        }
        
        // Eliminar el último elemento vacío generado por el flujo de cadena
        argumentos.pop_back();
        
        // Verificar que haya al menos un argumento ingresado
        if(argumentos.size() > 0){
            // Comando para cargar una imagen desde un archivo PGM
            if(argumentos[0] == "cargar_imagen" && argumentos.size() == 2){
                string tmp = argumentos[1];
                imagen.cargarDesdePGM(tmp);
            }
            // Comando para cargar un volumen de imágenes desde archivos
            else if(argumentos[0] == "cargar_volumen" && argumentos.size() == 3){
                volumen.cargarDesdeArchivos(argumentos[1], stoi(argumentos[2]));
            }
            // Comando para mostrar información de la imagen cargada
            else if(argumentos[0] == "info_imagen" && argumentos.size() == 1){
                imagen.mostrarInfo();
            }
            // Comando para mostrar información del volumen de imágenes cargado
            else if(argumentos[0] == "info_volumen" && argumentos.size() == 1){
                volumen.mostrarInfo();
            }
            // Comando para generar una proyección 2D de un volumen de imágenes
            else if(argumentos[0] == "proyeccion2D" && argumentos.size() == 4){
                volumen.generarProyeccion2D(argumentos[1], argumentos[2], argumentos[3]);
            }
            // Comando para salir del programa
            else if(argumentos[0] == "salir" && argumentos.size() == 1){
                cout << "Hasta luego" << endl;
                return 0;
            }else if(argumentos[0] == "codificar_imagen" && argumentos.size() == 2){
                codificador.codificacion(argumentos[1]);
            }
            // Mensaje de error en caso de ingresar un comando incorrecto
            else{
                cout << "Comando incorrecto" << endl;
            }
        }
    }

    return 0;
}