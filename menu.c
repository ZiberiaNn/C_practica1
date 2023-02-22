#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void selectOption(item_t items[], int SIZE){
    int continuar = 1;
    while(continuar==1){
        int option;
        printf("%s", "==============================================\n");
        printf("%s", "============== MENÚ DE OPCIONES ==============\n");
        printf("%s", "Ingrese el número correspondiente a la opción que desea ejecutar (1-7):\n* ");

        scanf("%d", &option);
        if(option==1){
            printf("%s",printPeoplePerCity(items, SIZE));
        }else if(option==2){
            printf("%s","Pongan el punto 2 acá porfa");
        }else if(option==3){
            printf("%s","Pongan el punto 3 acá porfa");
        }else if(option==4){
            int id;
            printf("%s", "====== PUNTO 4. Obtener elemento por ID ======\nIngrese el ID del elemento deseado:\n* ");
            scanf("%d", &id);
            char * resultGetById = getElementById(items, id);
            printf("%s",resultGetById);
            free(resultGetById);
        }else if(option==5){ 
            char * resultInsertElement = insertElement(items, SIZE);
            printf("%s",resultInsertElement);
            free(resultInsertElement);
        }else if(option==6){
            printf("%s","Pongan el punto 2 acá porfa");
        }else if(option==7){
            printf("%s","Falta implementar bien el punto 7");
        }
        printf("%s", "Ingrese 1 para ejecutar otra opción. De lo contrario, ingrese 0.\n* ");
        scanf("%d", &continuar);
    }
}