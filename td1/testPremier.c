#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int test_premier(int N)
{
	float i;
	While(i < sqrt(N))
	{
		
		if(floor(N/i) == N/i)
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
	
	res = test_premier(test);
	
	if(res)
	{
		printf("%d est premier",test);
	}
	else
	{
		printf("%d n'est pas premier premier",test);
	}
	
	return 0;
}
