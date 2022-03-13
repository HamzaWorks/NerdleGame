#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "liste.h"
#include "entree.h"

void jeu();
void traiter(FILE* Invalides, FILE* BonnesPositions, FILE* MauvaisesPositions, char* entree, char* retour);
void proposition();

#endif // MAIN_H_INCLUDED
