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
			actuel->suivant = actuel->suivant->suivant;
			return;
		}
		actuel = actuel->suivant;
	}
}

ListeEntiers* genererListeEntiersUnChiffre()
{
	ListeEntiers* L = initialiserListeEntiers(10);
	return L;
}

ListeEntiers* genererListeEntiersDeuxChiffres()
{
	ListeEntiers* L = initialiserListeEntiers(100);
	for(int i=0;i<10;i++)
	{
		supprimerNombre(L,i);
	}
	return L;
}


ListeEntiers* genererListeEntiersTroisChiffres()
{
	ListeEntiers* L = initialiserListeEntiers(1000);
	for(int i=0;i<100;i++)
	{
		supprimerNombre(L,i);
	}
	return L;
}
