#include "entree.h"

/*char* creationEntree1(int a, int b, char oper)
{
	char entree[8];
	if(a>10 && b > 10)
	{
		entree
	}







	char entree[8];
	int i = 0;
	if (a<10)
	{
		entree[i]=charr(a);
		i++;
	}
	else
	{
		entree[i]=charr(a/10);
		i++;
		entree[i]=charr(a%10);
		i++;
	}
	entree[i]=oper;

	return &entree;

}*/

int intt(char c)
{
	return (c - '0');
}

char charr(int n)
{
	return (n + '0');
}