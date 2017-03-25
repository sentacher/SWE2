/*
 ============================================================================
 Name        : DEQUE_main.c
 Author      : Stefan Entacher
 Version     :
 Copyright   : 
 Description : Deque (Double-ended queue)
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
	printf("Erstellt eine Deque mit Hilfe einer Liste  und befuellt diese mit Zufallszahlen.\n");
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

	//Elemente erzeugen und hinten anfuegen
	for(i=0;i<ELEM;i++){
		insert_back(list,rand()%10+1);
		printf("%d. Element in die Deque hinten hinzugefuegt.\n",i+1);
	}
	getchar();

	//Elemente erzeugen und vorne anfuegen
	for(i=0;i<ELEM;i++){
		insert_front(list,rand()%10+1);
		printf("%d. Element in die Deque vorne hinzugefuegt.\n",i+1);
	}
	getchar();

	//Element vorne entfernen
	printf("Laenge der Deque vor remove_element_at_front(): %d\n", list->len);
	printf("Wert des entfernten Elements: %d\n",remove_element_at_front(list));
	printf("Laenge der Deque nach remove_element_at_front(): %d\n", list->len);
	fflush(stdout);
	getchar();

	//Element hinten entfernen
	printf("Laenge der Deque vor remove_element_at_back(): %d\n", list->len);
	printf("Wert des entfernten Elements: %d\n",remove_element_at_back(list));
	printf("Laenge der Deque nach remove_element_at_back(): %d\n", list->len);
	fflush(stdout);
	getchar();

	//Element mit examine_first_element ausgeben
	printf("Laenge der Deque vor examine_first_element(): %d\n", list->len);
	printf("Wert des ersten Elements: %d\n",examine_first_element(list));
	printf("Laenge der Deque nach examine_first_element(): %d\n", list->len);
	fflush(stdout);
	getchar();

	//Element mit examine_last_element ausgeben
	printf("Laenge der Queue vor examine_last_element(): %d\n", list->len);
	printf("Wert des letzen Elements: %d\n",examine_last_element(list));
	printf("Laenge der Queue nach examine_last_element(): %d\n", list->len);
	fflush(stdout);
	getchar();

	//Pruefen, ob Deque leer
	if (empty(list)==0) printf("Deque ist leer.\n");
	else printf("Deque ist nicht leer.\n");
	fflush(stdout);
	getchar();

	//Deque loeschen (selbe Funkton wie SList)
	rm_SList(list);
	printf("Liste geloescht, Programm wird beendet.\n");
	printf("Weiter mit ENTER...\n");

	return EXIT_SUCCESS;
}
