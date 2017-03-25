/*
 ============================================================================
 Name        : func.c
 Author      : Stefan Entacher
 Version     :
 Copyright   :
 Description : Funktionen SWE2 - Uebung 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Funktion SLIST_HEADER
extern SLIST_HEADER *createList(){

	//Speicher reservieren
	SLIST_HEADER *head;
	head=malloc(sizeof(SLIST_HEADER));
	if(!head) {
		printf ("Fehler beim allokieren des Speichers.\n");
		return NULL;
	}

	head->len=0;
	head->First = NULL;
	head->Last = NULL;
	return head;
}

//Funktion Insert First
extern SLIST *insertFirst(SLIST_HEADER *head,int data){

	//Speicher reservieren
	SLIST *entry;
	entry=malloc(sizeof(SLIST));
	if (!entry){
		printf ("Fehler beim allokieren des Speichers.\n");
		return NULL;
	}

	//Wenn erstes Element der Liste
	if(head->len==0){
		entry->Next=NULL;
		entry->Prev=NULL;
		entry->Data=data;
		head->First=entry;
		head->Last=entry;
	}

	else{
		entry->Next=head->First;
		entry->Prev=NULL;
		entry->Data=data;
		entry->Next->Prev=entry;
		head->First=entry;

	}

	head->len++;
	return entry;
}

//Funktion Insert Last
extern SLIST *insertLast(SLIST_HEADER *head,int data){

	//Speicher reservieren
	SLIST *entry;
	entry=malloc(sizeof(SLIST));

	if (NULL== entry){
		printf ("Fehler beim allokieren des Speichers.\n");
		return NULL;
	}

	//Wenn erstes Element der Liste
	if(head->len==0){
		entry->Next=NULL;
		entry->Prev=NULL;
		entry->Data=data;
		head->First=entry;
		head->Last=entry;
	}

	else{
		entry->Next=NULL;
		entry->Prev=head->Last;
		entry->Data=data;
		head->Last->Next=entry;
		head->Last=entry;
	}

	head->len++;
	return entry;
}

//Funktion Delete First
extern void *deleteFirst(SLIST_HEADER *head){

	//Liste leer, Abbruch
	if(!head){
		printf("Keine Liste vorhanden.\n");
		return NULL;
	}

	SLIST *entry;
	entry= head->First;

	//Laenge minimieren
	head->len--;

	//Pointer neu setzen
	head->First=entry->Next;
	entry->Next->Prev=NULL;

	//Speicher freigeben
	free(entry);
	return EXIT_SUCCESS;
}

//Funktion Delete Last
extern void *deleteLast(SLIST_HEADER *head){
	//Liste leer, Abbruch
	if(!head){
		printf("Keine Liste vorhanden.\n");
		return NULL;
	}

	SLIST *entry;
	entry= head->Last;

	//Laenge minimieren
	head->len--;

	//Pointer neu setzen
	head->Last=entry->Prev;
	entry->Prev->Next=NULL;

	//Speicher freigeben
	free(entry);

	return EXIT_SUCCESS;
}

//Funktion Print List
extern int pr_SList(SLIST_HEADER *head,FILE *file){

	//Filepointer auf Anfang setzen
	rewind(file);

	//Pruefen ob Liste vorhanden
	if(!head){
		fprintf(file,"Keine Liste vorhanden\n");
		return EXIT_FAILURE;
	}
	//Pruefen ob Liste leer
	if(head->len < 1){
		fprintf(file,"Liste ist leer\n");
		return EXIT_SUCCESS;
	}
	//Speicher reservieren
	SLIST *temp;
	temp=malloc(sizeof(SLIST));
	temp=head->First;
	int i=1;

	//Ausgabe in Textfile
	do {
		fprintf(file, "%d. Element der Liste: %d\n", i,temp->Data);
		temp=temp->Next;
		i++;
	}while(temp->Next !=NULL);

	//Letztes Element ausgeben
	fprintf(file, "%d. Element der Liste: %d\n", i,temp->Data);
	return EXIT_SUCCESS;
}

//Funktion Remove List
extern int rm_SList(SLIST_HEADER *head){
	//Liste leer, Abbruch
	if(!head){
	printf("Keine Liste vorhanden.\n");
	return EXIT_FAILURE;
	}

	//Pointer auf erstes Element setzen
	SLIST *entry;
	entry=head->First;
	int i=head->len;

	//Elemente loeschen
	for(i=0;i>head->len;i--){
		SLIST *temp;

		//Pointer auf naechstes Element setzen
		temp=entry->Next;
		free(entry);
		entry=temp;
	}
	//Speicher fuer head freigeben
	free(head);
	return EXIT_SUCCESS;
}

//Funktion Wert des Eintrags ausgeben
extern int get_entrySList(SLIST_HEADER *head,int data){

	//Kein Element vorhanden
	if(head->len < 1){
		printf("Keine Elemente in der Liste!\n");
		return EXIT_FAILURE;
		}
	//Wert groesser als Laenge der Liste
	if (data>head->len){
		printf("Wert groesser als Laenge der Liste!\n");
		return EXIT_FAILURE;
	}


	int i=0;
	SLIST *entry;
	entry=head->First;
	//Wenn nur ein Element vorhanden ist
	if(head->len==1) {
		return (int)entry->Data;
	}

	//Liste durchlaufen
	else{
	for(i=0;i<=data;i++){
		entry=entry->Next;
	}
	return (int)entry->Data;
	}
}

//Funktionen LIFO - Stack

//POP - Loescht Element und gibt Wert aus
extern int pop (SLIST_HEADER *head){
	//Pruefen ob Liste vorhanden
	if(!head) return EXIT_FAILURE;
	//Kein Element vorhanden
	if(head->len < 1){
		printf("Keine Elemente in der Liste!\n");
		return EXIT_FAILURE;
	}

	//Wert aus Liste entfernen
	SLIST *entry;
	int i=0;
	entry= head->First;
	i=entry->Data;

	//Laenge minimieren
	head->len--;

	//Pointer neu setzen
	head->First=entry->Next;
	entry->Next->Prev=NULL;

	//Speicher freigeben
	free(entry);

	return i;
}

//Top - Erstes Element anzeigen, ohne es auszugeben
extern int top (SLIST_HEADER *head){
	//Pruefen ob Liste vorhanden
	if(!head) return EXIT_FAILURE;
	int i=0;
	i=head->First->Data;
	return i;
}

//Empty - Erfolgreich wenn leer
extern int empty (SLIST_HEADER *head){
	//Pruefen ob Liste vorhanden
	if(!head) return EXIT_FAILURE;
	if (head->Last==0) return EXIT_SUCCESS;
	else return EXIT_FAILURE;
}

//lenght - Gibt die Laenge der Queue aus
extern int lenght(SLIST_HEADER *head){
	//Pruefen ob Liste vorhanden
	if(!head) return EXIT_FAILURE;
	int i=0;
	i=head->len;
	return i;
}

//Funktionen FIFO

//get - Erstes Element ausgeben und loeschen
//Pruefen ob Liste vorhanden
extern int get(SLIST_HEADER *head){
	if(!head) return EXIT_FAILURE;
	//Kein Element vorhanden
	if(head->len < 1){
		printf("Keine Elemente in der Liste!\n");
		return EXIT_FAILURE;
	}

	//Wert aus Liste entfernen
	SLIST *entry;
	int i=0;
	entry= head->Last;
	i=entry->Data;

	//Laenge minimieren
	head->len--;

	//Pointer neu setzen
	head->Last=entry->Prev;
	entry->Prev->Next=NULL;

	//Speicher freigeben
	free(entry);

	return i;
}

//next - Abfragen des naechsten mit get gelieferten Elements
extern int next(SLIST_HEADER *head){
	if(!head) return EXIT_FAILURE;
	//Kein Element vorhanden
	if(head->len < 1){
		printf("Keine Elemente in der Liste!\n");
		return EXIT_FAILURE;
		}
	int i=0;
	i=head->Last->Data;

	return i;
}
