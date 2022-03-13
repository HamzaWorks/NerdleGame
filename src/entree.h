#ifndef _ENTREE_H_
#define _ENTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void creationEntree1(char* entree,int a, int b, char oper); // a >= b
int intt(char c);
char charr(int n);
int resultatOperation(int a, int b, char oper);

void recupererChiffreInvalide(int* invalide);
void recupererInvalides(char* invalides);

void entreePossible(ListeEntiers* L1, ListeEntiers* L2, char oper);

void entreePossibleSoustraction(ListeEntiers* L1, ListeEntiers* L2, int* tab);
void entreePossibleDivision(ListeEntiers* L1, ListeEntiers* L2, int* tab);
void entreePossibleMultiplication(ListeEntiers* L1, ListeEntiers* L2, int* tab);
void entreePossibleAddition(ListeEntiers* L1, ListeEntiers* L2, int* tab);

void genererEntreesPossiblesOper(int* tab, char oper);

int neContientPas(int n, int* tab);
void recupererBonChiffre(char* bons);
void recupererContient(char* contient);
void recupererMauvaisePosition(char* mauvaisePosition);
int verificatonPosition(char* entree, char* mauvaisePosition);

void purgerEntrees(char* bonneEntrees, char* contient, char* mauvaisePosition, char* invalides);

int comparaisonChaine(char* a, char* b); // retourne 55 si a different de b
int verificationInvalides(char* entree, char* invalides);

int comparaisonChaine(char* a, char* b);
int verifiationContient(char* entree, char* contient);
int entreeContient(char* entree, char c);

// =================================================================================
void creerToutesEntrees();
void creerEntrees1oper(FILE* f);

void genererEntreesPossiblesOper0(FILE* f,char oper);
void entreePossibleSoustraction1(FILE* f,ListeEntiers* L1, ListeEntiers* L2);
void entreePossibleDivision1(FILE* f, ListeEntiers* L1, ListeEntiers* L2);
void entreePossibleMultiplication1(FILE* f, ListeEntiers* L1, ListeEntiers* L2);
void entreePossibleAddition1(FILE* f, ListeEntiers* L1, ListeEntiers* L2);
void creationEntree2(char* entree,int a, int b, int c, char oper1, char oper2);
void toutesEntreesDeuxOper(FILE* f);



#endif