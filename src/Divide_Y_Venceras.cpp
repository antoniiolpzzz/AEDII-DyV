//
// Divide_Y_Venceras.cpp
// Created by Antonio López Toboso and Mercedes López Caballero on 5/3/24.

#include "Divide_Y_Venceras.h"

using namespace std;


int recursiva(int p, int q, string &cadena){

    int difAcumulada = 0;
    for (int i = p; i<q; i++) {
        difAcumulada = difAcumulada + abs(cadena[i]-cadena[i+1]);
    }

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



pair<int,int> combinar (const pair<int,int> &solA, const pair<int,int> &solB, int p, int q, int &m, int &cadMinima, string &cadena){

    pair<int,int> maxUnion = pair<int,int>(-1,-1);
    

    for (int i=max(p, m-cadMinima+1); i<min(q, m+1); i++) {

        int tmp = recursiva(i, i+cadMinima-1, cadena); /*m OR p+cadMinima-1*/

        if (tmp > maxUnion.second){
            maxUnion = make_pair(i, tmp);
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



pair<int,int> DyV (int p, int q, int &cadMinima, string &cadena){

    if (pequeno(p, q, cadMinima)){

        return solDirecta(p, q, cadena);

    }else if ( q-p < cadMinima - 1){

        return pair<int,int>(-1,-1);

    }else {
        int m = dividirCadena(p, q);
        pair<int,int> solA = DyV(p, m, cadMinima, cadena);
        pair<int,int> solB = DyV(m+1, q, cadMinima, cadena);
        return combinar(solA, solB, p, q, m, cadMinima, cadena);
    }
}
