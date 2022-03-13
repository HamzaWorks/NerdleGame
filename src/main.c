#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define TEST_ALL 0

int main()
{
	if(TEST_ALL == 1) testAll();
	else
	{


		// generation de toutes les entrees possibles
		creerToutesEntrees();

		// recupérer les chiffres bien placés
		char bons[9];
		recupererBonChiffre(bons);

		// récupérer contient
		char contient[10]; 
		recupererContient(contient);

		// récupérer inavlides
		char invalides[10];
		recupererInvalides(invalides);

		char mauvaisePosition[50];
		recupererMauvaisePosition(mauvaisePosition); 
		printf("mauvaisePosition = %s\ncontient = %s\nbons chiffres = %s\ninvalides = %s\n",mauvaisePosition,contient,bons,invalides);

		// output
		purgerEntrees(bons,contient,mauvaisePosition,invalides);
	}

	  return 0;
}
