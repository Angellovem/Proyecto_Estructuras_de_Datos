# Nombre del ejecutable
EXEC = bin/programa

# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++17 -I TADS/ -I Utils/

# Detectar sistema operativo
OS := $(shell uname 2>/dev/null || echo Windows)
ifeq ($(OS),Windows)
    MKDIR = mkdir
    RMDIR = rmdir /S /Q
    RM = del /Q
else
    MKDIR = mkdir -p
    RMDIR = rm -rf
    RM = rm -f
endif

# Archivos fuente
SRCS = main.cpp TADS/VolumenImagenes.cpp TADS/Imagen.cpp Utils/Menu.cpp TADS/Arbol.cpp TADS/Nodo.cpp TADS/ManejadorCodificacion.cpp TADS/Grafo.cpp

# Archivos objeto
OBJS = bin/main.o bin/TADS/VolumenImagenes.o bin/TADS/Imagen.o bin/Utils/Menu.o bin/TADS/Arbol.o bin/TADS/Nodo.o bin/TADS/ManejadorCodificacion.o bin/TADS/Grafo.o

# Regla principal: compilar el ejecutable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Regla para compilar archivos .cpp a .o en bin/
bin/main.o: main.cpp | bin
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/TADS/VolumenImagenes.o: TADS/VolumenImagenes.cpp | bin/TADS
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/TADS/Imagen.o: TADS/Imagen.cpp | bin/TADS
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/Utils/Menu.o: Utils/Menu.cpp | bin/Utils
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/TADS/Arbol.o: TADS/Arbol.cpp | bin/TADS
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/TADS/Nodo.o: TADS/Nodo.cpp | bin/TADS
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/TADS/ManejadorCodificacion.o: TADS/ManejadorCodificacion.cpp | bin/TADS
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/TADS/Grafo.o: TADS/Grafo.cpp | bin/TADS
	$(CXX) $(CXXFLAGS) -c $< -o $@
# Crear carpetas necesarias
bin:
	$(MKDIR) bin

bin/TADS:
	$(MKDIR) bin/TADS

bin/Utils:
	$(MKDIR) bin/Utils

# Limpiar archivos compilados
clean:
	$(RMDIR) bin
	$(RM) $(EXEC)
	clear
	

# Ejecutar el programa
run: $(EXEC)
	./$(EXEC)
