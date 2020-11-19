#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <string>
#include <vector>

void lectureTableauDynamique(std::vector<std::string>const& table);
void ecritureTableauDynamique(std::vector<std::string>& table);
void lectureTableauDynamiqueMultidimentionel(std::vector<std::vector<int>> grille);

void ecrire();
void lecture();

int motMystere();

#endif