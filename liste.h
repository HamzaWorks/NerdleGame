#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

typedef struct Entier Entier;
struct Entier
{
	int nombre;
	Entier* suivant;
};

typedef struct ListeEntiers ListeEntiers;
struct ListeEntiers
{
	Entier* premier;
};

ListeEntiers* initialiserListeEntiers(int taille); 	// Renvoie une liste de 0 à (taille-1)
void ajouterNombre(ListeEntiers* L, int n); 		// Ajoute un nombre à la liste
void afficherListeEntiers(ListeEntiers* L);			// Affiche la liste
int tailleListe(ListeEntiers* L);

#endif // LISTE_H_INCLUDED
