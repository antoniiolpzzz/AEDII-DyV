//
// generadorCasos.cpp
// Created by Antonio López Toboso and Mercedes López Caballero on 13/3/24.

#include <iostream>
#include <random>
#include <string>
#include <fstream>

using namespace std;

#define	ruta "CASOS DE PRUEBA/casosPrueba.txt"

const int LONGITUD_MIN = 10000;
const int LONGITUD_MAX = 1000000;


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
	
	cout << "Introduzca el número de casos de prueba deseados (entero positivo): ";
	
	int numCasos;
	cin >> numCasos;
	casosPrueba << numCasos << endl;
	
	while (numCasos) {
		string cadena = generarCadena(LONGITUD_MIN, LONGITUD_MAX);
		int m = cadena.size() / 1000;
		
		casosPrueba << cadena << endl;
		casosPrueba << m << endl;
		
		numCasos--;
	}
	
	casosPrueba.close();
	
	return 0;
}
