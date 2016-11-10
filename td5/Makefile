all : principale
	./principale
	
principale : circonference.o surface.o principale.o
	gcc -Wall -o principale principale.o circonference.o surface.o
	
circonference.o : circonference.c circonference.h pi.h
	gcc -c -Wall circonference.c
	
surface.o : surface.c surface.h pi.h
	gcc -c -Wall surface.c
	
principale.o : principale.c circonference.h surface.h
	gcc -c -Wall principale.c
	
clear : 
	rm -f principale
	rm -f circonference.o
	rm -f surface.o
	rm -f principale.o
