/*
 * ini_head.h
 *
 *  Created on: 21.05.2017
 *      Author: Stefan
 */

#ifndef INI_HEAD_H_
#define INI_HEAD_H_

//Struktur definieren
typedef struct ini_elem{
	char *val;
	char *key;
	struct SList *Next;
}INI_ELEM;

typedef struct ini_head{
	int len;
	INI_ELEM *First;
}INI_HEADER;

//Prototypen der Funktionen
int linecount(FILE *file);
extern int printini(INI_HEADER *head);
extern INI_ELEM *insert(INI_HEADER *head,char *val, char *key);
extern INI_HEADER *createList();

#endif /* INI_HEAD_H_ */
