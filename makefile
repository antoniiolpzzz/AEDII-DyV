#
# MAKEFILE
# Created by Antonio López Toboso and Mercedes López Caballero on 20/3/24.

#Ejecucion: Divide_Y_Venceras Solucion_Directa casosPrueba.txt
#	./COMPILADO/DivideyVenceras
#	./COMPILADO/SolucionDirecta
	

#casosPrueba.txt: Generador_De_Casos Divide_Y_Venceras Solucion_Directa Creacion_Directorios
#	./COMPILADO/GeneradorDeCasos

all: Divide_Y_Venceras Solucion_Directa Generador_De_Casos Generador_De_Casos_Incremental
	
	
Divide_Y_Venceras: Creacion_Directorios src/main.cpp src/Divide_Y_Venceras.cpp src/Divide_Y_Venceras.h
	g++ src/main.cpp src/Divide_Y_Venceras.cpp -o COMPILADO/DivideyVenceras
	
Solucion_Directa: Creacion_Directorios
	g++ src/Solucion_Directa.cpp -o COMPILADO/SolucionDirecta
	
Generador_De_Casos: Creacion_Directorios
	g++ src/Generador_De_Casos.cpp -o COMPILADO/GeneradorDeCasos
	
Generador_De_Casos_Incremental: Creacion_Directorios
	g++ src/Generador_De_Casos_Incremental.cpp -o COMPILADO/GeneradorDeCasosIncremental
	
Creacion_Directorios:
	@mkdir -p "COMPILADO"
	@mkdir -p "RESULTADOS"
	@mkdir -p "INFORMACION DE TIEMPOS"
	@mkdir -p "CASOS DE PRUEBA"
	
#clean:
#	rm -f COMPILADO/DivideyVenceras
#	rm -f COMPILADO/GeneradorDeCasos
#	rm -f COMPILADO/SolucionDirecta

	