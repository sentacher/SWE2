/*
 ============================================================================
 Name        : CreateFile.c
 Author      : Stefan Entacher
 Version     :
 Copyright   : 
 Description : Erstellt ein Programm, welches Zahlen in eine Textfile ensliest
 ============================================================================
 */

//Benoetigte Bibliotheken inkludieren
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Fuer Zufallszahlengenerator
#include <time.h>

//Funktion help
void help()
{
	printf("Aufruf: CreateFile [Option] File\n"\
			"Option Beschreibung:\n"\
			"\t-h Hilfe\n"\
			"\t-n Anzahl der Zahlen (default 100)\n"\
			"\t-r Zahlenbereich (default = 100)\n"\
			"Aufrufbeispiel:\n"\
			"./CreateFile -n 3 -r 1000 ausgabe.txt\n\n");
}

int main(int argc, char *argv[]){
	//Wen kein Argument oder -h
	if( argc==1 || strcmp(argv[1], "-h") == 0 )
	{
		help();
		return EXIT_SUCCESS;
	}

	//Variablen definieren
	int i=0, anz = 100, bereich = 100;
	int *zahlen;
	FILE *file;
	time_t t;
	time(&t);

	//Abfrage Argument (Anfang i=1)
	for(i=1; i < argc; i++){

		//Argument -n
		if( strcmp(argv[i],"-n") == 0 ){
			anz = atoi(argv[i+1]);
			i++;
		}

		//Wen Argument -r
		else if( strcmp(argv[i],"-r") == 0 ){
			bereich = atoi(argv[i+1]);
			i++;
		}

		//Argument Textfile
		else if( strstr(argv[i], ".txt") != NULL){
			file = fopen(argv[i], "wt");
			if(NULL == file){
				printf("Datei konnte nicht erstellt werden!\n");
				return EXIT_FAILURE;
			}
		}
	}

	//Zufallszahlengenerator initialisieren
	srand((unsigned int)t);

	//Textdatei mit Zufallszahlen befuellen
	zahlen = malloc(anz*sizeof(int));
	for(i=0; i < anz; i++){
		zahlen[i] = rand() % bereich;
		fprintf(file,"%d\n", zahlen[i]);
	}

	//File schliessen
	fclose(file);

	return EXIT_SUCCESS;
}
