/*
 ============================================================================
 Name        : SortANum.c
 Author      : Stefan Entacher
 Version     :
 Copyright   : 
 Description : Liest uebr die CLI Werte ein und sortiert diese
 ============================================================================
 */

//Benoetigte Bibliotheken
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortanum.h"

int main (int argc, char *argv[]){

	//Hilfetest aufrufen
	if (argc==1) {
		help();
		return EXIT_SUCCESS;
	}

	//Variablen definieren
	int i=0;
	int *p=NULL;

	//Speicher zuweisen
	p=malloc(argc*sizeof(int));
	if(p==NULL){
		printf("Es konnte kein Speicher zugewiesen werden.\n");
		return EXIT_FAILURE;
	}

	//Werte uebergeben
	for (i=1;i<argc-1;i++){
		//ATOI = ASCII to Integer
		p[i-1]=atoi(argv[i]);
	}

	//Array sortiern
	qsort(p,argc-1,sizeof(int),cmpfunc);

	//Ausgabe sortiert
	printf("Sortiertes Array: \n");
	for (i=0;i<argc-1;i++){
		printf("%d ",p[i]);
	}

	return EXIT_SUCCESS;
}
