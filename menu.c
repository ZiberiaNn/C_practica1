#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void selectOption(item_t items[], int size){
    int continuar = 1;
    while(continuar==1){
        int option;
        printf("%s", "==============================================\n");
        printf("%s", "============== MENÚ DE OPCIONES ==============\n");
        printf("%s", "Ingrese el número correspondiente a la opción que desea ejecutar (1-7):\n* ");

        scanf("%d", &option);
        if(option==1){
            printf("%s","===== PUNTO 1. Número de personas por ciudad =====\n");
            printf("%s",printPeoplePerCity(items, size));
        }else if(option==2){
            printf("%s","===== PUNTO 2. Promedio de salarios por ciudad en un rango de edad =====\n");
            int ageMinimum;
            int ageMaximum;
            int cityAverageIncome;
            printf("Ingrese la edad minima: ");
            scanf("%d", &ageMinimum);
            printf("Ingrese la edad maxima: ");
            scanf("%d", &ageMaximum);
            printf("Ingrese el número correspondiente a la ciudad:\n0 = Dallas, 1 = New York City, 2 = Los Angeles, 3 = Mountain View, 4 = Boston, 5 = Washington D.C., 6 = San Diego, 7 = Austin.\n* ");
            scanf("%d",&cityAverageIncome);
            printf("%s",printAverageIncome(items, size, ageMinimum, ageMaximum, cityAverageIncome));
        }else if(option==3){
            printf("%s","===== PUNTO 3. Probabilidad de estar enfermo en un rango de edad =====\n");
            int ageMin;
            // Pide la edad minima y maxima por consola
            printf("Ingrese la edad minima: ");
            scanf("%d", &ageMin);
            printf("%s",printProbabilitySick(items, size, ageMin));
        }else if(option==4){
            int id;
            printf("%s", "====== PUNTO 4. Obtener elemento por ID ======\nIngrese el ID del elemento deseado:\n* ");
            scanf("%d", &id);
            char * resultGetById = getElementById(items, id);
            printf("%s",resultGetById);
            //Libera el bloque de memoria asignado con malloc dentro de la función getElementById
            free(resultGetById);
        }else if(option==5){ 
            printf("===== PUNTO 5. Ingresar elemento a la mitad de los datos (id = 75000) =====\n");
            char * resultInsertElement = insertElement(items, size, getElementFromInput(size));
            printf("%s",resultInsertElement);
            //Libera el bloque de memoria asignado con malloc dentro de la función resultInsertElement
            free(resultInsertElement);
        }else if(option==6){
            printf("%s","===== PUNTO 6. Número de personas por ciudad con cierta edad =====\n");
            int ageCity;
            // Pide la edad minima y maxima por consola
            printf("Ingrese la edad a buscar: ");
            scanf("%d", &ageCity);
            printf("%s",printPeoplePerCityWithAge(items, size, ageCity));
        }else if(option==7){
            printf("%s","===== PUNTO 7. Imprimir el resultado de cada opción en el archivo results.txt =====\n");
            printFileOut(items, size);
        }
        printf("%s", "Ingrese 1 para ejecutar otra opción. De lo contrario, ingrese 0.\n* ");
        scanf("%d", &continuar);
    }
}

