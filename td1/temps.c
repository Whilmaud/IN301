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
	int s,m,h;
	m = h = 0;
	
	s = 0;
	
	if(s == 0 || s == 1) // si il y a 1 ou 0 sec on print directement sans calcule pour avoir 
	{					 // seconde au singulier
		printf("\n %d seconde corespond a %d heure %d minute %d seconde \n",s,h,m,s);
	}
	else
	{
		division_s(&s,&m,&h);
	
		printf("%d secondes ",s);
	}
	return 0;
}
