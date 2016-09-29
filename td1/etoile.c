#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* on va creer des etoiles*/

int main()
{
	int i ,y;
	
	for(i = 0;i<10;i++)
	{
		for(y = 0;y < 9-i;y++)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
	return 0;
}
