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

ListeEntiers* initialiserListeEntiers(int taille); 	// Renvoie une liste de 0 � (taille-1)
void ajouterNombre(ListeEntiers* L, int n); 		// Ajoute un nombre � la liste
void afficherListeEntiers(ListeEntiers* L);			// Affiche la liste
int tailleListe(ListeEntiers* L);					// r�cup�re la liste des chiffre invalides
void supprimerNombre(ListeEntiers* L, int n);		// supprime n de la liste
void purgerListe(ListeEntiers* L,int* invalide);

int chiffreDesUnites(int n);						// retounre le chiffre des unites
int chiffreDesDizaines(int n);						// retourne le chiffre des dizaines

#endif // LISTE_H_INCLUDED
