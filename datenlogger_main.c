/*
 ============================================================================
 Name        : datenlogger_ini.c
 Author      : Stefan Entacher
 Version     :
 Copyright   : 
 Description : Liest eine INI-File ein und speichert dessen Werte in eine dynamische Datenstruktur
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ini_head.h"
#define MAX 1024

int main(void) {

//Begruessungstext
	printf("Erstellt eine Liste und fuegt die ausgelesenen INI Werte ein.\n");
	printf("Weiter mit ENTER...\n");
	fflush(stdout);
	getchar();

	//Datei oeffnen bzw. ggf. erstellen
	FILE *datei = fopen("datenlogger.ini", "rt");
	if (datei == NULL){
		printf("Fehler beim Oeffnen der Datei.");
		return EXIT_FAILURE;
	}

	//Variablen initialisieren

	int i=1;
	printf("Weiter mit ENTER...\n");
	getchar();
	char buffer[MAX];
	char delimiter[] = "=";
	char *key, *val;

	//Liste erstellen
	INI_HEADER *list;
	list = createList();

	//Elemente auslesen und einfuegen vorne anfuegen

	//Filepointer auf Anfang setzen
	//Zeilen zaeheln
	rewind(datei);
	while(fgets(buffer,MAX,datei)){

		//Ueberpruefen ob Kommentar
		if (buffer[0]==';' || buffer[0] == '['){
			printf("Kommentar in Zeile %d gefunden.\n",i);
		}
		else{
			//String zerlegen
			//Werte in die Liste einfuegen
			key = strtok(buffer, delimiter);
			val = strtok(NULL, delimiter);
			insert(list,key,val);
			printf("%d. Zeile ausgelesen und in die Liste eingefuegt.\n",i);
			printf("Weiter mit ENTER...\n");
		}
		i++;
	}

	//Ausgabe der Liste
	printini(list);
	return EXIT_SUCCESS;
}
