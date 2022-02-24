#include "test.h"

void testAll()
{
	if(TEST_FONCTION_CHIFFRE == 1)
	{
		printf("Test de testFonctionChiffreDesUnites :\n\n");
		testFonctionChiffreDesUnites();
		printf("\n\nTest de testFonctionchiffreDesDizaines :\n\n");
		testFonctionChiffreDesDizaines();

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
	printf("Le chiffre des dizaines de 71 est %d\n",chiffreDesDizaines(71));
	printf("Le chiffre des dizaines de 99 est %d\n",chiffreDesDizaines(99));
	printf("Le chiffre des dizaines de 0 est %d\n",chiffreDesDizaines(0));
	printf("Le chiffre des dizaines de 450 est %d\n",chiffreDesDizaines(450));
	printf("Le chiffre des dizaines de 109 est %d\n",chiffreDesDizaines(109));
	printf("Le chiffre des dizaines de 67468 est %d\n",chiffreDesDizaines(67468));
	printf("Le chiffre des dizaines de 1 est %d\n",chiffreDesDizaines(1));
}



