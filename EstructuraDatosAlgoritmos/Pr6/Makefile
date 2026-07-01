###################################################
# Plantilla para makefile
# Se debe revisar para ver si se debe adaptar a
# la instalación de cada estudiante.
# Revisar especialmente las carpetas donde Se
# ubican los programas.
###################################################
# Creado por Jesus Albert, Universitat de Valencia
# Revisado Octubre 2024
###################################################

#
# 'make'        construye el archivo ejecutable en la carpeta 'bin'
# 'make clean-all'  elimina todos los ficheros .o y el ejecutable
# 'make clean'  elimina todos los ficheros .o, pero mantiene el ejecutable
# 'make run'  ejecuta la aplicacion
# 'make doxygen'  genera la doucmentacion Doxygen del proyecto
#

# 1: Definicion de variables
###################################################

# Nombre del archivo binario con la aplicacion final
# SUSTITUIR por el nombre que se le quiera dar a la aplicacion
EXEC = main.exe

# Ubicacion del ejecutable de Doxygen para generar documentacion
# SUSTITUIR  por lo que corresponda en cada instalacion particular
DOXYGEN = C:\Program Files\doxygen\bin\doxygen.exe

# CONFIGURACIÓN DE CARPETAS A UTILIZAR

# Especificar la carpeta con los fuentes, por defecto 'src'
SRC = src

# Especificar la carpeta con cabeceras, por defecto 'include'
INCLUDE = include

# Especificar la carpeta para archivos binarios (salida), por defecto 'bin'
BIN = bin

# Librerias no estandar a considerar en el proceso de enlazado (linking)
# Modificar el valor LIB si se quiere usar alguna libreria especifica (no estandar)
# O bien, incluir las librerias a utilizar en la carpeta indicada
# Por defecto carpeta 'lib'
LIBS = lib

# Especificar la carpeta para documentacion del proyecto, por defecto 'doc'
# y el archivo con la configuración de Doxygen, por defecto 'doc/configDoxygen.cfg'
DOC = doc
DOCONF = $(DOC)/configDoxygen.cfg

# CONFIGURACIÓN DE LA COMPILACIÓN

# Compilador de C++ a utilizar
CXX = g++

# Opciones de compilacion de los archivos
# Añadir opciones de compilacion si fuera necesario
# Por defecto C++17 (-std=c++14), todos los avisos de warnings (Wall) y depuración activada (-g)
CXXFLAGS = -std=c++17 -Wall -g

# OTRA CONFIGURACION

# Establecer los archivos fuentes a compilar, todos los de la carpeta SRC
SOURCES = $(wildcard $(patsubst %,%/*.cpp, $(SRC)))

# Establecer los objetos a generar, todos los correspondientes a los fuentes
# pero en la carpeta BIN
OBJS = $(patsubst $(SRC)/%,$(BIN)/%,$(SOURCES:%.cpp=%.o))

# Establecer ruta para el ejecutable de salida
BINEXEC = $(BIN)/$(EXEC)

# Establecer órdenes de borrado y creacion de carpetas
RM = rm -f -v
MD = mkdir -p

# 2: Definicion de reglas de compilacion
###################################################

all: $(BIN) $(EXEC)
	@echo Ejecucion 'all' finalizada

# Crear carpeta de salida, si no esta creada
$(BIN):
	$(MD) $(BIN)

# Generar ejecutable a partir de los objetos
$(EXEC): $(OBJS) 
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -L$(LIBS) $(OBJS) -o $(BINEXEC)

# Regla para generar cualquier archivo objeto, ya que todos se compilan igual
# %< referencia a la primera dependencia (.cpp) y %@ al archivo objetivo (.o)
# Cada objeto de BIN depende de un fuente con el mismo nombre en SRC
$(BIN)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $< -o $@

# Otras reglas de gestion, no compilacion

.PHONY: clean clean-all run doxygen

# Regla de borrado de archivos objetos (mantiene el ejecutable): make clean
clean:
	${RM} $(OBJS)
	@echo Ejecucion 'clean' finalizada

# Regla de borrado de todos los archivos generados (incluido ejecutable): make clean-all
clean-all:
	${RM} $(OBJS) $(BINEXEC)
	@echo Ejecucion 'clean-all' finalizada

# Ejecutar aplicacion
run: 
	@echo $(BINEXEC)
	./$(BINEXEC)
	@echo Ejecucion 'run' finalizada

# Generar la documentacion del proyecto con Doxygen
# Utiliza el archivo de configuracion 'configDoxygen.cfg'
# que debe estar ubicado en la carpeta 'doc'
doxygen:
	$(DOXYGEN) $(DOCONF)
	@echo Ejecucion 'doxygen' finalizada
