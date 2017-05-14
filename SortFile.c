/*
 ============================================================================
 Name        : SortFile.c
 Author      : Stefan Entacher
 Version     :
 Copyright   : 
 Description : Liest ein File mit Zahlen ein und gibt dieses sortiert aus
 ============================================================================
 */

//Bibliotheken inkludieren
#include <stdio.h>
#include <stdlib.h>
#define BEREICH 100

//Fuer qsort()
int cmpfunc(void const *a, void const *b){
	return *(int*)a - *(int*)b;
}


int main(){
	//Variablen definieren
	int i=0, anz=1, ch=0;
	int *zahlen;
	char buf[BEREICH];

	//File oeffnen
	FILE *file = fopen("test.txt", "rt");
	FILE *sort = fopen("sort.txt","wt");
	if(NULL == file || NULL == sort){
		printf("Datei konnte nicht geoeffnet werden!\n");
		return EXIT_FAILURE;
	}

	//Anzahl Zahlen (Zeilen) ermitteln
	while( (ch=fgetc(file)) != EOF ) if(ch == '\n') anz++;

	//Filepointer zuruecksetzen
	rewind(file);
	zahlen = malloc(anz*sizeof(int));

	for(i=0; i < anz; i++){
		fgets(buf, 100, file);
		zahlen[i] = atoi(buf);
	}

	// Sortieren mit qsort
	qsort(zahlen, anz, sizeof(int), cmpfunc);

	//Ausgabe Textfile
	for(i=0; i < anz; i++){
		fprintf(sort,"%d\n", zahlen[i]);
	}

	fclose(file);
	fclose(sort);
	return EXIT_SUCCESS;
}
