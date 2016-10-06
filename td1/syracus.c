#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int syrac_count(int u0)
{
	int count;
	count = 0;
	
	while(u0 != 1)
	{
		if(u0 & 1)
		{
			u0 = 3*u0+1;
		}
		else
		{
			u0 = u0 >> 1;
		}
			
		count++;
	}
	
	//printf("%d\n",count);
	
	return count;
}

int main()
{
	int n,i,o;
	
	n = 41;
	
	for(i = 1;i<n+1;i++)
	{
		o = syrac_count(i);
		printf("%d prend %d operation\n",i,o);
	}
	
	return 0;
}
