#include "liste.h"
#include <stdlib.h>
#include <stdio.h>

ListeEntiers* initialiserListeEntiers(int taille)
{
	ListeEntiers* Liste=malloc(sizeof(*Liste));
	Entier* n = malloc(sizeof(*n));
	n->nombre = 0;
	n->suivant = NULL;
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
	while (actuel->suivant != NULL)
	{
		printf("%d ",actuel->nombre);
		actuel = actuel->suivant;
	}
	printf("%d ",actuel->nombre);

}


