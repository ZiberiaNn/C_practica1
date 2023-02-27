#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "menu.h"
double executionTime(struct timeval inicio, struct timeval fin);

void selectOption(item_t items[], int size, struct Node_Item *head)
{
    int continuar = 1;
    struct timeval inicio, fin;
    while (continuar == 1)
    {
        int option;
        printf("%s", "==============================================\n");
        printf("%s", "============== MENÚ DE OPCIONES ==============\n");
        printf("%s", "Ingrese el número correspondiente a la opción que desea ejecutar (1-7):\n");
        printf("%s", "1. Número de personas por ciudad.\n");
        printf("%s", "2. Promedio de salarios por ciudad en un rango de edad.\n");
        printf("%s", "3. Probabilidad de estar enfermo en un rango de edad.\n");
        printf("%s", "4. Obtener elemento por ID.\n");
        printf("%s", "5. Ingresar elemento a la mitad de los datos (id = 75000).\n");
        printf("%s", "6. Número de personas por ciudad con cierta edad.\n");
        printf("%s", "7. Ejecutar todos los métodos e imprimir en un archivo\n");
        printf("%s", "0. Salir\n");
        printf("%s", "==============================================\n*");
        scanf("%d", &option);
        if (option == 1)
        {
            printf("%s", "===== PUNTO 1. Número de personas por ciudad =====\n");

            printf("%s", "Resultado por array:\n");
            gettimeofday(&inicio, 0);
            printf("%s", printPeoplePerCity(items, size));
            gettimeofday(&fin, 0);
            printf("Tiempo de ejecución: %f \n", executionTime(inicio, fin));

            printf("%s", "Resultado por Lista ligada:\n");
            gettimeofday(&inicio, 0);
            printf("%s", quantityByCity(head));
            gettimeofday(&fin, 0);
            printf("Tiempo de ejecución: %f\n", executionTime(inicio, fin));
        }
        else if (option == 2)
        {
            printf("%s", "===== PUNTO 2. Promedio de salarios por ciudad en un rango de edad =====\n");
            int ageMinimum;
            int ageMaximum;
            int cityAverageIncome;
            printf("Ingrese la edad minima: ");
            scanf("%d", &ageMinimum);
            printf("Ingrese la edad maxima: ");
            scanf("%d", &ageMaximum);
            printf("Ingrese el número correspondiente a la ciudad:\n0 = Dallas, 1 = New York City, 2 = Los Angeles, 3 = Mountain View, 4 = Boston, 5 = Washington D.C., 6 = San Diego, 7 = Austin.\n* ");
            scanf("%d", &cityAverageIncome);

            printf("%s", "Resultado por array:\n");
            gettimeofday(&inicio, 0);
            printf("%s", printAverageIncome(items, size, ageMinimum, ageMaximum, cityAverageIncome));
            gettimeofday(&fin, 0);
            printf("Tiempo de ejecución: %f\n", executionTime(inicio, fin));

            printf("%s", "Resultado por lista ligada:\n");
            gettimeofday(&inicio, 0);
            printf("%s", incomeCity(head, cityAverageIncome, ageMinimum, ageMaximum));
            gettimeofday(&fin, 0);
            printf("Tiempo de ejecución: %f\n", executionTime(inicio, fin));
        }
        else if (option == 3)
        {
            printf("%s", "===== PUNTO 3. Probabilidad de estar enfermo en un rango de edad =====\n");
            int ageMin;
            // Pide la edad minima y maxima por consola
            printf("Ingrese la edad minima: ");
            scanf("%d", &ageMin);

            printf("%s", "Resultado por array:\n");
            gettimeofday(&inicio, 0);
            printf("%s", printProbabilitySick(items, size, ageMin));
            gettimeofday(&fin, 0);
            printf("Tiempo de ejecución: %f\n", executionTime(inicio, fin));

            printf("%s", "Resultado por lista ligada:\n");
            gettimeofday(&inicio, 0);
            printf("%s", probability_disease(ageMin, head));
            gettimeofday(&fin, 0);
            printf("Tiempo de ejecución: %f\n", executionTime(inicio, fin));
        }
        else if (option == 4)
        {
            int id;
            printf("%s", "====== PUNTO 4. Obtener elemento por ID ======\nIngrese el ID del elemento deseado:\n* ");
            scanf("%d", &id);

            printf("%s", "Resultado por array:\n");
            gettimeofday(&inicio, 0);
            char *resultGetById = getElementById(items[id - 1]);
            printf("%s", resultGetById);
            gettimeofday(&fin, 0);
            // Libera el bloque de memoria asignado con malloc dentro de la función getElementById
            free(resultGetById);
            printf("Tiempo de ejecución: %f\n", executionTime(inicio, fin));

            printf("%s", "Resultado por lista ligada:\n");
            gettimeofday(&inicio, 0);
            printf("%s", search_by_id(head, id));
            gettimeofday(&fin, 0);
            printf("Tiempo de ejecución: %f\n", executionTime(inicio, fin));
        }
        else if (option == 5)
        {
            printf("===== PUNTO 5. Ingresar elemento a la mitad de los datos (id = 75000) =====\n");
            item_t elemento = getElementFromInput(size);

            printf("%s", "Resultado por array:\n");
            gettimeofday(&inicio, 0);
            char *resultInsertElement = insertElement(items, size, elemento);
            printf("%s", resultInsertElement);
            gettimeofday(&fin, 0);
            // Libera el bloque de memoria asignado con malloc dentro de la función resultInsertElement
            free(resultInsertElement);
            printf("Tiempo de ejecución: %f\n", executionTime(inicio, fin));

            printf("%s", "Resultado por lista ligada:\n");
            gettimeofday(&inicio, 0);
            insert_middle(head, elemento);
            gettimeofday(&fin, 0);
            printf("Tiempo de ejecución: %f\n", executionTime(inicio, fin));
        }
        else if (option == 6)
        {
            printf("%s", "===== PUNTO 6. Número de personas por ciudad con cierta edad =====\n");
            int ageCity;
            // Pide la edad minima y maxima por consola
            printf("Ingrese la edad a buscar: ");
            scanf("%d", &ageCity);

            printf("%s", "Resultado por array:\n");
            gettimeofday(&inicio, 0);
            printf("%s", printPeoplePerCityWithAge(items, size, ageCity));
            gettimeofday(&fin, 0);
            printf("Tiempo de ejecución: %f\n", executionTime(inicio, fin));

            printf("%s", "Resultado por lista ligada:\n");
            gettimeofday(&inicio, 0);
            printf("%s", ageByCity(head, ageCity));
            gettimeofday(&fin, 0);
            printf("Tiempo de ejecución: %f\n", executionTime(inicio, fin));
        }
        else if (option == 7)
        {
            printf("%s", "===== PUNTO 7. Imprimir el resultado de cada opción en los archivos de salida =====\n");
            // Imprime punto 2
            printf("===== PUNTO 2. Promedio de salarios por ciudad en un rango de edad =====\n");
            int ageMinimum;
            int ageMaximum;
            int cityAverageIncome;
            printf("Ingrese la edad minima: ");
            scanf("%d", &ageMinimum);
            printf("Ingrese la edad maxima: ");
            scanf("%d", &ageMaximum);
            printf("Ingrese el número correspondiente a la ciudad:\n0 = Dallas, 1 = New York City, 2 = Los Angeles, 3 = Mountain View, 4 = Boston, 5 = Washington D.C., 6 = San Diego, 7 = Austin.\n* ");
            scanf("%d", &cityAverageIncome);

            // Imprime punto 3
            printf("%s", "===== PUNTO 3. Probabilidad de estar enfermo en un rango de edad =====\n");
            int ageMin;
            // Pide la edad minima y maxima por consola
            printf("Ingrese la edad minima: ");
            scanf("%d", &ageMin);

            // Imprime punto 4
            int id;
            printf("====== PUNTO 4. Obtener elemento por ID ======\nIngrese el ID del elemento deseado:\n* ");
            scanf("%d", &id);

            // Imprime punto 5
            printf("===== PUNTO 5. Ingresar elemento a la mitad de los datos (id = 75000) =====\n");
            item_t elemento = getElementFromInput(size);

            // Imprime punto 6
            printf("%s", "===== PUNTO 6. Número de personas por ciudad con cierta edad =====\n");
            int ageCity;
            // Pide la edad minima y maxima por consola
            printf("Ingrese la edad a buscar: ");
            scanf("%d", &ageCity);

            printf("%s", "Resultado por array:\n");
            gettimeofday(&inicio, 0);
            printFileOut(items, size, ageMinimum, ageMaximum, cityAverageIncome, ageMin, id, ageCity, elemento);
            gettimeofday(&fin, 0);
            printf("Tiempo de ejecución: %f\n", executionTime(inicio, fin));
        }
        printf("%s", "Ingrese 1 para ejecutar otra opción. De lo contrario, ingrese 0.\n* ");
        scanf("%d", &continuar);
    }
}

double executionTime(struct timeval inicio, struct timeval fin)
{
    return ((double)(fin.tv_usec - inicio.tv_usec) / 1000000 + (double)(fin.tv_sec - inicio.tv_sec));
}