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

void reinitPointeur(int *p)
{
	int *d;
	d = &p;
	/*printf("%p\n",d);
	printf("%p\n",p);
	printf("\n");*/
	*d = NULL;
	/*printf("%d\n",*d);
	printf("%p\n",d);
	printf("%p\n",p);
	printf("%d\n",*p);*/
}

int main()
{
	int a,b;
	int* p;
	a = 4;
	b = 8;
	
	printf("%d   %d\n",a,b);
	inverse(&a,&b);
	printf("%d   %d\n",a,b);
	
	p = &a;
	
	printf("%p\n",p);
	printf("\n");
	
	reinitPointeur(p);
	
	printf("\n");
	printf("%p\n",p);
	
	return 0;
}
