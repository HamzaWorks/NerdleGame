#include "entree.h"

char* creationEntree1(int a, int b, char oper)
{
	char entree[9];
	entree[8] = '\0';
	if(a>10 && b > 10)
	{
		entree[0] = charr(a/10);
		entree[1] = charr(a%10);
		entree[2] = oper;
		entree[3] = charr(b/10);
		entree[4] = charr(b%10); 
		entree[5] = '=';
		switch (oper)
			{
				case '-':
					entree[6] = charr((a-b)/10);
					entree[7] = charr((a-b)%10);
					break;

				case '+':
					entree[6] = charr((a+b)/10);
					entree[7] = charr((a+b)%10);
					break;

				default:
					break;
			}
	}

	return &entree;

}

int intt(char c)
{
	return (c - '0');
}

char charr(int n)
{
	return (n + '0');
}