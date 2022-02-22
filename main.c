#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    ListeEntiers* L = initialiserListeEntiers(100);
	afficherListeEntiers(L);
	printf("\nTaille de la liste = %d", tailleListe(L));
    return 0;
}
