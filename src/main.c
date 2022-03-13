#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define TEST_ALL 0

int main()
{
	if(TEST_ALL == 1) testAll();
	else
	{

		// Récupérer les chiffres invalides 
		int tab[10];
		recupererChiffreInvalide(tab);

		// generer les entrees possible avec le bon opérateur
		genererEntreesPossiblesOper(tab,'-');

		// recupérer les chiffres bien plac"s
		char bons[9];
		recupererBonChiffre(bons);

		// récupérer contient
		char contient[10]; 
		recupererContient(contient);

		// output
		purgerEntrees(bons,contient);
	}

	  return 0;
}
