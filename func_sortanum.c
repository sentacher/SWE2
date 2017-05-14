/*
 * func_sortanum.c
 *
 *  Created on: 25.04.2017
 *      Author: Stefan
 */


//Bibliotheken inkludieren
#include <stdio.h>
#include <stdlib.h>

int help(){
	printf("\n===============================================\n"
	"MANUAL - SORTANUM\n"
	"Liest Zahlen ueber die CLI ein und sortiert diese.\n"
	"Syntax: sortanum.exe [Wert 1] [Wert 2] [Wert n]\n"
	"Wird kein Parameter eingegeben, so wird der Hilfstext aufgerufen.\n"
	"===============================================\n\n");
	return EXIT_SUCCESS;
}

//Fuer qsort
int cmpfunc (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}
