/*
 * tree.h
 *
 *  Created on: 16.04.2017
 *      Author: Stefan
 */

#ifndef TREE_H_
#define TREE_H_

typedef struct node{
	int data;
	//Pointer auf den linken Teilbaum
	struct node *left;
	//Pointer auf den rechten Teilbaum
	struct node *right;
}NODE;

//Prototypen der Funktionen

//Insert
NODE *insert (NODE *elem,int zahl);

//Traversieren
//Inorder
int trav_inorder(NODE *elem);

//Postorder
int trav_postorder(NODE *elem);

//PREORDER
int trav_preorder(NODE *elem);

//Search
NODE *search(NODE *elem,int zahl);

#endif /* TREE_H_ */
