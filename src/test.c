#include "test.h"

#define TEST_FONCTION_CHIFFRE 0
#define TEST_PURGER_LISTE 1
#define TEST_SUPPRIMER_NOMBRE 0

void testAll()
{
	if(TEST_FONCTION_CHIFFRE == 1)
	{
		printf("Test de testFonctionChiffreDesUnites :\n\n");
		testFonctionChiffreDesUnites();
		printf("\n\nTest de testFonctionchiffreDesDizaines :\n\n");
		testFonctionChiffreDesDizaines();
	}

	if(TEST_PURGER_LISTE == 1)
	{
		printf("\nTest de purgerListe :\n\n");
		testFoncionPurgerListe();
	}

	if(TEST_SUPPRIMER_NOMBRE == 1)
	{
		testSupprimerListe();
	}
}

void testFonctionChiffreDesUnites()
{
	printf("Le chiffre des unites de 40 est %d\n",chiffreDesUnites(40));
	printf("Le chiffre des unites de 68 est %d\n",chiffreDesUnites(68));
	printf("Le chiffre des unites de 71 est %d\n",chiffreDesUnites(71));
	printf("Le chiffre des unites de 99 est %d\n",chiffreDesUnites(99));
	printf("Le chiffre des unites de 450 est %d\n",chiffreDesUnites(450));
	printf("Le chiffre des unites de 109 est %d\n",chiffreDesUnites(109));
	printf("Le chiffre des unites de 67468 est %d\n",chiffreDesUnites(67468));
	printf("Le chiffre des unites de 1 est %d\n",chiffreDesUnites(1));
}

void testFonctionChiffreDesDizaines()
{
	printf("Le chiffre des dizaines de 40 est %d\n",chiffreDesDizaines(40));
	printf("Le chiffre des dizaines de 68 est %d\n",chiffreDesDizaines(68));
	printf("Le chiffre des dizaines de 19 est %d\n",chiffreDesDizaines(19));
	printf("Le chiffre des dizaines de 99 est %d\n",chiffreDesDizaines(99));
	printf("Le chiffre des dizaines de 0 est %d\n",chiffreDesDizaines(0));
	printf("Le chiffre des dizaines de 450 est %d\n",chiffreDesDizaines(450));
	printf("Le chiffre des dizaines de 109 est %d\n",chiffreDesDizaines(109));
	printf("Le chiffre des dizaines de 67468 est %d\n",chiffreDesDizaines(67468));
	printf("Le chiffre des dizaines de 1 est %d\n",chiffreDesDizaines(1));
}

void testFoncionPurgerListe()
{
	ListeEntiers* L = initialiserListeEntiers(100);
	printf("Liste initiale :\n");
	afficherListeEntiers(L);
	//printf("Liste purgee de 4, 2, 1 et 5");
	purgerListe(L,4);
	//purgerListe(L,2);
	//purgerListe(L,1);
	//purgerListe(L,5);
	//afficherListeEntiers(L);
}

void testSupprimerListe()
{
	ListeEntiers* L = initialiserListeEntiers(50);
	afficherListeEntiers(L);
	printf("\nSupression de 4 45 20 et 8\n");
	supprimerNombre(L,4);
	supprimerNombre(L,45);
	supprimerNombre(L,20);
	supprimerNombre(L,8);
	afficherListeEntiers(L);
}

