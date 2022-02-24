#include "liste.h"
#include <stdlib.h>
#include <stdio.h>

ListeEntiers* initialiserListeEntiers(int taille)
{
	ListeEntiers* Liste=malloc(sizeof(*Liste));
	Entier* n = malloc(sizeof(*n));
	n->nombre = 0;
	n->suivant = NULL;
	Liste->premier = n;
	for(int i=1;i<taille;i++)
	{
		ajouterNombre(Liste,i);
	}

	return Liste;
}


void ajouterNombre(ListeEntiers* L, int n)
{
	Entier* x = malloc(sizeof(*x));
	x->nombre = n;
	x->suivant = L->premier;
	L->premier = x;
}

void afficherListeEntiers(ListeEntiers* L)
{
	Entier* actuel=L->premier;
	printf("\n");
	while (actuel->suivant != NULL)
	{
		printf("%d ",actuel->nombre);
		actuel = actuel->suivant;
	}
	printf("%d ",actuel->nombre);
}

int tailleListe(ListeEntiers* L)
{
	int i=0;
	Entier* actuel = L->premier;
	while (actuel != NULL)
	{
		i++;
		actuel = actuel->suivant;
	}
	return i;
}

void supprimerNombre(ListeEntiers* L, int n)
{	
	Entier* actuel=L->premier;
	if (actuel->nombre == n)
	{
		L->premier = L->premier->suivant;
		return;
	}
	while (actuel->suivant != NULL)
	{
		if(actuel->suivant->nombre == n)
		{
			//Entier* aSupprimer = actuel->suivant;
			actuel->suivant = actuel->suivant->suivant;
			//free(aSupprimer);
			return;
		}
		actuel = actuel->suivant;
	}
}

void purgerListe(ListeEntiers* L,int invalide)
{
	Entier* actuel = L->premier;
	while(actuel != NULL)
	{
		if(chiffreDesDizaines(actuel->nombre) == invalide || chiffreDesUnites(actuel->nombre) == invalide || chiffreDesCentaines(actuel->nombre) == invalide) 
		{	
			supprimerNombre(L,actuel->nombre);
		}
		actuel = actuel->suivant;
	}
}

int chiffreDesUnites(int n)
{
	return n%10;
}

int chiffreDesDizaines(int n)
{
	if(n>=100)
		return (n/10)%10;
	else if (n<10)
	{
		return 0;
	}
	else
	{
		return n/10;
	}
}

int chiffreDesCentaines(int n)
{
	return n/100;
}


