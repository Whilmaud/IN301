#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Tableau TABLEAU;

struct Tableau {
  int taille;
  int tab[100];
};

void inverse(int *p1,int *p2)
{
	int save;
	save = *p1;
	*p1 = *p2;
	*p2 = save;
}

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
	long int i,x;
	
	x = 1;
	
	for(i = 0;i<(*T).taille;i++)
	{
		x = x * (*T).tab[i];
	}
	return x;
}

int minim_tableau(TABLEAU *T)
{
	int i,min;
	
	min = (*T).tab[0];
	
	for(i = 1;i<(*T).taille;i++)
	{
		if(min > (*T).tab[i])
		{
			min = (*T).tab[i];
		}
	}
	return min;
}

void decal_tableau(TABLEAU *T)
{
	int i;
	(*T).taille++;
	for(i = (*T).taille;i > 0;i--)
	{
		(*T).tab[i] = (*T).tab[i-1];
	}
	(*T).tab[0] = 0;
}

void tris_tableau(TABLEAU *T)
{
	int i,j;
	
	for(i = 0;i < (*T).taille;i++)
	{
		for(j = (*T).taille-1;j>i;j--)
		{
			if((*T).tab[j]<(*T).tab[j-1])
			{
				inverse(&(*T).tab[j],&(*T).tab[j-1]);
			}
		}
	}
}

void insere_tableau_tris(int n,TABLEAU *T)
{
	int i,j;
	
	i = 0;
	
	while(n > (*T).tab[i])
	{
		i++;
	}

	(*T).taille++;
	for(j = (*T).taille;j > i;j--)
	{
		(*T).tab[j] = (*T).tab[j-1];
	}
	(*T).tab[i] = n;
	
}
void inverse_tableau(TABLEAU *T)
{
	int i;
	
	for(i = 0;i < ((*T).taille)/2;i++)
	{
		inverse(&(*T).tab[i],&(*T).tab[(*T).taille -1 -i]);
	}
}

void suppr_alea_tableau(TABLEAU *T)
{
	int n;
	int i;
	
	n = alea((*T).taille);
	printf("n = %d\n",n);
	for(i = n;i < (*T).taille;i++)
	{
		(*T).tab[i] = (*T).tab[i+1];
	}
	(*T).taille--;
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
	
	//affiche_tableau(&T);
	
	//printf("%ld\n",produit_tableau(&T));
	//printf("%d\n",minim_tableau(&T));
	
	printf("post décal\n");
	
	decal_tableau(&T);
	//affiche_tableau(&T);
	
	printf("post tris\n");
	tris_tableau(&T);
	//affiche_tableau(&T);
	
	printf("post insere\n");
	insere_tableau_tris(10,&T);
	//affiche_tableau(&T);
	
	printf("post inverse\n");
	inverse_tableau(&T);
	affiche_tableau(&T);
	
	printf("post suppr_alea\n");
	suppr_alea_tableau(&T);
	affiche_tableau(&T);
	
	return 0;
}
