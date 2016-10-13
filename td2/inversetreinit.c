#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inverse(int *p1,int *p2)
{
	int save;
	save = *p1;
	*p1 = *p2;
	*p2 = save;
}

int main()
{
	int a,b;
	a = 4;
	b = 8;
	
	printf("%d   %d\n",a,b);
	inverse(&a,&b);
	printf("%d   %d\n",a,b);
	
	return 0;
}
