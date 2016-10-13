#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	int c,i,d,c2,v2,i2,d2,i3,i10,c73,it;
	
	c = sizeof(char); //1
	printf("%d \n",c);
	
	i = sizeof(int); //4
	printf("%d \n",i);
	
	d = sizeof(double); //8
	printf("%d \n",d);
	
	c2 = sizeof(char*); //8
	printf("%d \n",c2);
	
	v2 = sizeof(void*); //8
	printf("%d \n",v2);
	
	i2 = sizeof(int*); //8
	printf("%d \n",i2);
	
	d2 = sizeof(double*); //8
	printf("%d \n",d2);
	
	i3= sizeof(int**); //8
	printf("%d \n",i3);
	
	i10 = sizeof(int[10]); //40
	printf("%d \n",i10);
	
	c73 = sizeof(char[7][3]); //21
	printf("%d \n",c73);
	
	//it = sizeof(int[]); // ne semble pas foctioner
	//printf("%d \n",it);
	
	printf("test suivant\n");
	
	char tab[10];
	
	c = sizeof(tab); //10
	printf("%d \n",c);
	
	c = sizeof(tab[0]); //1
	printf("%d \n",c);
	
	c = sizeof(&tab[0]); //8
	printf("%d \n",c);
	
	c = sizeof(*&tab); //10
	printf("%d \n",c);
	
	c = sizeof(*&tab[0]); //1
	printf("%d \n",c);
	
	printf("test suivant\n");
	
	char (*p)[10] = &tab;
	
	c = sizeof(p); //8
	printf("%d \n",c);
	
	c = sizeof(*p); //10
	printf("%d \n",c);
	
	c = sizeof((*p)[2]); //1
	printf("%d \n",c);
	
	c = sizeof(&(*p)[2]); //8
	printf("%d \n",c);
	
	return 0;
}
