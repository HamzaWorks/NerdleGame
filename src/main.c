#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define TEST_ALL 0

int main(int argc, char* argv[])
{
	if(TEST_ALL == 1) testAll();
	else
	{


		// generation de toutes les entrees possibles
		creerToutesEntrees();

		char bonnePosition[10];
		char contient[10]; 
		initialiserContient(contient);
		char invalides[10];
		char mauvaisePosition[50];

		recupererContraintes(bonnePosition, contient,invalides,mauvaisePosition);
		// output
		purgerEntrees(bonnePosition,contient,mauvaisePosition,invalides);
	}

	  return 0;
}
