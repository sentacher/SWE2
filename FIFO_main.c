/*
 ============================================================================
 Name        : FIFO_main.c
 Author      : Stefan Entacher
 Version     :
 Copyright   : 
 Description : FIFO mit Liste
 ============================================================================
 */

//Benoetigte Bibliotheken importieren
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

#define ELEM 5

int main(void) {
	//Begruessungstext
	printf("Erstellt eine Queue mit Hilfe einer Liste und befuellt diese mit Zufallszahlen.\n");
	printf("Weiter mit ENTER...\n");
	fflush(stdout);
	getchar();

	//Variablen initialisieren
	int i=0;
	time_t t;
	time(&t);

	//Liste erstellen
	SLIST_HEADER *list;
	list = createList();

	//Zufallsgenerator initialisieren
	srand((unsigned int)t);

	//Elemente erzeugen und vorne anfuegen
	for(i=0;i<ELEM;i++){
		put(list,rand()%10+1);
		printf("%d. Element in die Queue hinzugefuegt.\n",i+1);
	}
	getchar();

	//Element mit GET entfernen
	printf("Laenge der Queue vor get(): %d\n", list->len);
	printf("Wert des entfernten Elements: %d\n",get(list));
	printf("Laenge der Queue nach get(): %d\n", list->len);
	fflush(stdout);
	getchar();

	//Element mit last ausgeben
	printf("Laenge der Queue vor last(): %d\n", list->len);
	printf("Wert des ersten Elements: %d\n",last(list));
	printf("Laenge der Queue nach last(): %d\n", list->len);
	fflush(stdout);
	getchar();

	//Element mit next ausgeben
	printf("Laenge der Queue vor next(): %d\n", list->len);
	printf("Wert des letzen Elements: %d\n",next(list));
	printf("Laenge der Queue nach next(): %d\n", list->len);
	fflush(stdout);
	getchar();

	//Pruefen, ob Queue leer
	if (empty(list)==0) printf("Queue ist leer.\n");
	else printf("Queue ist nicht leer.\n");
	fflush(stdout);
	getchar();

	//Ausgabe Laenge Queue
	printf("Laenge der Queue: %d",lenght(list));
	fflush(stdout);
	getchar();

	//Queue loeschen (selbe Funkton wie SList
	rm_SList(list);
	printf("Liste geloescht, Programm wird beendet.\n");
	printf("Weiter mit ENTER...\n");

	return EXIT_SUCCESS;
}
