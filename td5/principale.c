#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "circonference.h"
#include "surface.h"


int main()
{
	int rayon, circ,surf;
	
	scanf("%d",&rayon);
	
	circ = circonference(rayon);
	surf = surface(rayon);
	
	printf("le périmetre d'un cercle de rayon %d cm est de %d cm et sa surface est de %d cm carré",rayon,circ,surf);
	
	return 0;
}
