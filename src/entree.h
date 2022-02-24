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

void entreePossible(ListeEntiers* L1, ListeEntiers* L2, char oper);


#endif