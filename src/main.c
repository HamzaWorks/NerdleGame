#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char* argv[])
{
	// generation de toutes les entrees possibles
	creerToutesEntrees();

	// génération des contraintes à partir du dossier input
	char bonnePosition[10];				// dans BonnesPositions.txt
	char contient[10]; 					// dans MauvaisesPositions.txt
	initialiserContient(contient);		// initalisation (très important)
	char invalides[10];					// dans Invalides.txt
	char mauvaisePosition[50];			// dans MauvaisesPositions.txt

	recupererContraintes(bonnePosition, contient,invalides,mauvaisePosition);
	
	// application des contraintes à la liste des entrées
	purgerEntrees(bonnePosition,contient,mauvaisePosition,invalides);

	  return 0;
}
