#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float racine(float n)
{
	float a1,a2,rac;
	
	a1 = 0.;
	a2 = n;
	rac = (a1+a2)/2.;
	
	while(fabs(n - rac*rac) > 0.0001)
	{
		if(rac*rac < n)
		{
			a1 = rac;
		}
		else
		{
			a2 = rac;
		}
		rac = (a1+a2)/2.;
	}
	
	return rac;
	
}

float S_r(int n,int i)
{
	if(n == 1)
	{
		return 1.;
	}
	if(i == n)
	{
		return racine(n);
	}
	else
	{
		return racine(i + S_r(n,i+1));
	}
}

int main()
{
	int b,n;
	float res;
	
	n = 30;
	
	for(b = 1;b<n+1;b++)
	{
		res = S_r(b,1);
		printf("pour n = %d S_n = %f\n",b,res);
	}
	
	return 0;
}
