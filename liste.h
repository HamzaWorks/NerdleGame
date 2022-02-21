#ifndef _LISTE_H_
#define _LISTE_H_

typedef struct Entier Entier;
struct Entier
{
	int n;
	Entier* suivant;
};

typedef struct ListeEntiers ListeEntiers;
struct ListeEntiers
{
	ListeEntiers* premier;
};

ListeEntiers* initialiserListeEntiers(int taille); // Renvoie une liste de 0 à taille
void ajouterNombre(ListeEntiers L, int n); // Ajoute un nombre à la liste


#endif