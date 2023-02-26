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
    int ageMinimum;
    int ageMaximum;
    int cityAverageIncome;
    printf("Ingrese la edad minima: ");
    scanf("%d", &ageMinimum);
    printf("Ingrese la edad maxima: ");
    scanf("%d", &ageMaximum);
    printf("Ingrese el número correspondiente a la ciudad:\n0 = Dallas, 1 = New York City, 2 = Los Angeles, 3 = Mountain View, 4 = Boston, 5 = Washington D.C., 6 = San Diego, 7 = Austin.\n* ");
    scanf("%d",&cityAverageIncome);
    fprintf(fileOut,"%s",printAverageIncome(items, size, ageMinimum, ageMaximum, cityAverageIncome));

    //Imprime punto 3
    printf("%s","===== PUNTO 3. Probabilidad de estar enfermo en un rango de edad =====\n");
    int ageMin;
    // Pide la edad minima y maxima por consola
    printf("Ingrese la edad minima: ");
    scanf("%d", &ageMin);
    fprintf(fileOut,"%s",printProbabilitySick(items, size ,ageMin));
    
    //Imprime punto 4
    int id;
    printf("====== PUNTO 4. Obtener elemento por ID ======\nIngrese el ID del elemento deseado:\n* ");
    scanf("%d", &id);
    char * resultGetById = getElementById(items[id-1]);
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
    int ageCity;
    // Pide la edad minima y maxima por consola
    printf("Ingrese la edad a buscar: ");
    scanf("%d", &ageCity);
    fprintf(fileOut,"%s",printPeoplePerCityWithAge(items, size ,ageCity));

    fclose(fileOut);
}
