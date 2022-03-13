#include "entree.h"

void creationEntree1(char* entree,int a, int b, char oper)
{
	int res = resultatOperation(a,b,oper);

	if(res<10)
	{
		if(a>b)
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
		else
		{
			entree[0] = charr(a/10);
			entree[1] = charr(a%10);
			entree[2] = oper;
			entree[3] = charr(b/100);
			entree[4] = charr((b/10)%10);
			entree[5] = charr(b%10); 
			entree[6] = '=';
			entree[7] = charr(res);
		}
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
			if(a>b)
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
			else
			{
				entree[0] = charr(a);
				entree[1] = oper;
				entree[2] = charr(a/100);
				entree[3] = charr((b/10)%10);
				entree[4] = charr(b%10);
				entree[5] = '=';
				entree[6] = charr(res/10);
				entree[7] = charr(res%10);
			}
		}
	}

	else if (res>=100)
	{
		if(a>b)
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
		else
		{
			entree[0] = charr(a);
			entree[1] = oper;
			entree[2] = charr(b/10);
			entree[3] = charr(b%10);
			entree[4] = '=';
			entree[5] = charr(res/100);
			entree[6] = charr((res/10)%10);
			entree[7] = charr(res%10);
		}
	}



	entree[8] = '\0';

}

void creationEntree2(char* entree,int a, int b, int c, char oper1, char oper2)
{
	int res = resultatOperation(resultatOperation(a,b,oper1),c,oper2);

	if(res<10)
	{
		entree[0] = charr(a/10);
		entree[1] = charr(a%10);
		entree[2] = oper1;
		entree[3] = charr(b);
		entree[4] = oper2;
		entree[5] = charr(c); 
		entree[6] = '=';
		entree[7] = charr(res);
	}

	else if (res<100 && res >=10)
	{
		entree[0] = charr(a);
		entree[1] = oper1;
		entree[2] = charr(b);		
		entree[3] = oper2;
		entree[4] = charr(c); 
		entree[5] = '=';
		entree[6] = charr(res/10);
		entree[7] = charr(res%10);
	}
	
	entree[8] = '\0';

}

void recupererInvalides(char* invalides)
{
	FILE* f = fopen("input/invalides.txt","r");
	char c='c';
	int i=0;
	while (c != '!')
	{
		fscanf(f,"%c",&c);
		invalides[i]=c;
		i++;
	}
	invalides[i]='\0';
	fclose(f);
} 

void recupererBonnePosition(char* bons)
{
	FILE* f = fopen("input/bonschiffres.txt","r");
	int i=0;
	for(i=0;i<8;i++)
	{
		fscanf(f,"%c",&bons[i]);
	}
	bons[8] = '\0';
	fclose(f);
}

void recupererContient(char* contient)
{
	FILE* f = fopen("input/contient.txt","r");
	char c;
	int i=0;
	while (c != '!')
	{
		fscanf(f,"%c",&c);
		contient[i]=c;
		i++;
	}
	contient[i]='\0';
	fclose(f);
}

void recupererMauvaisePosition(char* mauvaisePosition, char* contient)
{
	FILE* f = fopen("input/MauvaisesPositions.txt","r");
	int i=0;
	char lecture='l';
	while(lecture != '!')
	{
		fscanf(f,"%c",&lecture);
		if(lecture != ';') mauvaisePosition[i]=lecture;
		if(i%2 == 0) ajouterContient(contient,lecture);
		i++;
	}
	mauvaisePosition[i]='\0';
	contient[i/2] = '\0';
	fclose(f);
}

int verificatonPosition(char* entree, char* mauvaisePosition)
{
	int i=0;

	while(mauvaisePosition[i] != '!')
	{
		if(entree[intt(mauvaisePosition[i+1])-1] == mauvaisePosition[i]) return 55;
		i +=2;
	}
	return 0;
}




int verificationBonnePosition(char* a, char* b)
{
	for(int i=0; i<8; i++)
	{
		if(a[i] == '?') ;
		else if(a[i] != b[i]) return 55;
	}

	return 0;
}

int verificationInvalides(char* entree, char* invalides)
{
	int i=0,j;

	while(invalides[i] != '!')	
	{	
		for(j=0;j<8;j++)
		{
			if (invalides[i] == entree[j]) return 55;
		}
		i++;
	}

	return 0;
}

int verifiationContient(char* entree, char* contient)
{
	int i=0;
	while(contient[i] != '!')
	{
		if (entreeContient(entree,contient[i]) == 55) return 55;
		i++;
	}
	return 0;
}

void purgerEntrees(char* bonneEntrees, char* contient, char* mauvaisePosition, char* invalides)
{
	FILE* inputEntrees = fopen("input/ToutesLesEntrees.txt","r");
	FILE* outputEntrees = fopen("output/entreesValides.txt","w+");
	
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
		if((verificationBonnePosition(bonneEntrees,entree) != 55) && (verifiationContient(entree,contient) != 55) && (verificatonPosition(entree,mauvaisePosition) != 55) && (verificationInvalides(entree,invalides) != 55))
			fprintf(outputEntrees,"%s\n",entree);
		fscanf(inputEntrees,"%c",&lecture);
	}

	fclose(inputEntrees);
	fclose(outputEntrees);
}

void creerToutesEntrees()
{
	FILE* f = fopen("input/ToutesLesEntrees.txt","w+");
	creerEntrees1oper(f);
	creerEntrees2oper(f);
	fprintf(f,"\n#");
	fclose(f);
}

