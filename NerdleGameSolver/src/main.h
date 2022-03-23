#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "liste.h"
#include "entree.h"

void recupererEntreeRetour(char* entree, char* retour);
void traiter(Contrainte* contrainte,char* entree, char* retour);
void proposition();
void initialiserContrainte(Contrainte* C);
void ajouter(char * chaine, char c);
int victoire(); // 1 si victoire

#endif // MAIN_H_INCLUDED
