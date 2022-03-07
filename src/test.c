#include "test.h"

#define TEST_FONCTION_CHIFFRE 0
#define TEST_PURGER_LISTE 1
#define TEST_SUPPRIMER_NOMBRE 0
#define TEST_ENTREE_POSSIBLE 0
#define TEST_GENERE_LISTE 0

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

	if(TEST_ENTREE_POSSIBLE == 1)
	{
		testEntreePossible();
	}

	if(TEST_GENERE_LISTE == 1)
	{
		testGenererListeEntiers();
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
	ListeEntiers* L = initialiserListeEntiers(10);
	int tab[10];
	recupererChiffreInvalide(tab);
	printf("Liste initiale :\n");
	afficherListeEntiers(L);
	printf("\nListe purgee");
	//purgerListeTab(L,tab);
	afficherListeEntiers(L);
}

void testSupprimerListe()
{
	ListeEntiers* L = initialiserListeEntiers(50);
	afficherListeEntiers(L);
	printf("\nSupression de 4 45 20 44 et 8\n");
	supprimerNombre(L,4);
	supprimerNombre(L,45);
	supprimerNombre(L,44);
	supprimerNombre(L,20);
	supprimerNombre(L,8);
	afficherListeEntiers(L);
}

void testEntreePossible()
{
	ListeEntiers* L1 = genererListeEntiersDeuxChiffres();
	ListeEntiers* L2 = genererListeEntiersDeuxChiffres();
	afficherListeEntiers(L1);
	afficherListeEntiers(L2);
	entreePossible(L1,L2,'-');
}

void testGenererListeEntiers()
{
	printf("Voici la generation d'une liste de tous les entiers de 0 a 9 :");
	afficherListeEntiers(genererListeEntiersUnChiffre());
	printf("\nVoici la generation d'une liste de tous les entiers de 10 a 99 :");
	afficherListeEntiers(genererListeEntiersDeuxChiffres());
}

