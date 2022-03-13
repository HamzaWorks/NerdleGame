#ifndef _ENTREE_H_
#define _ENTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"


// ======================================================================================
// Création d'une entrée
void creationEntree1(char* entree,int a, int b, char oper);
void creationEntree2(char* entree,int a, int b, int c, char oper1, char oper2);

// ======================================================================================
// Récupération des invalides, bonnes positions, mauvaises positions
void recupererContraintes(char* bonnePosition, char* contient, char* invalides, char* mauvaisePosition);
void recupererInvalides(char* invalides);
void recupererBonnePosition(char* bons);
void recupererMauvaisePosition(char* mauvaisePosition, char* contient);

// ======================================================================================
// Verification des différentes contraintes
int verificationPosition(char* entree, char* mauvaisePosition);
int verificationBonnePosition(char* a, char* b); // retourne 55 si a different de b
int verificationInvalides(char* entree, char* invalides);
int verifiationContient(char* entree, char* contient);


// ======================================================================================
// Purge de toutes les entrées possibles par les contraintes
void purgerEntrees(char* bonneEntrees, char* contient, char* mauvaisePosition, char* invalides);


// ======================================================================================
// Création des entrées possibles
void creerToutesEntrees();
void creerEntrees1oper(FILE* f);
void creerEntrees2oper(FILE* f);




// ======================================================================================
// Outils intermédiaires 
int entreeContient(char* entree, char c);
void genererEntreesPossiblesOper(FILE* f,char oper);
void entreePossibleSoustraction(FILE* f,ListeEntiers* L1, ListeEntiers* L2);
void entreePossibleDivision(FILE* f, ListeEntiers* L1, ListeEntiers* L2);
void entreePossibleMultiplication(FILE* f, ListeEntiers* L1, ListeEntiers* L2);
void entreePossibleAddition(FILE* f, ListeEntiers* L1, ListeEntiers* L2);
int resultatOperation(int a, int b, char oper);
int intt(char c);
char charr(int n);
void initialiserContient(char* contient);
void ajouterContient(char* contient,char lecture);



#endif