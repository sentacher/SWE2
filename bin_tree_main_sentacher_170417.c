/*
 ============================================================================
 Name        : bin_tree.c
 Author      : Stefan Entacher
 Version     :
 Copyright   : 
 Description : Binaerer Suchbaum
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"
#define ELEM 10


int main(void) {
	//Begruessungstext
	printf("Erstellt einen binaeren Suchbaum, fuellt diesen mit Zufallszahlen und traversiert ihn  anschliessend.\n");
	printf("Zusaetzlich kann ene Zahl im Baum gesucht werden.\n");
	printf("Weiter mit ENTER...\n");
	fflush(stdout);
	getchar();

	//Variablen initialisieren
	int i=0;
	time_t t;
	time(&t);

	//Structur Baum erstellen
	NODE *root =NULL;

	//Baum mit Zufallszahlen fuellen
	//Zufallsgenerator initialisieren
	srand((signed int)t);

	//Elemente erzeugen und einordnen
	for(i=0;i<ELEM;i++){
		root=insert(root,rand()%10+1);
		printf("%d. Element in den Baum eingeordnet.\n",i+1);
	}
	getchar();

	//Inorder Traversieren
	printf("Baum inorder traversiert:\n");
	trav_inorder(root);
	printf("\n=======================================================\n");
	getchar();

	//Preorder Traversieren
	printf("Baum preorder traversiert:\n");
	trav_preorder(root);
	printf("\n=======================================================\n");
	getchar();

	//Postorder Traversieren
	printf("Baum postorder traversiert:\n");
	trav_postorder(root);
	printf("\n=======================================================\n");
	getchar();

	//Element suchen
	printf("Bitte geben Sie eine Zahl ein, die im Baum gesucht werden soll: ");
	fflush(stdout);
	scanf("%d",&i);
	fflush(stdin);
	search(root,i);

	printf("\nProgramm wird beendet.\n");
	return EXIT_SUCCESS;
}
