#include <stdio.h>
#include <stdlib.h>
#include "main.h"


int main()
{
	ListeEntiers* L = initialiserListeEntiers(100);
	afficherListeEntiers(L);
	int invalide[10];
	recupererChiffreInvalide(invalide);
	/*printf("\n\nPurge de %d %d\n",invalide[0],invalide[1]);
	purgerListe(L,invalide);*/
	supprimerNombre(L,99);
	afficherListeEntiers(L);
  	return 0;
}
