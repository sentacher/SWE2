/*
 ============================================================================
 Name        : SortArray.c
 Author      : Stefan Entacher
 Version     :
 Copyright   : 
 Description : Sortiert ein Array
 ============================================================================
 */

//Benoetigte Bibliotheken inkludieren
#include <stdio.h>
#include <stdlib.h>

//Cmpfunc fuer qsort
int cmpfunc(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main(){
	//Variablen definieren
	int array[10] = {17, 23, 90, 67, 6, 8, 31, 76, 27, 99};
	int i=0;

	//Ausgabe Array unsortiert
	printf("Array unsortiert:\n");
	for(i=0;i<10;i++){
		printf("%d. Zahl = %d\n",i+1,array[i]);
	}

	// sort with qsort-function
	qsort(array, 10, sizeof(int), cmpfunc);

	getchar();

	//Ausgabe Array unsortiert
	printf("Array sortiert:\n");
	for(i=0;i<10;i++){
		printf("%d. Zahl = %d\n",i+1,array[i]);
	}

	return EXIT_SUCCESS;
}
