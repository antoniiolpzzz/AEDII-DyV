# MAKEFILE
# Creado por Antonio López Toboso y Mercedes López Caballero el 20/3/24.

# Ejecución: Divide_Y_Venceras Solucion_Directa casosPrueba.txt
#	./COMPILADO/DivideyVenceras
#	./COMPILADO/SolucionDirecta

# Variables
SRC_DIR := src
BIN_DIR := COMPILADO

# Objetivos por defecto
all: $(BIN_DIR)/DivideyVenceras $(BIN_DIR)/SolucionDirecta $(BIN_DIR)/GeneradorDeCasos $(BIN_DIR)/GeneradorDeCasosIncremental
	rm -f $(BIN_DIR)/*.o
	
# Compilación de Divide_Y_Venceras
$(BIN_DIR)/DivideyVenceras: $(SRC_DIR)/main.cpp $(SRC_DIR)/Divide_Y_Venceras.cpp $(SRC_DIR)/Divide_Y_Venceras.h | Creacion_Directorios
	g++ -c $(SRC_DIR)/main.cpp -o $(BIN_DIR)/main.o
	g++ -c $(SRC_DIR)/Divide_Y_Venceras.cpp -o $(BIN_DIR)/Divide_Y_Venceras.o
	g++ $(BIN_DIR)/main.o $(BIN_DIR)/Divide_Y_Venceras.o -o $@
	

# Compilación de Solucion_Directa
$(BIN_DIR)/SolucionDirecta: $(SRC_DIR)/Solucion_Directa.cpp | Creacion_Directorios
	g++ -c $< -o $(BIN_DIR)/Solucion_Directa.o
	g++ $(BIN_DIR)/Solucion_Directa.o -o $@

# Compilación del Generador_De_Casos
$(BIN_DIR)/GeneradorDeCasos: $(SRC_DIR)/Generador_De_Casos.cpp | Creacion_Directorios
	g++ -c $< -o $(BIN_DIR)/Generador_De_Casos.o
	g++ $(BIN_DIR)/Generador_De_Casos.o -o $@

# Compilación del Generador_De_Casos_Incremental
$(BIN_DIR)/GeneradorDeCasosIncremental: $(SRC_DIR)/Generador_De_Casos_Incremental.cpp | Creacion_Directorios
	g++ -c $< -o $(BIN_DIR)/Generador_De_Casos_Incremental.o
	g++ $(BIN_DIR)/Generador_De_Casos_Incremental.o -o $@

# Creacion de directorios necesarios
Creacion_Directorios:
	@mkdir -p $(BIN_DIR)
	@mkdir -p "RESULTADOS"
	@mkdir -p "INFORMACION DE TIEMPOS"
	@mkdir -p "CASOS DE PRUEBA"
