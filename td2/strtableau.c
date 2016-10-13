#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Tableau TABLEAU;

struct Tableau {
  int taille;
  int tab[100];
};

int alea(int n)
{
	int r;
	static int first = 0;
   
	if (first == 0)
	{
		srand (time (NULL));
		first = 1;
	}
	r = rand ();
	return r%(n+1);
}

void init_tableau(TABLEAU *T)
{
	int i;
	(*T).taille = 10;
	for(i = 0;i < (*T).taille;i++)
	{
		(*T).tab[i] = alea(20);
	}
}

void affiche_tableau(TABLEAU *T)
{
	int i;
	
	for(i = 0;i<(*T).taille;i++)
	{
		printf ("%d\n", (*T).tab[i]);
	}
}

long int produit_tableau(TABLEAU *T)
{
	int i,x;
	
	x = 1;
	
	for(i = 0;i<(*T).taille;i++)
	{
		x = x * (*T).tab[i];
	}
	return x;
}

/*int mr()
{
	static int first = 0;
   
   if (first == 0)
   {
      srand (time (NULL));
      first = 1;
   }
   return (rand ());
}*/


int main()
{
	int i;
	TABLEAU T;
	
	init_tableau(&T);
	
	printf("%d\n",T.taille);
	
	affiche_tableau(&T);
	
	printf("%ld\n",produit_tableau(&T));
	
	return 0;
}
