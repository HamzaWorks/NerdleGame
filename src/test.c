#include "test.h"

#define TEST_FONCTION_CHIFFRE 0
#define TEST_PURGER_LISTE 0
#define TEST_SUPPRIMER_NOMBRE 0
#define TEST_ENTREE_POSSIBLE 0
#define TEST_GENERE_LISTE 0
#define TEST_RECUPERER_CHIFFRE_INVALIDE 0
#define TEST_RECUPERER_BON_CHIFFRE 0
#define TEST_PURGER_ENTRER 0
#define TEST_ENTREE_CONTIENT 1

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

	if(TEST_RECUPERER_CHIFFRE_INVALIDE == 1)
	{
		testRecupererChiffreInvalide();
	}

	if(TEST_RECUPERER_BON_CHIFFRE == 1 )
	{
		testRecupererBonChiffre();
	}

	if(TEST_PURGER_ENTRER == 1)
	{
		printf("Test de purgerEntrees :\n");
		testPurgerEntrer();
	}

	if(TEST_ENTREE_CONTIENT == 1)
	{
		printf("Test de entreeContient :\n");
		testEntreeContient();
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

void testRecupererChiffreInvalide()
{
	int tab[10];
	recupererChiffreInvalide(tab);
	for(int i=0; i<10;i++)
	{
		printf("\ntab %d = %d\n",i,tab[i]);
	}
}

void testFoncionPurgerListe()
{
	ListeEntiers* L = initialiserListeEntiers(500);
	int tab[10];
	recupererChiffreInvalide(tab);
	printf("Liste initiale :\n");
	afficherListeEntiers(L);
	printf("\nListe purgee");
	purgerListeTab(L,tab);
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
	int tab[10];
	recupererChiffreInvalide(tab);
	genererEntreesPossiblesOper(tab,'-');
}

void testGenererListeEntiers()
{
	printf("Voici la generation d'une liste de tous les entiers de 0 a 9 :");
	afficherListeEntiers(genererListeEntiersUnChiffre());
	printf("\nVoici la generation d'une liste de tous les entiers de 10 a 99 :");
	afficherListeEntiers(genererListeEntiersDeuxChiffres());
	printf("\nVoici la generation d'une liste de tous les entiers de 100 a 999 :");
	afficherListeEntiers(genererListeEntiersTroisChiffres());
}

void testRecupererBonChiffre()
{
	char bons[10];
	recupererBonChiffre(bons);
	for(int i=0; i<10;i++) printf("%c ",bons[i]);
}

void testPurgerEntrer()
{
	char bons[9];
	char contient[10];
	recupererBonChiffre(bons);
	recupererContient(contient);
	purgerEntrees(bons,contient);
}

void testEntreeContient()
{
	char* entree = "99-89=10 ";
	char* contient ="189/";
	if(verifiationContient(entree,contient) != 55) printf("BRAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
}