#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Tableau TABLEAU;

struct Tableau {
  int taille;
  int tab[100];
};

/*int alea(int n)
{
	
}*/

int mr()
{
	return rand();
}


int main()
{
	int i;
	for(i = 0;i<100;i++)
	{
		printf ("%d\n", mr());
	}
	
	return 0;
}