void creerEntrees1oper(FILE* f)
{
	genererEntreesPossiblesOper(f,'-');
	genererEntreesPossiblesOper(f,'+');
	genererEntreesPossiblesOper(f,'/');
	genererEntreesPossiblesOper(f,'*');
}

void creerEntrees2oper(FILE* f)
{
	ListeEntiers* L1;
	ListeEntiers* L2;
	ListeEntiers* L3;
	char oper1[4]; oper1[0] = '+'; oper1[1] = '-'; oper1[2] = '/'; oper1[3] = '*';
	char oper2[4]; oper2[0] = '+'; oper2[1] = '-'; oper2[2] = '/'; oper2[3] = '*';
	int i,j;
	char entree[9];
	int res;


						// generation du type XX oper X oper X = X

	L1 = genererListeEntiersDeuxChiffres();
	L2 = genererListeEntiersUnChiffre();
	L3 = genererListeEntiersUnChiffre();

	Entier* actuel_1 = L1->premier;
	Entier* actuel_2 = L2->premier;
	Entier* actuel_3 = L3->premier;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			while(actuel_1 != NULL)
			{
				while(actuel_2 != NULL)
				{
					while(actuel_3 != NULL)
					{
						res = resultatOperation(resultatOperation(actuel_1->nombre,actuel_2->nombre,oper1[i]),actuel_3->nombre,oper2[j]);
						if(res<10 && res >=0)
						{
							creationEntree2(entree,actuel_1->nombre,actuel_2->nombre,actuel_3->nombre,oper1[i],oper2[j]);
							fprintf(f,"%s\n",entree);
						}
					actuel_3 = actuel_3->suivant;
					}
					actuel_3 = L3->premier;
					actuel_2 = actuel_2->suivant;
				}
				actuel_2 = L2->premier;
				actuel_1 = actuel_1->suivant;
			}
			actuel_1 = L1->premier;
		}
	}



					// generation de type X oper X oper X = XX

	L1 = genererListeEntiersUnChiffre();
	L2 = genererListeEntiersUnChiffre();
	L3 = genererListeEntiersUnChiffre();

	actuel_1 = L1->premier;
	actuel_2 = L2->premier;
	actuel_3 = L3->premier;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			while(actuel_1 != NULL)
			{
				while(actuel_2 != NULL)
				{
					while(actuel_3 != NULL)
					{
						res = resultatOperation(resultatOperation(actuel_1->nombre,actuel_2->nombre,oper1[i]),actuel_3->nombre,oper2[j]);
						if(res>10 && res <100)
						{
							creationEntree2(entree,actuel_1->nombre,actuel_2->nombre,actuel_3->nombre,oper1[i],oper2[j]);
							fprintf(f,"%s\n",entree);
						}
					actuel_3 = actuel_3->suivant;
					}
					actuel_3 = L3->premier;
					actuel_2 = actuel_2->suivant;
				}
				actuel_2 = L2->premier;
				actuel_1 = actuel_1->suivant;
			}
			actuel_1 = L1->premier;
		}
	}
}

int entreeContient(char* entree, char c)
{
	for(int i=0;i<9;i++)
	{
		if(entree[i] == c) return 0;
	}
	return 55;
}

void genererEntreesPossiblesOper(FILE* f,char oper)
{
	ListeEntiers* L1;
	ListeEntiers* L2;

	switch(oper)
	{
		case '-':
			L1 = genererListeEntiersDeuxChiffres();
			L2 = genererListeEntiersDeuxChiffres();
			entreePossibleSoustraction(f,L1,L2);
			break;
		case '*':
			L1 = genererListeEntiersDeuxChiffres();
			L2 = genererListeEntiersUnChiffre();
			entreePossibleMultiplication(f,L1,L2);
			entreePossibleMultiplication(f,L2,L1);
			break;
		case '/':
			L1 = genererListeEntiersTroisChiffres();
			L2 = genererListeEntiersUnChiffre();;
			entreePossibleDivision(f,L1,L2);
			break;
		case '+':
			L1 = genererListeEntiersDeuxChiffres();
			L2 = genererListeEntiersDeuxChiffres();
			entreePossibleAddition(f,L1,L2);
			break;
	}

}

void entreePossibleSoustraction(FILE* f,ListeEntiers* L1, ListeEntiers* L2)
{
	Entier* actuel1 = L1->premier;
	Entier* actuel2 = L2->premier;
	int res;
	char entree[9];
	while(actuel1 != NULL)
	{
		while(actuel2 != NULL)
		{
			res = resultatOperation(actuel1->nombre, actuel2->nombre,'-');
			if(res < 100 && res >= 10 )
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


void entreePossibleDivision(FILE* f, ListeEntiers* L1, ListeEntiers* L2)
{
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
			if(res < 100 )
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

void entreePossibleMultiplication(FILE* f, ListeEntiers* L1, ListeEntiers* L2)
{
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
			if(res >= 100)
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

void entreePossibleAddition(FILE* f, ListeEntiers* L1, ListeEntiers* L2)
{
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
			if(res < 100 )
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
			if(b==0) return 10000;
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

void initialiserContient(char* contient)
{
	contient[0] = '!';
}

void ajouterContient(char* contient,char lecture)
{
	int i=0;
	while(contient[i] != '!')
	{
		if(contient[i] == lecture) return;
		i++;
	}
	contient[i] = lecture;
	contient[i+1] = '!';
}



