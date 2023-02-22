#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFileOut(item_t items[], int size){
    FILE *fileOut;
	//Imprime el archivo de salida
    //Imprime punto 1
	fileOut = fopen("results.txt","w");
	fprintf(fileOut,"%s",printPeoplePerCity(items, size));
    
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

    fclose(fileOut);
}
