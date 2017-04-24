/*
 * tree_func.c
 *
 *  Created on: 16.04.2017
 *      Author: Stefan
 */

//Funktionen Binaerbaum

//Bibliotheken importieren
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

//Insert
NODE *insert(NODE *elem, int data){

	//Root-Zeiger auf NULL
	if (elem==NULL){
		elem=malloc(sizeof(NODE));
		if (elem==NULL){
			printf("Fehler beim Allokieren des Speichers.\n");
			return NULL;
		}
		else{
			elem->data=data;
			elem->left=elem->right=NULL;
		}
	}

	else{
		//Daten links einfuegen, Wert kleiner bzw. gleich gross
		if(data<=elem->data) elem->left = insert(elem->left,data);
		//Daten rechts einfuegen, Wert greosser
		else elem->right=insert(elem->right,data);
	}
	return elem;
}


//Traversieren
//Inorder
int trav_inorder(NODE *elem){
	//Root-Zeiger auf NULL
	if (elem==NULL){
		return EXIT_SUCCESS;;
	}

	else{
		trav_inorder(elem->left);
		printf("%d -> ",elem->data);
		trav_inorder(elem->right);
	}

	return EXIT_SUCCESS;
}

//Preorder
int trav_preorder(NODE *elem){
	//Root-Zeiger auf NULL
	if (elem==NULL){
		return EXIT_SUCCESS;;
	}

	else{
		printf("%d -> ",elem->data);
		trav_preorder(elem->left);
		trav_preorder(elem->right);
	}

	return EXIT_SUCCESS;
}

//Postorder
int trav_postorder(NODE *elem){
	//Root-Zeiger auf NULL
	if (elem==NULL){
		return EXIT_SUCCESS;
	}

	else{
		trav_postorder(elem->left);
		trav_postorder(elem->right);
		printf("%d -> ",elem->data);
	}

	return EXIT_SUCCESS;
}

//Suchen
NODE *search(NODE *elem, int zahl){
	//Root-Zeiger auf NULL
	if(elem==NULL){
		printf("Kein Element im Baum vorhanden.\n");
		return NULL;
	}

	if(elem->data==zahl){
		printf("Zahl wurde im Baum gefunden.\n");
		return elem;
	}
	//Linken Teilbaum durchsuchen
	else if (elem->data >= zahl){
		//Rueckgabe Addresse fuer weitere Suche
		return search(elem->left,zahl);
	}
	//Rechten Teilbaum durchsuchen
	else {
		return search(elem->data,zahl);
	}
}
