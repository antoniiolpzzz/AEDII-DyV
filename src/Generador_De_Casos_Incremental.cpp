//
// Generador_De_Casos_Incremental.cpp
// Created by Antonio López Toboso and Mercedes López Caballero on /3/24.

#include <iostream>
#include <random>
#include <string>
#include <fstream>

using namespace std;

#define	ruta "CASOS DE PRUEBA/casosPrueba.txt"

int LONGITUD = 10000;
int INCREMENTO = 10000;
const int TOPE = 1000000;


string generarCadena(int longitud_min, int longitud_max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(longitud_min, longitud_max);
	int longitud = dist(gen);
	
	string caracteres = "abcdefghijklmnopqrstuvwxyz";
	string cadena;
	for (int i = 0; i < longitud; i++) {
		cadena += caracteres[rand() % caracteres.size()];
	}
	
	return cadena;
}

int main() {
	
	ofstream casosPrueba(ruta);
	
	int numCasos = ((TOPE-LONGITUD)/INCREMENTO)+1;
	
	casosPrueba << numCasos << endl;
	
	while (LONGITUD <= TOPE) {
		string cadena = generarCadena(LONGITUD, LONGITUD);
		int m = cadena.size() / 1000;
		
		casosPrueba << cadena << endl;
		casosPrueba << m << endl;
		
		
		LONGITUD += INCREMENTO;
	}
	
	casosPrueba.close();
	
	return 0;
}
