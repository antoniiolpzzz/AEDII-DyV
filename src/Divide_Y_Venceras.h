//
// Divide_Y_Venceras.h
// Created by Antonio López Toboso and Mercedes López Caballero on 5/3/24.

#ifndef AEDII_DYV_DIVIDE_Y_VENCERAS_H
#define AEDII_DYV_DIVIDE_Y_VENCERAS_H

#include <cstring>
#include <vector>


int recursiva(int p, int q, std::string &cadena, std::vector<int> &diferenciaAcumulada);

bool pequeno(int p, int q, int &cadMinima);

std::pair<int,int> solDirecta(int p, int q, std::string &cadena);

int dividirCadena(int p, int q);

std::pair<int,int> combinar (std::pair<int,int> &solA, std::pair<int,int> &solB, int p, int q, int &m, int &cadMinima, std::string &cadena, std::vector<int> &diferenciaAcumulada);

std::pair<int,int> DyV (int p, int q, int &cadMinima, std::string &cadena, std::vector<int> &diferenciaAcumulada);


#endif //AEDII_DYV_DIVIDE_Y_VENCERAS_H
