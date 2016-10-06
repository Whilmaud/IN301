#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float racine(int n)
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

int main()
{
	int n;
	float rac;
	
	scanf("%d",&n);
	
	rac = racine(n);
	
	printf("%f est la racine de %d\n",rac,n);
	
	return 0;
}
