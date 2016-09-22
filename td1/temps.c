#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void division_s(int *s, int * m,int *h)
{
	*m = *s/60;
	*s = *s%60;
	*h = *m/60;
	*m = *m%60;
}

int main()
{
	int s,m,h;
	
	division_s(&s,&m,&h);
	
	printf("")
	
	return 0;
}
