#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int X_egypte(int a,int b, int add)
{
	
	if(a ==1)
	{	
		printf("= %d x %d + %d\n",a,b,add);
		return b;
	}
	
	if(a%2 == 0)
	{
		if(add != 0)
		{
			printf("= %d x %d + %d\n",a,b,add);
		}
		else 
		{
			printf("= %d x %d\n",a,b);
		}
		return X_egypte(a/2,b*2,add);
	}
	else
	{
		if(add != 0)
		{
			printf("= %d x %d + %d\n",a,b,add);
		}
		else 
		{
			printf("= %d x %d\n",a,b);
		}
		add +=b;
		return X_egypte(a-1,b,add)+b;
	}
}

int main()
{
	int a,b,add,res;
	
	add = 0;
	printf("premier nombre:");
	scanf("%d", &a);
	printf("second nombre :");
	scanf("%d", &b);
	printf("%d x %d\n",a,b);
	res = X_egypte(a,b,add);
	
	printf("= %d \n",res);
	
	return 0;
}
