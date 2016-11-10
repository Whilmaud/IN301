#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elem ELEM;

struct elem {
  int val;
  struct elem * suiv;
};

typedef ELEM* LISTE;

LISTE creerListeVide()
{
	return NULL;
}

int testListeVide(LISTE l)
{
	if(l == NULL)
	{
		return 1;
	}
	return 0;
}

void afficher_liste(LISTE l)
{
	if(l == NULL)return;
	printf("%d\n",(*l).val);
	afficher_liste((*l).suiv);
}

LISTE ajout_debut_liste(LISTE l,int n)
{
	LISTE a;
	if(!(a = malloc(sizeof(ELEM))))exit(1);
	(*a).val = n;
	(*a).suiv = l;
	return a;
}

LISTE ajout_fin_liste(LISTE l,int n)
{
	LISTE a;
	if(!(a = malloc(sizeof(ELEM))))exit(1);
	if(l == NULL)
	{
		(*a).val = n;
		(*a).suiv = NULL;
		return a;
	}
	(*l).suiv = ajout_fin_liste((*l).suiv,n);
	return l;
}

LISTE ajout_liste_tri(LISTE l,int n)
{
	LISTE a;
	if(!(a = malloc(sizeof(ELEM))))exit(1);
	if(l == NULL)
	{
		(*a).val = n;
		(*a).suiv = NULL;
		return a;
	}
	if(n<(*l).val)
	{
		(*a).val = n;
		(*a).suiv = l;
		return a;
	}
		(*l).suiv = ajout_liste_tri((*l).suiv,n);
		return l;
	
}

int testListeTri(LISTE l)
{
	if((*l).suiv == NULL)
	{
		return 1;
	}
	if((*l).val > (*((*l).suiv)).val)
	{
		return 0;
	}
	return testListeTri((*l).suiv);
	
}

int nombre_elem_liste(LISTE l)
{
	if(l == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + nombre_elem_liste((*l).suiv);
	}
	
}

int recherche_elem(LISTE l,int n)
{
	if(l == NULL)
	{
		return 0;
	}
	if((*l).val == n)
	{
		return 1;
	}
	return recherche_elem((*l).suiv,n);
}

void suppr_elem(LISTE l,int n)
{
	if(l == NULL)
	{
		return;
	}
	if((*l).val == n)
	{
		LISTE a;
		a = (*l).suiv;	
		(*l).val = (*((*l).suiv)).val;	
		(*l).suiv = (*((*l).suiv)).suiv;
		free(a);
		return;
	}
	suppr_elem((*l).suiv,n);
	return;
}

LISTE concatenation_list(LISTE l,LISTE l2)
{
	if(l2 == NULL) return l;
	else if(l == NULL)
	{
		return l2;
	}
	else if((*l).suiv == NULL)
	{
		//~ printf("1");
		(*l).suiv = l2;
		return l;
	}
	else
	{
		(*l).suiv = concatenation_list((*l).suiv,l2);
		return l;
	}
}

//~ LISTE entrela_list(LISTE l,LISTE l2)
//~ {
	//~ if(l == NULL)
	//~ {
		//~ return l2;
	//~ }
	//~ if(l2 == NULL)
	//~ {
		//~ return l;
	//~ }
	//~ 
	//~ LISTE l3,temp;
	//~ l3 = creerListeVide();
	//~ temp = l3;
	//~ 
	//~ if(l->val < l2->val)
	//~ {
			//~ temp->suiv = l->suiv;
			//~ l = l->suiv;
			//~ temp = temp->suiv;
			//~ printf("\n");
			//~ afficher_liste(l3);
		//~ }
		//~ else
		//~ {
			//~ temp->suiv = l2->suiv;
			//~ l2 = l2->suiv;
			//~ temp = temp->suiv;
			//~ printf("\n");
			//~ afficher_liste(l3);
		//~ }
	//~ 
	//~ while(l != NULL || l2 != NULL)
	//~ {
		//~ if(l == NULL)
		//~ {
			//~ temp->suiv = l2;
			//~ return l3;
		//~ }
		//~ if(l2 == NULL)
		//~ {
			//~ temp->suiv = l;
			//~ return l3;
		//~ }
		//~ if(l->val < l2->val)
		//~ {
			//~ temp->suiv = l->suiv;
			//~ l = l->suiv;
			//~ temp = temp->suiv;
			//~ printf("\n");
			//~ afficher_liste(l3);
		//~ }
		//~ else
		//~ {
			//~ temp->suiv = l2->suiv;
			//~ l2 = l2->suiv;
			//~ temp = temp->suiv;
			//~ printf("\n");
			//~ afficher_liste(l3);
		//~ }	
	//~ }
//~ }

int main()
{
	LISTE l;
	LISTE l2;
	int a;
	
	l2 = creerListeVide();
	l = creerListeVide();
	
	l = ajout_debut_liste(l,6);
	l = ajout_debut_liste(l,4);
	l = ajout_debut_liste(l,2);
	l = ajout_fin_liste(l,8);
	l = ajout_liste_tri(l,4);
	suppr_elem(l,4);
	afficher_liste(l);
	
	l2 = ajout_debut_liste(l2,5);
	l2 = ajout_debut_liste(l2,3);
	l2 = ajout_debut_liste(l2,1);
	l2 = ajout_fin_liste(l2,7);
	printf("\n");
	afficher_liste(l2);
	
	//~ l = concatenation_list(l,l2);
	
	//~ printf("\n\n\n");
	
	l = entrela_list(l,l2);
	
	afficher_liste(l);
	
	return 0;
}
