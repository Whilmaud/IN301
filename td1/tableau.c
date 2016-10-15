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

void tableau_1(int T[],int n)
{
	int i;
	
	for(i = 0;i<n;i++)
	{
		T[i] = 1;
	}
}

int xTableau(int T[],int n)
{
	int i,x;
	
	x = 1;
	
	for(i = 0;i<n;i++)
	{
		x = x*T[i];
	}
	return x;
}

int min_tableau(int T[], int n)
{
	int min,i;
	
	min = T[0];
	
	for(i = 1;i<n;i++)
	{
		if(T[i] < min)
		{
			min = T[i];
		}
	}
	
	return min;
}

void decalage_tableau(int T[],int n)
{
	int i;
	
	for(i = n-1;i>0;i--)
	{
		T[i] = T[i-1];
	} 
	
	T[0] = 0;
}

void inverse_tableau(int T[],int n)
{
	int i;
	
	for(i = 0;i < n/2;i++)
	{
		inverse(&T[i],&T[n -1 -i]);
	}
}


void inser_T_tri(int T[],int n,int e) // j'en suis ici
{
	if(e > T[n-1]) return;
	
	int i;
	
	i = 0;
	
	while(e > T[i])
	{
		i++;
	}
	
	decalage_tableau((T+i),n-i);
	
	T[i] = e;
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

float moy_prod_sect(int T[],int n)
{
	int i,j;
	float moy,c,p;
	
	moy = 0.;
	j = 0;
	i = 0;
	p = 1.;
	c = 0.;
	
	while(i != n)
	{
		if(T[i] == 0 && j != 0)
		{
			moy = moy*c + p;
			c = c+1;
			moy = moy/c;
			j = 0;
			p = 1.;
		}
		else if(T[i] != 0)
		{
			p = T[i] * p;
			//printf("%f\n",p);
			j++;
		}
		i++;
	}
	
	if(T[n-1] != 0)
	{
		moy = moy*c + p;
		c = c+1;
		moy = moy/c;
	}
	
	return moy;
}


int main()
{
	int T[9],i;
	float y;
	
	T[0] = 3;
	T[1] = 2;
	T[2] = 0;
	T[3] = 0;
	T[4] = 5;
	T[5] = 4;
	T[6] = 0;
	T[7] = 0;
	T[8] = 2;
	
	
		
	/*
 
	for(i = 0;i<4;i++)
	{
		printf("%d\n",T[i]);
	} 
	
	printf("\n");
	
	decalage_tableau(T,4);
	
	for(i = 0;i<4;i++)
	{
		printf("%d\n",T[i]);
	}
	
	printf("\n");
	
	inser_T_tri(T,4,15);
	
	for(i = 0;i<4;i++)
	{
		printf("%d\n",T[i]);
	}
	
	printf("\n");
	
	inverse_tableau(T,4);
	
	for(i = 0;i<4;i++)
	{
		printf("%d\n",T[i]);
	}
	
	*/
	
	/*for(i = 0;i<9;i++)
	{
		printf("%d\n",T[i]);
	}
	
	suppr_double_tableau(T,9);
	
	printf("\n");
	
	for(i = 0;i<9;i++)
	{
		printf("%d\n",T[i]);
	}*/
	
	y = moy_prod_sect(T,9);
	
	printf("%f\n",y);
	
	return 0;
}
