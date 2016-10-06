#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void inser_T_tri(int T[],int n) // j'en suis ici
{
	int i;
	
	while(T(i)
	
	
}


int main()
{
	int T[4],i;
	
	T[0] = 45;
	T[1] = 97;
	T[2] = 4;
	T[3] = 36;
	
		
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
	
	return 0;
}
