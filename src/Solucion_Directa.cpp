//
// Solucion_Directa.cpp
// Created by Antonio López Toboso and Mercedes López Caballero on 5/3/24.

#include <iostream>
#include <ctime>
#include <fstream>

/*
Define´s, const e includes.
*/

#define	rutaTiempos "INFORMACION DE TIEMPOS/infoTiemposDirecta.csv"
#define	rutaResultados "RESULTADOS/resultadosDirecta.txt"
#define	rutaEntrada "CASOS DE PRUEBA/casosPrueba.txt"


int main() {
	
	/*
	Flujo de informacion hacia ficheros de salida de datos.
	*/
	
	std::ifstream entrada(rutaEntrada);
	std::ofstream infoTiempos(rutaTiempos); //, std::ios::app);
	std::ofstream resultados(rutaResultados); //, std::ios::app);

	/*
	Lectura del numero de casos a tratar.
	*/
	
	int numeroCasos;
	entrada >> numeroCasos;
	
	infoTiempos << "TAMAÑO_CADENA, TIEMPO_SEG, M_(N/1000)" << std::endl;
	
	/*
	Bucle de ejecucion.
	*/
	
	while(numeroCasos){
		
		numeroCasos--;
		
		/*
		Lectura de la cadena.
		*/
		
		std::string cadenaEntrada;
		int cadMinima;
		
		entrada >> cadenaEntrada;
		entrada >> cadMinima;
		
		unsigned long longitudEntrada = cadenaEntrada.length();
		
		/*
		Ejecución de la Solucion Directa.
		Conteo de tiempos de ejecucion de dicha metodología.
		*/
		
		int arrayDiferencias[longitudEntrada-1];
		
		long double timestampInicio = (long double) clock();
				
		
		for (int i = 0; i < (longitudEntrada-1); i++){
			
			arrayDiferencias[i] = abs(cadenaEntrada[i] - cadenaEntrada[i+1]);
			
		}
		std::pair<int,int> solucion = std::pair<int,int>(-1,-1);
		for (int i=0; i<(sizeof(arrayDiferencias)/sizeof(int))-cadMinima+1; i++){
			int difMaxima = 0;
			for (int j=i; j<i+cadMinima-1; j++){
				
				difMaxima += arrayDiferencias[j];
			}
			
			if (difMaxima > solucion.second){
				solucion = std::pair<int,int>(i+1, difMaxima);
			}
			
		}
		
		long double timestampFinal = (long double) clock();
		long double timestamp = (long double) ((timestampFinal - timestampInicio)) / CLOCKS_PER_SEC;
		
		/*
		Flujo de datos hacia sus respectivos archivos.
		Generacion de 2 ficheros
		· infoTiempos.csv
		· resultados.txt
		*/
		
		infoTiempos << longitudEntrada << ",";
		infoTiempos << timestamp << ",";
		infoTiempos << cadMinima << std::endl;

		for (int caracter=0; caracter<100; caracter++){
			
			resultados << cadenaEntrada[caracter];
		}
        resultados << std::endl;
        resultados << "Posición de inicio: " << (solucion.first) << std::endl;
		resultados << "Diferencia máxima: " << (solucion.second) << std::endl;

	}
	
	entrada.close();
	infoTiempos.close();
	resultados.close();
}