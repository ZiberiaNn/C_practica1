#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
            printAverageIncome(items, size);
        }else if(option==3){
            printf("%s","===== PUNTO 3. Probabilidad de estar enfermo en un rango de edad =====\n");
            printProbabilitySick(items, size);
        }else if(option==4){
            int id;
            printf("%s", "====== PUNTO 4. Obtener elemento por ID ======\nIngrese el ID del elemento deseado:\n* ");
            scanf("%d", &id);
            char * resultGetById = getElementById(items, id);
            printf("%s",resultGetById);
            free(resultGetById);
        }else if(option==5){ 
            printf("===== PUNTO 5. Ingresar elemento a la mitad de los datos (id = 75000) =====\n");
            char * resultInsertElement = insertElement(items, size);
            printf("%s",resultInsertElement);
            free(resultInsertElement);
        }else if(option==6){
            printf("%s","===== PUNTO 6. Número de personas por ciudad con cierta edad =====\n");
            printPeoplePerCityWithAge(items, size);
        }else if(option==7){
            printFileOut(items, size);
        }
        printf("%s", "Ingrese 1 para ejecutar otra opción. De lo contrario, ingrese 0.\n* ");
        scanf("%d", &continuar);
    }
}