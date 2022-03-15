#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char* argv[])
{
	//jeu();
	// generation de toutes les entrees possibles
	creerToutesEntrees();

	// génération des contraintes à partir du dossier input
	char bonnePosition[10];				// dans BonnesPositions.txt
	char contient[15]; 					// dans MauvaisesPositions.txt
	initialiserContient(contient);		// initalisation (très important)
	char invalides[15];					// dans Invalides.txt
	char mauvaisePosition[50];			// dans MauvaisesPositions.txt

	recupererContraintes(bonnePosition, contient,invalides,mauvaisePosition);
	
	// application des contraintes à la liste des entrées
	purgerEntrees(bonnePosition,contient,mauvaisePosition,invalides);

	  return 0;
}


void jeu()
{
	FILE* Invalides = fopen("input/Invalides.txt","w+");
	FILE* BonnesPositions = NULL;
	FILE* MauvaisesPositions = fopen("input/MauvaisesPositions.txt","w+");
	char* entree;
	char* retour;
	size_t bufsize =32;
	size_t characters=10;
	characters ++;
	entree = (char*)malloc(bufsize * sizeof(char));
	retour = (char*)malloc(bufsize * sizeof(char));

	for(int i=0;i<2;i++)
	{
		BonnesPositions = fopen("input/BonnesPositions.txt","w+");
		printf("\nEntree :");
		characters = getline(&entree,&bufsize,stdin);
		printf("Retour :");
		characters = getline(&retour,&bufsize,stdin);
		traiter(Invalides,BonnesPositions,MauvaisesPositions,entree,retour);
		fprintf(BonnesPositions,"!");
		fclose(BonnesPositions);

	}

	fprintf(Invalides,"!");
	fprintf(MauvaisesPositions,"!");

	fclose(Invalides);
	fclose(MauvaisesPositions);
}

void traiter(FILE* Invalides, FILE* BonnesPositions, FILE* MauvaisesPositions, char* entree, char* retour)
{
	int i=0;

	for(i=0;i<8;i++)
	{
		switch(retour[i])
		{
			case '0':
				fprintf(Invalides,"%c",entree[i]);
				fprintf(BonnesPositions,"?");
				break;
			case '1':
				fprintf(MauvaisesPositions,"%c",entree[i]);
				fprintf(MauvaisesPositions,"%c",charr(i+1));
				fprintf(BonnesPositions,"?");
				break;
			case '2':
				fprintf(BonnesPositions,"%c",entree[i]);
				break;
			default:
				fprintf(BonnesPositions,"?");
				break;
		}
	}
}