//
// Divide_Y_Venceras.cpp
// Created by Antonio López Toboso and Mercedes López Caballero on 5/3/24.

#include "Divide_Y_Venceras.h"

using namespace std;


int recursiva(int p, int q, string &cadena, vector<int> &diferenciaAcumulada){

    if (diferenciaAcumulada[p] != -1) {
        return diferenciaAcumulada[p];
    }


    int difAcumulada = 0;
    for (int i = p; i<q; i++) {
        difAcumulada = difAcumulada + abs(cadena[i]-cadena[i+1]);
    }

    diferenciaAcumulada[p] = difAcumulada;
    return difAcumulada;
}


bool pequeno(int p, int q, int &cadMinima){

    return (q-p) == cadMinima - 1;
}


pair<int,int> solDirecta(int p, int q, string &cadena){

    int difAcumulada = 0;
    for (int i = p; i<q; i++) {
        difAcumulada = difAcumulada + abs(cadena[i]-cadena[i+1]);
    }

    return pair<int,int>(p, difAcumulada);
}


int dividirCadena(int p, int q){

    return (p+q)/2;
}


pair<int,int> combinar (pair<int,int> &solA, pair<int,int> &solB, int p, int q, int &m, int &cadMinima, string &cadena, vector<int> &diferenciaAcumulada){

    pair<int,int> maxUnion = pair<int,int>(-1,-1);

    //int i = max(p, m-cadMinima+1)
    //i< min(q, m+1)
    for (int i=max(p, m-cadMinima+1); i<min(q, m+1); i++) {

        int tmp = recursiva(i, i+cadMinima-1, cadena, diferenciaAcumulada); /*m OR p+cadMinima-1*/

        if (tmp > maxUnion.second){
            maxUnion = pair<int,int>(i, tmp);
        }
    }


    if (maxUnion.second > max(solA.second, solB.second)){

        return maxUnion;

    }else{

        if (solA.second > solB.second){
            return solA;
        }
        else {
            return solB;
        }
    }
}



pair<int,int> DyV (int p, int q, int &cadMinima, string &cadena, vector<int> &diferenciaAcumulada){

    if (pequeno(p, q, cadMinima)){

        return solDirecta(p, q, cadena);

    }else if ( q-p < cadMinima - 1){

        return pair<int,int>(-1,-1);

    }else {
        int m = dividirCadena(p, q);
        pair<int,int> solA = DyV(p, m, cadMinima, cadena, diferenciaAcumulada);
        pair<int,int> solB = DyV(m+1, q, cadMinima, cadena, diferenciaAcumulada);
        return combinar(solA, solB, p, q, m, cadMinima, cadena, diferenciaAcumulada);
    }
}
