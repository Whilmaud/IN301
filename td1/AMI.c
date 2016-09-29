#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	int Century ,Boy ,res;
	
	Century = 220;
	Boy = 284;
	
	res = AMI(Century,Boy);
	
	if(res)
	{
		printf("%d et %d sont amis\n",Century, Boy);
	}
	else
	{
		printf("%d et %d ne sont pas amis\n",Century, Boy);
	}
	
	return 0;
	
	return 0;
}	
