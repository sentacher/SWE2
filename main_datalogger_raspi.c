/*
 ============================================================================
 Name        : datalogger_sentacher.c
 Author      : Stefan Entacher
 Version     :
 Copyright   : 
 Description : Liest Wetterdaten von zamg und schreibt diese in ein Textfile
 ============================================================================
 */

 //Benoetigte Bibliotheken inkludieren
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 50

//Funktion help
void help(){
	printf("Aufruf: datalogger ORT\n"\
			"Option Beschreibung:\n"\
			"\t-h Hilfe\n"\
			"\tORT Gibt die Temperatur des angegebenen Orts in eine Textfile aus.\n"\
			"\tAuf Gross- und Kleinschreibung achten!\n"\
			"Aufrufbeispiel:\n"\
			"./datalogger salzburg\n\n");
}


int get_temperatur(char *ort, float *pTemp){
	FILE *datei;
	char name[MAX];

	datei=fopen("ogd","r");
	if(datei==NULL) {
		printf("Datei konnte nicht geoffnet werden!\n");
	return EXIT_FAILURE;
	}
	//Erste Zeile nicht relevant
	fscanf(datei,"%*[^\n]");
	
	//Bis EOF
	while (feof(datei) == 0){
	fscanf(datei,"%*i;\"%[^\"]\";%*i;\"%*[^\"]\";\"%*[^\"]\";%f%*[^\n]",name,pTemp);
	
	//Wenn Ort gefunden
	if(strcmp(name,ort)==0){
		printf("Wert fuer %s gefunden: %f\n",name,*pTemp);
		break;
	}
	}
	fclose(datei);
	return EXIT_SUCCESS;
}


int main(int argc, char *argv[]){
	
	//Wenn kein Argument oder -h
	if( argc==1 || strcmp(argv[1], "-h") == 0 )
	{
		help();
		return EXIT_SUCCESS;
	}
	
	//Wenn zu viele Argumente
	if (argc>2){
		printf("Zu viele Werte angegeben!\n");
		printf("Programm wird beendet.\n");
		return EXIT_FAILURE;
	}
	
	//Variablen definieren
	int ret=0;
	float temperatur=0;
	
	//Systembefehle Linux
	system("rm ogd");
	system("wget http://www.zamg.ac.at/ogd");
	
	//Zuweisung Ort mit argv[1]
	ret = get_temperatur(argv[1], &temperatur);
	
	//Daten in Ausgabefile schreiben
	FILE *fp;
	
	fp = fopen("templogger.txt", "a");
	if (NULL == fp){
		printf("Fehler beim Oeffnen der Datei!\n");
		return EXIT_FAILURE;
	}
	//Zuweisung Zeit
	time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char datetime[64];
    strftime(datetime, sizeof(datetime), "%c", tm);
	
	//Ausgabe Textfile
	fprintf(fp,"%s - Temperatur in %s = %f\n",datetime, argv[1],temperatur);
	fclose(fp);
	
	system("rm ogd");
	
	return EXIT_SUCCESS;
}	
