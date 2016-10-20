#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alea(int n)
{
	int r;
	static int first = 0;
   
	if (first == 0)
	{
		printf("a\n");
		srand(time (NULL));
		first = 1;
	}
	r = rand ();
	printf("%d\n",r);
	return r%(n+1);
}

void suppr_double_tableau(int T[],int n)
{
	int i;
	
	if(n == 1)return;
	
	if(T[0] == -1)
	{
		suppr_double_tableau((T+1),n-1);
		return;
	}
	
	for(i = 1;i < n;i++)
	{
		if(T[i] == T[0])
		{
			T[i] = -1;
		}
	}
	
	suppr_double_tableau((T+1),n-1);
}

int main()
{
	int T[60],T2[60],i,c;
	
	for(i = 0;i<60;i++)
	{
		T[i] = alea(99);
	}
	
	T2[60] = T[60];
	
	suppr_double_tableau(T2,60);
	
	c = 0;
	
	for(i = 0;i<60;i++)
	{
		if(T2[i] != -1)
		{
			c++;
		}
	}
	
	printf("%d\n",c);
	
	return 0;
}
