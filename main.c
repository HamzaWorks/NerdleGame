#include <stdio.h>
#include <stdlib.h>
#include "main.h"


int main()
{
  	/*if(TEST_ALL=1)
        test();*/
    char s[9];
    creationEntree1(s,100,4,'/');
    printf("%s",s);
    printf("\ntest : %c", charr((100/10)%10));
}
