/*
 ============================================================================
 Name        : LIFO_main.c
 Author      : Stefan Entacher
 Version     :
 Copyright   : 
 Description : LIFO mit Liste
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
	printf("Erstellt einen Stack mit Hilfe einer Liste Liste und befuellt diese mit Zufallszahlen.\n");
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
		push(list,rand()%10+1);
		printf("%d. Element in die Stack hinzugefuegt.\n",i+1);
	}
	getchar();

	//Element mit POP entfernen
	printf("Laenge des Stacks vor pop(): %d\n", list->len);
	printf("Wert des entfernten Elements: %d\n",pop(list));
	printf("Laenge des Stacks nach pop(): %d\n", list->len);
	fflush(stdout);
	getchar();

	//Element mit TOP ausgeben
	printf("Laenge des Stacks vor top(): %d\n", list->len);
	printf("Wert des ersten Elements: %d\n",top(list));
	printf("Laenge des Stacks nach top(): %d\n", list->len);
	fflush(stdout);
	getchar();

	//Pruefen, ob Stack leer
	if (empty(list)==0) printf("Stack ist leer.\n");
	else printf("Stack ist nicht leer.\n");
	fflush(stdout);
	getchar();

	//Ausgabe Laenge Stack
	printf("Laenge des Stacks: %d",lenght(list));
	fflush(stdout);
	getchar();

	//Stack loeschen (selbe Funkton wie SList
	rm_SList(list);
	printf("Liste geloescht, Programm wird beendet.\n");
	printf("Weiter mit ENTER...\n");

	return EXIT_SUCCESS;
}
