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

int pos_minim_tableau(TABLEAU *T)
{
	int i,pmin;
	
	pmin = 0;
	
	for(i = 1;i<(*T).taille;i++)
	{
		if((*T).tab[pmin] > (*T).tab[i])
		{
			pmin = i;
		}
	}
	return pmin;
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

void insere_tableau_tris(int n,TABLEAU *T)
{
	int i,j;
	
	i = 0;
	
	while(n > (*T).tab[i])
	{
		i++;
	}
	printf("%d\n",i);

	

	for(j = (*T).taille;j != i;j--)
	{
		(*T).tab[j] = (*T).tab[j-1];
	}
	(*T).taille++;
	(*T).tab[i] = n;
	
}

void tris_tableau_bulle(TABLEAU *T)
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

void tris_tableau_insertion(TABLEAU *T)
{
	int sT;
	
	sT = (*T).taille;
	(*T).taille = 1;
	
	while((*T).taille != sT)
	{
		insere_tableau_tris((*T).tab[(*T).taille],&(*T));
	}

}

void tris_tableau_selection(TABLEAU *T)
{
	TABLEAU T2;
	int i,pmin;
	
	for(i = 0;i < (*T).taille;i++)
	{
		T2.taille = (*T).taille-i;
		T2.tab = ((*T).(tab+1));
		pmin = i + pos_minim_tableau(&T2);
		inverse(&((*T).tab[i]),&((*T).tab[pmin]));
	}
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

void suppr_double_str_tableau(TABLEAU *T) // a refaire ?
{
	int j,i;
	
	for(i = 0;i < (*T).taille;i++)
	{
		for(j = i+1;j < (*T).taille;j++)
		{
			if((*T).tab[j] == (*T).tab[i])
			{
				(*T).taille--;
				inverse(&((*T).tab[j]),&((*T).tab[(*T).taille]));
				j--;
			}
		}
	}

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
	
	//printf("%d\n",T.taille);
	
	affiche_tableau(&T);
	
	//printf("%ld\n",produit_tableau(&T));
	//printf("%d\n",minim_tableau(&T));
	
	printf("post décal\n");
	
	decal_tableau(&T);
	//affiche_tableau(&T);
	
	printf("post tris\n");
	tris_tableau_insertion(&T);
	//affiche_tableau(&T);
	
	printf("post insere\n");
	insere_tableau_tris(10,&T);
	//affiche_tableau(&T);
	
	printf("post inverse\n");
	//inverse_tableau(&T);
	//affiche_tableau(&T);
	
	printf("post suppr_alea\n");
	//suppr_alea_tableau(&T);
	//affiche_tableau(&T);
	
	//suppr_double_str_tableau(&T);
	affiche_tableau(&T);
	
	return 0;
}
