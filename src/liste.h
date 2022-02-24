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
int tailleListe(ListeEntiers* L);					// récupère la liste des chiffre invalides
void supprimerNombre(ListeEntiers* L, int n);		// supprime n de la liste
void purgerListe(ListeEntiers* L,int invalide);
void purgerListeTab(ListeEntiers* L, int* tab);

int chiffreDesUnites(int n);						// retourne le chiffre des unites
int chiffreDesDizaines(int n);						// retourne le chiffre des dizaines
int chiffreDesCentaines(int n);

ListeEntiers* genererListeEntiersUnChiffre();	// Genere une liste de 0 à 9
ListeEntiers* genererListeEntiersDeuxChiffres(); // Genere une liste de tous les entiers à 2 chiffres

#endif // LISTE_H_INCLUDED
