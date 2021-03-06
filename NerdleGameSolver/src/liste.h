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

ListeEntiers* initialiserListeEntiers(int taille); 	// Renvoie une liste de 0 ? (taille-1)
void ajouterNombre(ListeEntiers* L, int n); 		// Ajoute un nombre ? la liste
void afficherListeEntiers(ListeEntiers* L);			// Affiche la liste
int tailleListe(ListeEntiers* L);					// r?cup?re la liste des chiffre invalides
void supprimerNombre(ListeEntiers* L, int n);		// supprime n de la liste

ListeEntiers* genererListeEntiersUnChiffre();	// Genere une liste de 0 ? 9
ListeEntiers* genererListeEntiersDeuxChiffres(); // Genere une liste de tous les entiers ? 2 chiffres
ListeEntiers* genererListeEntiersTroisChiffres(); // Entiers 3 chiffres


#endif // LISTE_H_INCLUDED
