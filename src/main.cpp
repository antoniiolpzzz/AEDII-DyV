//
// main.cpp
// Created by Antonio López Toboso and Mercedes López Caballero on 5/3/24.

/*
	Define´s, const e includes.
*/

#include <iostream>
#include <ctime>
#include <fstream>
#include "Divide_Y_Venceras.h"

#define	rutaTiempos "INFORMACION DE TIEMPOS/infoTiempos.csv"
#define	rutaResultados "RESULTADOS/resultados.txt"
#define	rutaEntrada "CASOS DE PRUEBA/casosPrueba.txt"

int main() {

    /*
        Flujo de informacion hacia ficheros de salida de datos.
    */

    std::ifstream entrada(rutaEntrada);
    std::ofstream infoTiempos(rutaTiempos); //, std::ios::app);
    std::ofstream resultados(rutaResultados);

    infoTiempos << "TAMAÑO_CADENA, TIEMPO_SEG, M_(N/1000)" << std::endl;

    /*
        Lectura del numero de casos a tratar.
    */

    int numeroCasos;
    entrada >> numeroCasos;

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

        int longitudEntrada = (int) cadenaEntrada.length();

        /*
            Llamada a la funcion Divide Y Venceras (DyV).
            Conteo de tiempos de ejecucion de dicha funcion.
        */

        int inicio = 0;
        int fin = longitudEntrada-1;

        std::vector<int> diferenciaAcumulada(longitudEntrada, -1);

        long double timestampInicio = (long double) clock();

        std::pair<int,int> solucion = DyV(inicio, fin, cadMinima, cadenaEntrada, diferenciaAcumulada);

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
        resultados << "Posición de inicio: " << (solucion.first + 1) << std::endl;
        resultados << "Diferencia máxima: " << (solucion.second) << std::endl;

    }

    entrada.close();
    infoTiempos.close();
    resultados.close();
}
