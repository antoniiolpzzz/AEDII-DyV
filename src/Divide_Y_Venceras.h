//
// Divide_Y_Venceras.h
// Created by Antonio López Toboso and Mercedes López Caballero on 5/3/24.

#ifndef AEDII_DYV_DIVIDE_Y_VENCERAS_H
#define AEDII_DYV_DIVIDE_Y_VENCERAS_H

#include <cstring>
#include <vector>


bool pequeno(int p, int q, int &cadMinima);

std::pair<int,int> solDirecta(int p, int q, std::string &cadena);

int dividirCadena(int p, int q);

std::pair<int,int> combinar (const std::pair<int,int> &solA, const std::pair<int,int> &solB, int p, int q, int &m, int &cadMinima, std::string &cadena);

std::pair<int,int> DyV (int p, int q, int &cadMinima, std::string &cadena);


#endif //AEDII_DYV_DIVIDE_Y_VENCERAS_H
