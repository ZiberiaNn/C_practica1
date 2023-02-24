#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"
#include "peoplePerCity.h"

// Calculate the average income of the people in a city and with a certain age

// Contiene el promedio de ingresos de las personas en una ciudad
unsigned int averageIncome[9] = {0,0,0,0,0,0,0,0,0};

const char * printAverageIncome(item_t items[], int size){
    memset(averageIncome, 0, sizeof(averageIncome));
    int ageMinimum;
    int ageMaximum;
    // Pide la edad minima y maxima por consola
    printf("Ingrese la edad minima: ");
    scanf("%d", &ageMinimum);
    printf("Ingrese la edad maxima: ");
    scanf("%d", &ageMaximum);

    // Valida que la edad del elemento se encuentra entre la edad minima y maxima
    // Y suma el ingreso de la persona a la ciudad correspondiente
    for(int i = 0; i<size; i++){
        if(items[i].age >= ageMinimum && items[i].age <= ageMaximum){
            averageIncome[items[i].city] += items[i].income;
        }
    }

    // Imprime en el documento

    static char averageIncomePerCity[] = "";

	//char *str1;
	//size_t nbytes1;

    //Toca llamar a este loco para que se actualice el arreglo de cityCount
    addPeoplePerCity(items, size);
    char str[250];

    for (int i = 0; i < 9; i++)
    {	  
        if(cityCount[i] == 0){
            snprintf(str, sizeof(str), "No hay personas en %s en el rango de edad ingresado.\n", city_names[i]);
            strcat(averageIncomePerCity, str);
            continue;
        }
        averageIncome[i] = averageIncome[i]/cityCount[i]; 
        snprintf(str, sizeof(str), "Promedio de ingresos en %s: %d.\n", city_names[i], averageIncome[i]);
        strcat(averageIncomePerCity, str);
    }
    return averageIncomePerCity;
}