#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int test_premier(int N)
{
	int i;
	i = 2;
	while(i < N)
	{
		
		if(N%i == 0)
		{
			return 0;
		}
		i = i+1.;
	}
	return 1;
}

int main()
{
	int test,res;
	
	scanf("%d",&test);
	
	res = test_premier(test);
	
	if(res)
	{
		printf("%d est premier\n",test);
	}
	else
	{
		printf("%d n'est pas premier premier\n",test);
	}
	
	return 0;
}
