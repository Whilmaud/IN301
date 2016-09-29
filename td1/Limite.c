#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main()
{
	float S,i;
	S = 0. ;
	i = 1. ;
	
	while((S+(1/(i*i)) - S) > 0.0001)
	{
		S = S+(1/(i*i));
		i = i + 1.;
	}
	
	printf("%f\n",S);
	
	return 0;
}
