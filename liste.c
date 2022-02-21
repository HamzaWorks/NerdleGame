#include "liste.h"
#include <stdlib.h>

ListeEntiers* initialiserListeEntiers(int taille)
{
	ListeEntiers* Liste=malloc(sizeof(*Liste));
	Entier* n = Liste;
	for(int i=0;i<taille;i++)
	{
		
	}
}

void ajouterNombre(ListeEntiers* L, int n)
{
	Entier* x = malloc(sizeof(*x));
	x->next = L->list;
	L->list = x;
}

