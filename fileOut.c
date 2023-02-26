#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileOut.h"

void printFileOut(item_t items[], int size){
    FILE *fileOut;
    fileOut = fopen("results.txt","w");

	//Imprime el archivo de salida
    //Imprime punto 1
	fprintf(fileOut,"%s",printPeoplePerCity(items, size));

    //Imprime punto 2
    printf("===== PUNTO 2. Promedio de salarios por ciudad en un rango de edad =====\n");
    fprintf(fileOut,"%s",printAverageIncome(items, size));

    //Imprime punto 3
    printf("%s","===== PUNTO 3. Probabilidad de estar enfermo en un rango de edad =====\n");
    fprintf(fileOut,"%s",printProbabilitySick(items, size));
    
    //Imprime punto 4
    int id;
    printf("====== PUNTO 4. Obtener elemento por ID ======\nIngrese el ID del elemento deseado:\n* ");
    scanf("%d", &id);
    char * resultGetById = getElementById(items, id);
    fprintf(fileOut,"%s",resultGetById);
    //Libera el bloque de memoria asignado con malloc dentro de la función resultGetById
    free(resultGetById);

    //Imprime punto 5
    printf("===== PUNTO 5. Ingresar elemento a la mitad de los datos (id = 75000) =====\n");
    char * resultInsertElement = insertElement(items, size, getElementFromInput(size));
    fprintf(fileOut,"%s",resultInsertElement);
    //Libera el bloque de memoria asignado con malloc dentro de la función resultInsertElement
    free(resultInsertElement);

    //Imprime punto 6
    printf("%s","===== PUNTO 6. Número de personas por ciudad con cierta edad =====\n");
    fprintf(fileOut,"%s",printPeoplePerCityWithAge(items, size));

    fclose(fileOut);
}
