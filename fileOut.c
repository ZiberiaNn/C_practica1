#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileOut.h"

void printFileOut(item_t items[], int size, int ageMinimum, int ageMaximum, int cityAverageIncome, int ageMin, int id, int ageCity, item_t element){
    FILE *fileOut;
    fileOut = fopen("arrayResults.txt","w");

	//Imprime el archivo de salida
	fprintf(fileOut,"%s",printPeoplePerCity(items, size));

    fprintf(fileOut,"%s",printAverageIncome(items, size, ageMinimum, ageMaximum, cityAverageIncome));

    fprintf(fileOut,"%s",printProbabilitySick(items, size ,ageMin));
    
    char * resultGetById = getElementById(items[id-1]);
    fprintf(fileOut,"%s",resultGetById);
    //Libera el bloque de memoria asignado con malloc dentro de la función resultGetById
    free(resultGetById);

    char * resultInsertElement = insertElement(items, size, element);
    fprintf(fileOut,"%s",resultInsertElement);
    //Libera el bloque de memoria asignado con malloc dentro de la función resultInsertElement
    free(resultInsertElement);

    fprintf(fileOut,"%s",printPeoplePerCityWithAge(items, size ,ageCity));

    fclose(fileOut);
}
