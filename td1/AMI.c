#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int AMI(int Century,int Boy)
{
	int i,Somme;
	Somme = 0;
	i = 1;

	Somme = calcul_somme_diviseur(Century);
	
	if(Somme == Boy)
	{	
		Somme = calcul_somme_diviseur(Boy);
		
		if(Somme == Century)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int AMIbis(int Century,int Boy)
{
	int i,Somme;	
	Somme = calcul_somme_diviseur(Boy);
		
	if(Somme == Century)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int calcul_somme_diviseur(int n)
{
	int i,Somme;
	i = 1;
	Somme = 0;
	while(i < n)
	{
		if(n%i == 0)
		{
			Somme += i;
		}
		i = i+1;
	}
	
	return Somme;
}

void ALL_AMI(int CenturyBoy)
{
	int Century ,Boy, res;
	
	for(Century = 0; Century < CenturyBoy+1;Century++)
	{
		Boy = calcul_somme_diviseur(Century);
		res = AMIbis(Century,Boy);
		if(res)
		{
			printf("%d et %d sont amis\n",Century, Boy);
		}
	}
}

int main()
{
	int CenturyBoy = 100000;
	
	ALL_AMI(CenturyBoy);
	
	return 0;
}	
