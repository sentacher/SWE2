/*
 * list.h
 *
 *  Created on: 14.03.2017
 *      Author: Stefan SWE2 - Uebung 1
 */

#ifndef LIST_H_
#define LIST_H_

//Struktur definieren
typedef struct SList{
	int Data;
	struct SList *Next;
	struct SList *Prev;
}SLIST;

typedef struct SList_Header{
	int len;
	SLIST *First;
	SLIST *Last;
}SLIST_HEADER;

//Prototyen der Funktionen
extern SLIST_HEADER *createSList();
extern SLIST *insertFirst(SLIST_HEADER *head,int data);
extern SLIST *insertLast(SLIST_HEADER *head,int data);
extern void *deleteFirst(SLIST_HEADER *head);
extern void *deleteLast(SLIST_HEADER *head);
extern int pr_SList(SLIST_HEADER *head,FILE *file);
extern int rm_SList(SLIST_HEADER *head);
extern int get_entrySList(SLIST_HEADER *head,int data);

//Funktionen LIFO (Stack)
#define push *insertFirst
extern int pop (SLIST_HEADER *head);
extern int top (SLIST_HEADER *head);
extern int empty (SLIST_HEADER *head);
extern int lenght(SLIST_HEADER *head);

//Funktionen Fifo (List)
//Definition fuer selbe Funktionen
#define put *insertFirst
#define last top
extern int get(SLIST_HEADER *head);
extern int next(SLIST_HEADER *head);

//Funktionen Deque (Double-ended queue)
#define insert_back *insertLast
#define remove_element_at_back get
#define insert_front *insertFirst
#define remove_element_at_front pop
#define examine_first_element top
#define examine_last_element next

#endif /* LIST_H_ */
