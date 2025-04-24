# Integrantes

[Salomon Avila](https://github.com/MrMich34)

[Tomas Silva](https://github.com/Tomas-SilvaC)

[Gabriel Jaramillo](https://github.com/GabrielJaramilloCuberos)

[Juan Pabon](https://github.com/JohnWilliams2050)

[Angel Morales](https://github.com/Angellovem)


## Installation

Al usar makefile se compila de la siguiente manera

```bash
make clean

make run
```
## Usage

Por la estructura del codigo consta de 4 comandos importantes

Cargar imagen
```bash
cargar_imagen img_02.pgm
```
Informacion de la imagen
```bash
info_imagen
```
Cargar Volumen
```bash
cargar_volumen slice_ 19
```
Informacion Volumen
```bash
info_volumen
```

Proyeccion en x
```bash
proyeccion2D x promedio imagenFinalPromedioX.pgm
proyeccion2D x minimo imagenFinalMinimoX.pgm
proyeccion2D x maximo imagenFinalMaximoX.pgm
proyeccion2D x mediana imagenFinalMedianaX.pgm
```

Proyeccion en y
```bash
proyeccion2D y promedio imagenFinalPromedioY.pgm
proyeccion2D y minimo imagenFinalMinimoY.pgm
proyeccion2D y maximo imagenFinalMaximoY.pgm
proyeccion2D y mediana imagenFinalMedianaY.pgm
```

Proyeccion en z
```bash
proyeccion2D z promedio imagenFinalPromedioZ.pgm
proyeccion2D z minimo imagenFinalMinimoZ.pgm
proyeccion2D z maximo imagenFinalMaximoZ.pgm
proyeccion2D z mediana imagenFinalMedianaZ.pgm
```


## Entrega

Esta entrega corresponde a la entrega 2 del proyecto de Estructuras de datos

## Aclaraciones
En el lenguaje de programación de c++, el tipo de dato primitivo *bool* utiliza un byte _(8 bits)_ para su implementacion ([Fuente](https://learn.microsoft.com/en-us/cpp/cpp/fundamental-types-cpp?view=msvc-170#sizes-of-built-in-types)).

Una posible solucion para guardar bits individualmente es mediante el uso de un [bitset](https://cplusplus.com/reference/bitset/bitset/), sin embargo este unicamente funciona referente a un tamaño fijo, o en otras palabras, no es un contenedor dinamico.

Para dar una solucion definitiva se uso una especializacion del contenedor [vector](https://cplusplus.com/reference/vector/vector/). Esta especializacion es referente al uso de un vector de datos booleanos, la cual no guarda un tipo booleano de un byte directamente, por el contrario, es capaz de almacenar bits individualmente. La documentacion de la especializacion se puede encontrar en el siguiente [enlace](https://cplusplus.com/reference/vector/vector-bool/).

Para la [cola de prioridad personalizada](https://www.geeksforgeeks.org/custom-comparator-in-priority_queue-in-cpp-stl/) se usan distintos elementos.
Elegimos como tipo de dato un apuntador de tipo Nodo, como contenedor un vector del mismo
tipo y por ultimo el comparador es el personalizado creado en la misma implementacion del Arbol.
Posterior al nombre se vuelve a incluir el comparador para generar su instancia.