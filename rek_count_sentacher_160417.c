/*
 ============================================================================
 Name        : rek_count.c
 Author      : Stefan Entacher
 Version     :
 Copyright   : 
 Description : Gibt die Zahlen von 5 bis 10 rekursiv aus
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int rekcount(int zahl){
	if (zahl<=10){
		printf("%d\n",zahl);
		rekcount(zahl+1);
	}
	return EXIT_SUCCESS;
}

int main(void) {
	rekcount(5);
	return EXIT_SUCCESS;
}
