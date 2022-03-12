#include "entree.h"

void creationEntree1(char* entree,int a, int b, char oper)
{
	int res = resultatOperation(a,b,oper);

	if(res<10)
	{
		entree[0] = charr(a/100);
		entree[1] = charr((a/10)%10);
		entree[2] = charr(a%10);
		entree[3] = oper;
		entree[4] = charr(b/10);
		entree[5] = charr(b%10); 
		entree[6] = '=';
		entree[7] = charr(res);
	}

	else if (res<100)
	{
		if(a<100)
		{
			entree[0] = charr(a/10);
			entree[1] = charr(a%10);
			entree[2] = oper;
			entree[3] = charr(b/10);
			entree[4] = charr(b%10); 
			entree[5] = '=';
			entree[6] = charr(res/10);
			entree[7] = charr(res%10);
		}
		else
		{
			entree[0] = charr(a/100);
			entree[1] = charr((a/10)%10);
			entree[2] = charr(a%10);
			entree[3] = oper;
			entree[4] = charr(b);
			entree[5] = '=';
			entree[6] = charr(res/10);
			entree[7] = charr(res%10);
		}
	}

	else if (res>=100)
	{
		entree[0] = charr(a/10);
		entree[1] = charr(a%10);
		entree[2] = oper;
		entree[3] = charr(b);
		entree[4] = '=';
		entree[5] = charr(res/100);
		entree[6] = charr((res/10)%10);
		entree[7] = charr(res%10);
	}



	entree[8] = '\0';

}

int resultatOperation(int a, int b, char oper)
{
	switch (oper)
	{
		case '*':
			return a*b;
			break;

		case '+':
			return a+b;
			break;

		case '-':
			return a-b;
			break;

		case '/':
			if (a%b==0) return a/b;
			else return 10000;
			break;
	}
	return 0;
}

int intt(char c)
{
	return (c - '0');
}

char charr(int n)
{
	return (n + '0');
}

void recupererChiffreInvalide(int* invalide)
{
	FILE* f = fopen("test/invalides.txt","r");
	int n=99;
	int i=0;
	while (n != 55)
	{
		fscanf(f,"%d",&n);
		invalide[i]=n;
		i++;
	}
	invalide[i]=55;
	fclose(f);
}

void entreePossible(ListeEntiers* L1, ListeEntiers* L2, char oper)
{
	FILE* f = fopen("test/entreesPossibles.txt","w+");
	fprintf(f,"LISTE : \n");
	Entier* actuel1 = L1->premier;
	Entier* actuel2 = L2->premier;
	int res;
	char entree[9];
	while(actuel1 != NULL)
	{
		while(actuel2 != NULL)
		{
			res = resultatOperation(actuel1->nombre, actuel2->nombre,oper);
			if(res >= 100 )
			{
				creationEntree1(entree,actuel1->nombre,actuel2->nombre,oper);
				fprintf(f,"%s\n",entree);
			}
			actuel2 = actuel2->suivant;
		}
		actuel1 = actuel1->suivant;
		actuel2 = L2->premier;
	}
}  

void entreePossibleSoustraction(ListeEntiers* L1, ListeEntiers* L2, int* tab)
{
	FILE* f = fopen("test/entreesPossibles.txt","w+");
	fprintf(f,"LISTE : \n");
	Entier* actuel1 = L1->premier;
	Entier* actuel2 = L2->premier;
	int res;
	char entree[9];
	while(actuel1 != NULL)
	{
		while(actuel2 != NULL)
		{
			res = resultatOperation(actuel1->nombre, actuel2->nombre,'-');
			if(res < 100 && res >= 10 && neContientPas(res,tab) != 55 )
			{
				creationEntree1(entree,actuel1->nombre,actuel2->nombre,'-');
				fprintf(f,"%s\n",entree);
			}
			actuel2 = actuel2->suivant;
		}
		actuel1 = actuel1->suivant;
		actuel2 = L2->premier;
	}
} 


void entreePossibleDivision(ListeEntiers* L1, ListeEntiers* L2, int* tab)
{
	FILE* f = fopen("test/entreesPossibles.txt","w+");
	fprintf(f,"LISTE : \n");
	supprimerNombre(L2,0);
	Entier* actuel1 = L1->premier;
	Entier* actuel2 = L2->premier;
	int res;
	char entree[9];
	while(actuel1 != NULL)
	{
		while(actuel2 != NULL)
		{
			res = resultatOperation(actuel1->nombre, actuel2->nombre,'/');
			if(res < 100 && neContientPas(res,tab) != 55 )
			{
				creationEntree1(entree,actuel1->nombre,actuel2->nombre,'/');
				fprintf(f,"%s\n",entree);
			}
			actuel2 = actuel2->suivant;
		}
		actuel1 = actuel1->suivant;
		actuel2 = L2->premier;
	}
}

