/*
 * ini_func.c
 *
 *  Created on: 21.05.2017
 *      Author: Stefan
 */

//Benoetigte Bibliotheken
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ini_head.h"

//Funktion SLIST_HEADER
extern INI_HEADER *createList(){

	//Speicher reservieren
	INI_HEADER *head;
	head=malloc(sizeof(INI_HEADER));
	if(!head) {
		printf ("Fehler beim allokieren des Speichers.\n");
		return NULL;
	}

	head->len=0;
	head->First = NULL;
	return head;
}

//Funktion Insert First
extern INI_ELEM *insert(INI_HEADER *head,char *val, char *key){

	//Speicher reservieren
	INI_ELEM *entry;
	entry=malloc(sizeof(INI_ELEM));
	if (!entry){
		printf ("Fehler beim allokieren des Speichers.\n");
		return NULL;
	}

	//Wenn erstes Element der Liste
	if(head->len==0){
		entry->Next=NULL;
		entry->val=val;
		entry->key=key;
		head->First=entry;
	}

	else{
		entry->Next=head->First;
		head->First=entry;
		entry->val=val;
		entry->key=key;

	}

	head->len++;
	return entry;
}

extern int printini(INI_HEADER *head){

	//Pruefen ob Liste vorhanden
	if(!head){
		printf("Keine Liste vorhanden\n");
		return EXIT_FAILURE;
	}
	//Pruefen ob Liste leer
	if(head->len < 1){
		printf("Liste ist leer\n");
		return EXIT_SUCCESS;
	}
	//Speicher reservieren
	INI_ELEM *temp;
	temp=malloc(sizeof(INI_ELEM));
	temp=head->First;
	int i=1;

	//Ausgabe in stdout
	do {
		printf("%d. value der Liste: %s\n",i,temp->val);
		printf("%d. key der Liste: %s\n", i,temp->key);
		temp=temp->Next;
		i++;
	}while(temp->Next !=NULL);

	//Letztes Element ausgeben
	printf("%d. value der Liste: %s\n",i,temp->val);
	printf("%d. key der Liste: %s\n", i,temp->key);
	return EXIT_SUCCESS;
}

int linecount(FILE *quelle){
	int i=1;
	char c;

	//Filezeiger auf Anfang
	rewind(quelle);

	while( (c = fgetc(quelle)) != EOF ){
		if(c == '\n')
			i++;
	}
	return i;
}
