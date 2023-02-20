#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"

// Calculate the average income of the people in a city and with a certain age

// Contiene el promedio de ingresos de las personas en una ciudad
unsigned int averageIncome[9] = {0,0,0,0,0,0,0,0,0};

// Guarda los elementos del formulario (Recibe máximo 200.000)
item_t averageElement[200000];

// Recibe el elemento y la linea del documento.
void saveAverageElement(item_t element, unsigned int line_number){
    averageElement[line_number] = element;
}

const char * printAverageIncome(){
    char arr[9][20] = {"Dallas", "New York City", "Los Angeles", "Mountain View", "Boston","Washington D.C.", "San Diego", "Austin", "Not found"};
    int ageMinimum;
    int ageMaximum;

    // Pide la edad minima y maxima por consola
    printf("Ingrese la edad minima: ");
    scanf("%d", &ageMinimum);
    printf("Ingrese la edad maxima: ");
    scanf("%d", &ageMaximum);

    // Valida que la edad del elemento se encuentra entre la edad minima y maxima
    // Y suma el ingreso de la persona a la ciudad correspondiente
    for(int i = 0; i<200000; i++){
        if(averageElement[i].age >= ageMinimum && averageElement[i].age <= ageMaximum){
            averageIncome[averageElement[i].city] += averageElement[i].income;
        }
    }
    static char averageIncomePerCity[200000];
    char str1[200000], str2[200000];
    for (int i = 0; i < 9; i++)
    {	        
        // Saca el promedio de ingresos de la ciudad
        averageIncome[i] = averageIncome[i]/cityCount[i];
        // Imprime el promedio de ingresos de la ciudad
        sprintf(str1,"Promedio de ingresos en %s", arr[i]);
        sprintf(str2,": %d.\n",averageIncome[i]);
        strcat(averageIncomePerCity, str1);
        strcat(averageIncomePerCity, str2);
    }	
    return averageIncomePerCity;
}