void entreePossibleMultiplication(ListeEntiers* L1, ListeEntiers* L2, int* tab)
{
	FILE* f = fopen("test/entreesPossibles.txt","w+");
	fprintf(f,"LISTE : \n");
	supprimerNombre(L2,0);
	Entier* actuel1 = L1->premier;
	Entier* actuel2 = L2->premier;
	int res;
	char entree[9];
	while(actuel1 != NULL)
	{
		while(actuel2 != NULL)
		{
			res = resultatOperation(actuel1->nombre, actuel2->nombre,'*');
			if(res >= 100 && neContientPas(res,tab) != 55 )
			{
				creationEntree1(entree,actuel1->nombre,actuel2->nombre,'*');
				fprintf(f,"%s\n",entree);
			}
			actuel2 = actuel2->suivant;
		}
		actuel1 = actuel1->suivant;
		actuel2 = L2->premier;
	}
}

void entreePossibleAddition(ListeEntiers* L1, ListeEntiers* L2, int* tab)
{
	FILE* f = fopen("test/entreesPossibles.txt","w+");
	fprintf(f,"LISTE : \n");
	supprimerNombre(L2,0);
	Entier* actuel1 = L1->premier;
	Entier* actuel2 = L2->premier;
	int res;
	char entree[9];
	while(actuel1 != NULL)
	{
		while(actuel2 != NULL)
		{
			res = resultatOperation(actuel1->nombre, actuel2->nombre,'+');
			if(res < 100 && neContientPas(res,tab) != 55 )
			{
				creationEntree1(entree,actuel1->nombre,actuel2->nombre,'+');
				fprintf(f,"%s\n",entree);
			}
			actuel2 = actuel2->suivant;
		}
		actuel1 = actuel1->suivant;
		actuel2 = L2->premier;
	}
}
void genererEntreesPossiblesOper(int* tab, char oper)
{
	ListeEntiers* L1;
	ListeEntiers* L2;

	switch(oper)
	{
		case '-':
			L1 = genererListeEntiersDeuxChiffres();
			L2 = genererListeEntiersDeuxChiffres();
			purgerListeTab(L1,tab);
			purgerListeTab(L2,tab);
			entreePossibleSoustraction(L1,L2,tab);
			break;
		case '*':
			L1 = genererListeEntiersDeuxChiffres();
			L2 = genererListeEntiersUnChiffre();
			purgerListeTab(L1,tab);
			purgerListeTab(L2,tab);
			entreePossibleMultiplication(L1,L2,tab);
			break;
		case '/':
			L1 = genererListeEntiersTroisChiffres();
			L2 = genererListeEntiersUnChiffre();
			purgerListeTab(L1,tab);
			purgerListeTab(L2,tab);
			entreePossibleDivision(L1,L2,tab);
			break;
		case '+':
			L1 = genererListeEntiersDeuxChiffres();
			L2 = genererListeEntiersDeuxChiffres();
			purgerListeTab(L1,tab);
			purgerListeTab(L2,tab);
			entreePossibleAddition(L1,L2,tab);
			break;
	}
}

int neContientPas(int n, int* tab)
{
	for(int i=0;i<10;i++)
	{
		if(chiffreDesUnites(n) == tab[i]) return 55;
		if(n>=10 && n<100)
		{
			if(chiffreDesDizaines(n) == tab[i]) return 55;
		}
		else if (n>=100)
		{
			if(chiffreDesCentaines(n) == tab[i]) return 55;
		}
	}
	return 0;
}

void recupererBonChiffre(char* bons)
{
	FILE* f = fopen("test/bonschiffres.txt","r");
	int i=0;
	for(i=0;i<8;i++)
	{
		fscanf(f,"%c",&bons[i]);
	}
	bons[8] = '\0';
	fclose(f);
}


void purgerEntrees(char* bonneEntrees)
{

	printf(" VALEUR DE BONNE ENTREES : %s ",bonneEntrees);
	FILE* inputEntrees = fopen("test/entreesPossibles.txt","r");
	FILE* outputEntrees = fopen("test/entreesValides.txt","w+");
	
	char entree[9];
	char lecture;
	int i=0;
	while( lecture != '#' )
	{
		for(i=0; i<8; i++)
		{
			fscanf(inputEntrees,"%c",&lecture);
			entree[i] = lecture;
		}
		entree[8] = '\0' ;
		printf("%s et %s \n",bonneEntrees,entree);
		//system("pause");
		if(comparaisonChaine(bonneEntrees,entree) != 55)
			fprintf(outputEntrees,"%s\n",entree);
		fscanf(inputEntrees,"%c",&lecture);
	}

	fclose(inputEntrees);
	fclose(outputEntrees);
}

int comparaisonChaine(char* a, char* b)
{
	for(int i=0; i<8; i++)
	{
		if(a[i] == '?') ;
		else if(a[i] != b[i]) return 55;
	}

	return 0;
}