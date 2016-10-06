#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ALL_AMI(int CenturyBoy)
{
	int Century ,Boy, res;
	
	for(Century = 0; Century < CenturyBoy+1;Century++)
	{
		for(Boy = 0; Boy < Century+1;Boy++)
		{
			res = 0;
			res = AMI(Century,Boy);
			if(res)
			{
				printf("%d et %d sont amis\n",Century, Boy);
			}
		}
	}
}

int AMI(int Century,int Boy)
{
	int i,Somme;
	Somme = 0;
	i = 1;
	while(i < Century)
	{
		
		if(Century%i == 0)
		{
			Somme += i;
		}
		i = i+1;
	}
	if(Somme == Boy)
	{
		i = 1;
		Somme = 0;
		while(i < Boy)
		{
		
			if(Boy%i == 0)
			{
				Somme += i;
			}
			i = i+1;
		}
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
int main()
{
	int CenturyBoy = 285;
	
	ALL_AMI(CenturyBoy);
	
	return 0;
}	
