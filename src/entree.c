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
			return a/b;
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
	FILE* f = fopen("test/EntreesPossible.txt","w+");
	fprintf(f,"LISTE : \n");
	Entier* actuel1 = L1->premier;
	Entier* actuel2 = L2->premier;
	char entree[8];
	char* s = "THIS IS A TEST";
	while(actuel1 != NULL)
	{
		while(actuel2 != NULL)
		{
			if(resultatOperation(actuel1->nombre, actuel2->nombre,oper) < 100)
			{
				creationEntree1(entree,actuel1->nombre,actuel2->nombre,oper);
				fprintf(f,"hello : %s\n",entree);
			}
			actuel2 = actuel2->suivant;
		}
		actuel1 = actuel1->suivant;
		actuel2 = L2->premier;
	}
}  