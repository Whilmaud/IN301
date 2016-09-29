#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void division_s(int *s, int * m,int *h)
{
	*m = *s/60;
	*s = *s%60;
	*h = *m/60;
	*m = *m%60;
}

int main()
{
	int s,m,h,Save_s;
	m = h = 0;
	
	scanf("%d", &s);
	
	Save_s = s;
	
	if(s == 0 || s == 1) // si il y a 1 ou 0 sec on print directement sans calcule pour avoir 
	{					 // seconde au singulier
		printf("\n %d seconde corespond a %d heure %d minute %d seconde \n",Save_s,h,m,s);
	}
	else if(s < 60) 
	{	
		printf("\n %d secondes corespond a %d heure %d minute %d secondes \n",Save_s,h,m,s);
	}
	else
	{
		division_s(&s,&m,&h);
		
		if(h == 0 || h == 1)
		{
			if(m == 0 || m == 1)
			{
				if(s == 0 || m == 1)
				{
					printf("\n %d secondes corespond a %d heure %d minute %d seconde \n",Save_s,h,m,s);
				}
				else
				{
					printf("\n %d secondes corespond a %d heure %d minute %d secondes \n",Save_s,h,m,s);
				}
			}
			else
			{
				if(s == 0 || m == 1)
				{
					printf("\n %d secondes corespond a %d heure %d minutes %d seconde \n",Save_s,h,m,s);
				}
				else
				{
					printf("\n %d secondes corespond a %d heure %d minutes %d secondes \n",Save_s,h,m,s);
				}
			}
		}
		else
		{
			if(m == 0 || m == 1)
			{
				if(s == 0 || m == 1)
				{
					printf("\n %d secondes corespond a %d heures %d minute %d seconde \n",Save_s,h,m,s);
				}
				else
				{
					printf("\n %d secondes corespond a %d heures %d minute %d secondes \n",Save_s,h,m,s);
				}
			}
			else
			{
				if(s == 0 || m == 1)
				{
					printf("\n %d secondes corespond a %d heures %d minutes %d seconde \n",Save_s,h,m,s);
				}
				else
				{
					printf("\n %d secondes corespond a %d heures %d minutes %d secondes \n",Save_s,h,m,s);
				}
			}
		}
	}
	
	return 0;
}
