#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"

// Calculate the average income of the people in a city and with a certain age

// Contiene el promedio de ingresos de las personas en una ciudad
unsigned int averageIncome[9] = {0,0,0,0,0,0,0,0,0};

const char * printAverageIncome(item_t items[], int size){
    int ageMinimum;
    int ageMaximum;
    // Pide la edad minima y maxima por consola
    printf("Ingrese la edad minima: ");
    scanf("%d", &ageMinimum);
    printf("Ingrese la edad maxima: ");
    scanf("%d", &ageMaximum);

    // Valida que la edad del elemento se encuentra entre la edad minima y maxima
    // Y suma el ingreso de la persona a la ciudad correspondiente
    for(int i = 0; i<size-10; i++){
        if(items[i].age >= ageMinimum && items[i].age <= ageMaximum){
            averageIncome[items[i].city] += items[i].income;
        }
    }

    // Imprime en el documento

    static char averageIncomePerCity[] = "";
	char *str1;
	size_t nbytes1;

    for (int i = 0; i < 8; i++)
    {	  
        averageIncome[i] = averageIncome[i]/cityCount[i]; 
         
        nbytes1 = snprintf(NULL, 0, "Promedio de ingresos en %s", city_names[i]) + 1;
        str1 = malloc(nbytes1);
        snprintf(str1, nbytes1, "Promedio de ingresos en %s", city_names[i]);
        strcat(averageIncomePerCity, str1);

        nbytes1 = snprintf(NULL, 0,": %d.\n",averageIncome[i]) + 1;
        str1 = malloc(nbytes1);
        snprintf(str1, nbytes1,": %d.\n",averageIncome[i]);
        strcat(averageIncomePerCity, str1);
    }
    free(str1);
    return averageIncomePerCity;
}


