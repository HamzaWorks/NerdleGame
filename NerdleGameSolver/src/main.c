#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char* argv[])
{
	char c;
	char entree[10];
	char retour[10];
	Contrainte* C = malloc(sizeof(Contrainte));
	initialiserContrainte(C);

	// generation de toutes les entrees possibles
	printf("Generer les entrees ? O/N");
	scanf("%c",&c);
	if(c=='o' || c=='O' || c=='y' || c=='Y')
	{
		printf("Generation de toutes les entrees possibles...\n");
		creerToutesEntrees();
		printf("Entrees generees !\n");
	}
	//else
		//chargerToutesEntrees();


	// Proposition
	printf("Proposition : 3*4+5=17\n");

	// Jeu
	
	
	recupererEntreeRetour(entree,retour);
	//printf("\nENTREE : %s\nRETOUR : %ss",entree,retour);
	traiter(C,entree,retour);
		
	// application des contraintes à la liste des entrées
	purgerEntrees(C->bp,C->contient,C->mp,C->invalides);
	copierFichier("output/EntreesValides.txt","input/EntreesValides.txt");
	

	printf("Victoire = %d",victoire());

	  return 0;
}


void recupererEntreeRetour(char* entree, char* retour)
{
		printf("\nEntree :");
		scanf("%s",entree);
		printf("Retour :");
		scanf("%s",retour);
}

void traiter(Contrainte* C,char* entree, char* retour)
{
	int i=0;


	for(i=0;i<8;i++)
	{
		switch(retour[i])
		{
			case '0':
				if((contientEntree(C->contient,entree[i]) == 0))
					ajouter(C->invalides,entree[i]);
				break;
			case '1':
				ajouter(C->mp,entree[i]);
				ajouter(C->mp,charr(i+1));
				ajouter(C->contient,entree[i]);
				break;
			case '2':
				ajouter(C->bp,entree[i]);
				ajouter(C->bp,charr(i+1));
				ajouter(C->contient,entree[i]);
				break;
			default:
				printf("ERROR\n");
				break;
		}
	}
}

void initialiserContrainte(Contrainte* C)
{
	C->bp[0]='!';
	C->mp[0]='!';
	C->invalides[0]='!';
	C->contient[0]='!';
	C->bp[1]='\0';
	C->mp[1]='\0';
	C->invalides[1]='\0';
	C->contient[1]='\0';
}

void ajouter(char * chaine, char c)
{
	int i=0;
	while(chaine[i] != '!') i++;
	chaine[i] = c;
	chaine[i+1] = '!';
	chaine[i+2] = '\0';
}

int victoire()
{
	FILE* f = fopen("output/EntreesValides.txt","r");
	char c = 'c';
	int lignes = 0;
	while(c != '#')
	{
		fscanf(f,"%c",&c);
		if(c == '\n') lignes++;
	}
	if(lignes==1) return 1;
	else return 0;
}

int contientEntree(char* entree, char c)
{
	char c0 = 'c';
	int i = 0;
	while(c0 != '!')
	{
		if(entree[i] == c)
			return 1;
		i++;
	}
	return 0;
}

void chargerToutesEntrees()
{
	copierFichier("Archives/ToutesLesEntrees.txt","input/EntreesValides.txt");
}

void copierFichier(char* f1, char* f2)
{
	FILE *fp1, *fp2;
    char ch;
  
    // ouvrir le fichier en lecture
    fp1 = fopen(f1, "r");
    // ouvrir le fichier en écriture
    fp2 = fopen(f2, "w+");
  
    // Lire le contenu du fichier
    while((ch = getc(fp1)) != EOF)
        putc(ch, fp2);
  
    fclose(fp1);
    fclose(fp2);
}