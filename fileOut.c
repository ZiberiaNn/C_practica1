#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFileOut(item_t items[], int size){
    FILE *fileOut;
	//Imprime el archivo de salida
    //Imprime punto 1
	fileOut = fopen("results.txt","w");
	fprintf(fileOut,"%s",printPeoplePerCity(items, size));

    //Imprime punto 2
    //fprintf(fileOut,"%s","===== PUNTO 2. Promedio de salarios por ciudad en un rango de edad =====\n");
    //fprint(fileOut,"%s",printAverageIncome(items, size));

    //Imprime punto 3
    //fprintf(fileOut,"%s","===== PUNTO 3. Probabilidad de estar enfermo en un rango de edad =====\n");
    //fprint(fileOut,"%s",printProbabilitySick(items, size));
    
    //Imprime punto 4
    int id;
    printf("%s", "====== PUNTO 4. Obtener elemento por ID ======\nIngrese el ID del elemento deseado:\n* ");
    scanf("%d", &id);
    char * resultGetById = getElementById(items, id);
    fprintf(fileOut,"%s",resultGetById);
    free(resultGetById);

    //Imprime punto 5
    printf("===== PUNTO 5. Ingresar elemento a la mitad de los datos (id = 75000) =====\n");
    char * resultInsertElement = insertElement(items, size);
    fprintf(fileOut,"%s",resultInsertElement);
    free(resultInsertElement);

    //Imprime punto 6
    //fprintf(fileOut,"%s","===== PUNTO 6. Número de personas por ciudad con cierta edad =====\n");
    //fprint(fileOut,"%s",printPeoplePerCityWithAge(items, size));

    fclose(fileOut);
}
