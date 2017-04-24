/*
 ============================================================================
 Name        : SList.c
 Author      : Stefan Entacher
 Version     :
 Copyright   :
 Description : Doppelt verketete Liste -> rekursive Ausgabe
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Funktion Print List rekursiv
extern int pr_rek_SList(SLIST_HEADER *head,FILE *file){

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

	//Ausgabe in Textfile rekursiv
	fprintf(file, ":%d\n", temp->Data);
	//Abbruch wenn NULL
	if (temp->Next==NULL) return EXIT_SUCCESS;
	SLIST_HEADER *new_head = head;
	new_head->First = head->First->Next;
	pr_rek_SList(new_head, file);
	return EXIT_SUCCESS;
}